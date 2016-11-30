/*
 * ServerSockets.cpp
 *
 *  Created on: 10 nov. 2016
 *      Author: gustavo, randy, fernanda, ricardo
 */

#include "ServerSockets.h"
#include "ControllerNode.h"
#include "Document.h"
#include "Collections.h"


vector<int> socketNode;
vector<string> dataVideo;

struct sockaddr_in cli_addr;
int socketClient;
string message;

Collections collections;


/**
 * otro codigo
 */
fd_set read_fds;
fd_set write_fds;

int i, max_sd, sd, activity;
int client_socket[MAXCONNECTIONS];

int fdMax;
int nbytes;
int selectSocket;
char buffer[1024];
time_t ticks;


ControllerNode controller;

/**
 * Constructor. Set up the connection for the Server.
 */
ServerSockets::ServerSockets() {
	int yes = 1;
	struct sockaddr_in serv_addr;
	socketServer = socket(AF_INET, SOCK_STREAM, 0);
	if (socketServer < 0){
		cout << "ERROR opening socket" << endl;
		exit(-1);
	}

	/**
	 * deberia funcionar sin esto,
	 * pero lo cambiamos para que tenga multiple conexion
	 */
	if (setsockopt(socketServer, SOL_SOCKET, SO_REUSEADDR, (char *)&yes, sizeof(yes)) < 0){
		cout << "ERROR set multiple connections" << endl;
		exit(-1);
	}


	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(serv_addr.sin_zero), 8);


	if (bind(socketServer, (struct sockaddr *)&serv_addr,
			  sizeof(struct sockaddr)) < 0){
		cout<<("ERROR on binding") << endl;
		exit(-1);
	}

	if (listen(socketServer, MAXCONNECTIONS) < 0){
		cout << "ERROR on listen" << endl;
		exit(-1);
	}

	struct ifreq ifr;
	ifr.ifr_addr.sa_family = AF_INET;
	/*
	 * "wlp10s0" in GQosmio
	 * command ifconfig
	 *
	 */
	strncpy(ifr.ifr_name, "enp11s0", IFNAMSIZ-1);
	ioctl(socketServer, SIOCGIFADDR, &ifr);
	cout << "Server IP: " << (inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr)) << endl;
	cout << "Server Port: " << (PORT) << endl;

	cliLen = sizeof(struct sockaddr);

	FD_ZERO(&read_fds);



}

/**
 * Destoyer.
 */
ServerSockets::~ServerSockets() {

}


/**
 * Starts the connection with the Client.
 */
void ServerSockets::run(){
	/*Loop for the conncetion.*/
	while(true){
		FD_ZERO(&read_fds);

		FD_SET(socketServer, &read_fds);
		struct sockaddr_in cli_addr;
		max_sd = socketServer;

		for(i = 0; i < MAXCONNECTIONS; i++){
			sd = client_socket[i];

			if (sd > 0){
				FD_SET(sd, &read_fds);
			}

			if (sd > max_sd){
				max_sd = sd;
			}
		}

		activity = select(max_sd + 1, &read_fds, NULL, NULL, NULL);


		if ((activity < 0) && (errno != EINTR)){
			cout << "ERROR on select" << endl;
		}

		if(FD_ISSET(socketServer, &read_fds)){

			if ((socketClient = accept(socketServer,(struct sockaddr *)&cli_addr, &cliLen)) < 0 ){
				cout << "ERROR on accept" << endl;
				exit(-1);
			}
			sendMSG(socketClient, "Conectado con el Server");

			for (i = 0; i < MAXCONNECTIONS; i++){
				if (client_socket[i] == 0){
					client_socket[i] = socketClient;
					printf("Adding to list of sockets as %d\n" , i);
					break;
				}
			}
		}

		for (i = 0; i < MAXCONNECTIONS; i++){
			sd = client_socket[i];
			if (FD_ISSET(sd, &read_fds)){
				string message = receiveMSG(sd);
				if (message == ""){
					 getpeername(sd , (struct sockaddr*)&cli_addr ,
						(socklen_t*)&cli_addr);
					printf("Host disconnected , ip %s , port %d \n" ,
						  inet_ntoa(cli_addr.sin_addr) , ntohs(cli_addr.sin_port));
					//Close the socket and mark as 0 in list for reuse
					close( sd );
					client_socket[i] = 0;
				}
				else{
					if (message == "DiskNode"){
						socketNode.push_back(sd);
						//sendMSG(sd, "Agregado como Node");
					}
					if (message == "OMP"){
						sendMSG(sd, "Bienvenido Odissey MP");
					}
					if (message == "UploadFile"){
						cout << "Recibir archivo desde OMP\n";
						string message1 = receiveMSG(sd);

						int bytesVideo = message1.length();
						string name = receiveMSG(sd);
						string lengthms = receiveMSG(sd);
						string description = receiveMSG(sd);
						string owner = receiveMSG(sd);
						string title = receiveMSG(sd);
						string date = receiveMSG(sd);

						Document document = Document(name, bytesVideo, lengthms, description,
								 owner, title, date);
						collections.addDocument(document);

//						while (message1.length()%3 !=0){
//							message1+="0";
//						}
//
//						int lengCut = (message1.length()) / 3;
//						while(message1 != ""){
//							string cut = message1.substr(0, lengCut);
//							dataVideo.push_back(cut);
//							message1 = message1.substr(lengCut, message1.length() -1);
//						}
//						string A1 = dataVideo.operator [](0);
//						string A2 = dataVideo.operator [](1);
//						string A3 = dataVideo.operator [](2);
//						string Ap = controller.parityMgmt(A1, A2, A3);
//						cout << "save parity Ap" << endl;
//
//						cout << "cantidad de nodos: " << (int)socketNode.size() << endl;
//
//						cout << "largo de A1: " << A1.length() << endl;
//						sendMSG(socketNode.operator [](0), "SaveData");
//						sendMSG(socketNode.operator [](0), A1);
//
//						cout << "largo de A2: " << A2.length() << endl;
//						sendMSG(socketNode.operator [](1), "SaveData");
//						sendMSG(socketNode.operator [](1), A2);
//
//						cout << "largo de A3: " << A3.length() << endl;
//						sendMSG(socketNode.operator [](2), "SaveData");
//						sendMSG(socketNode.operator [](2), A3);
//
//						cout << "largo de Ap: " << Ap.length() << endl;
//						sendMSG(socketNode.operator [](3), "SaveParity");
//						sendMSG(socketNode.operator [](3), Ap);

						cout << "complete receive data video\n";
					}
					if(message == "Complete Upload"){
						sendMSG(sd, "Upload your file!!");
					}
					if(message == "Streaming"){
						string parameter = receiveMSG(sd);

						if(collections.searchDocument(parameter)){
							cout << "si hemos encontrado el video" << endl;
							int sizeVideo = collections.getDocument().getSize();

//							sendMSG(socketNode.operator [](0), "SendData");
//							string A1 = receiveMSG(socketNode.operator [](0));
//
//							sendMSG(socketNode.operator [](1), "SendData");
//							string A2 = receiveMSG(socketNode.operator [](1));
//
//							sendMSG(socketNode.operator [](2), "SendData");
//							string A3 = receiveMSG(socketNode.operator [](2));
//
//							sendMSG(socketNode.operator [](3), "Send Parity");
//							string Ap = receiveMSG(socketNode.operator [](3));
//
//							if (A1 == ""){
//								cout << "se borro A1\n";
//								A1 = controller.parityMgmt(A2, A3, Ap);
//								cout << "largo de A1 paridad: "  << A1.length() << endl;
//							}
//							if (A2 == ""){
//								cout << "se borro A2\n";
//								A2 = controller.parityMgmt(A1, A3, Ap);
//								cout << "largo de A2 paridad: "  << A2.length() << endl;
//							}
//							if (A3 == ""){
//								cout << "se borro A3\n";
//								A3 = controller.parityMgmt(A1, A2, Ap);
//								cout << "largo de A3 paridad: "  << A3.length() << endl;
//							}
//							cout << "se creo la paridad\n";
//							string data = A1 + A2 + A3;
//							data = data.substr(0, sizeVideo);
//							cout << "largo de data binaria: " << data.length() << endl;
//							sendMSG(sd, data);

						}
						else{
							cout << "No se ha encontrado el vide" << endl;
						}
					}
					if(message == "Edit"){
						string parameter = receiveMSG(sd);

						if(collections.searchDocument(parameter)){
							cout << "Editar metadata" << endl;
							string name = collections.getDocument().getName();
							string duration = collections.getDocument().getLength();
							string description = collections.getDocument().getDescription();
							string date = collections.getDocument().getDate();
							string title = collections.getDocument().getTitle();

							sendMSG(sd, name);
							sleep(1);
							 cout << "Envio el primer parametro" << endl;
							sendMSG(sd, duration);
							sleep(1);
							sendMSG(sd, description);
							sleep(1);
							sendMSG(sd, date);
							sleep(1);
							sendMSG(sd, title);
							sleep(1);
							cout << "Envio todos los parametros" << endl;

							string message = receiveMSG(sd);
							if(message == "UploadEdit"){
								string nameEdit = receiveMSG(sd);
								string durationEdit = receiveMSG(sd);
								string descriptionEdit = receiveMSG(sd);
								string dateEdit = receiveMSG(sd);
								string titleEdit = receiveMSG(sd);
								/*
								 * Set Document
								 */
								collections.getDocument().setDate(dateEdit);
								collections.getDocument().setDescription(descriptionEdit);
								collections.getDocument().setLength(durationEdit);
								collections.getDocument().setName(nameEdit);
								collections.getDocument().setTitle(titleEdit);

								cout << collections.getDocument().getName() << endl;

							}

						}
						else{
							cout << "No se ha encontrado el vide" << endl;
						}
					}
				}
			}
		}
	}
}

/**
 * Send messages to the client.
 *
 * @param socketClient, message string
 */
void ServerSockets::sendMSG(int socketClient, string message){
	int lengthMSG = message.length();
	const char *buffer = new char[lengthMSG];
	buffer = message.c_str();
	int buffsize = (MAXDATA);
	setsockopt(socketClient, SOL_SOCKET, SO_SNDBUF, &buffsize, sizeof(buffsize));

	int s = send(socketClient, buffer, lengthMSG+1, MSG_OOB|MSG_PEEK);
	if (s < 0){
		cout << "ERROR on send message to client" << endl;
	}
}


string ServerSockets::receiveMSG(int socketClient){
	char *buffer = new char[MAXDATA];
	int buffsize = (MAXDATA);
	setsockopt(socketClient, SOL_SOCKET, SO_RCVBUF, &buffsize, sizeof(buffsize));
	int r;
	string message;
	r = recv(socketClient, buffer, MAXDATA, MSG_WAITALL|MSG_CTRUNC);
	if(r > 0){
		message = buffer;
		cout << "bytes leido server: " << r << endl;
	}
	if (r < 0){
		cout << "ERROR on receive message from client" << endl;
		return "";
	}
	return message;
	delete[] buffer;
}
