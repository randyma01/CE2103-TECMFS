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


/**
 * Extra code, variables for connections.
 */
vector<int> socketNode;
vector<string> dataVideo;

struct sockaddr_in cli_addr;
int socketClient;
string message;

Collections collections; /*Object Collections, for keeping register of all the video's Document uploaded.*/
ControllerNode controller; /*Object ControllerNode, for managing the data at the RAID5 Disks Nodes.*/

fd_set read_fds;
fd_set write_fds;

int i, max_sd, sd, activity;
int client_socket[MAXCONNECTIONS];

int fdMax;
int nbytes;
int selectSocket;
char buffer[1024];
time_t ticks;
/***************************************/

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
	strncpy(ifr.ifr_name, "wlp10s0", IFNAMSIZ-1); /*Second parameter must be change on the computer to use: get form "ifoconfig" Linux Bash at Terminal.*/
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
					/*If the message receive is "DiskNode" the client is detected and manage as a Disk Node.*/
					if (message == "DiskNode"){
						socketNode.push_back(sd);
						//sendMSG(sd, "Agregado como Node");
					}
					/*If the message is "OMP" the client is detected as the Odyssey Media Player.*/
					if (message == "OMP"){
						sendMSG(sd, "Bienvenido Odissey MP");
					}
					/*If the message is "UpaloadFile", the Odyssey Media Player ask to save a video.*/
					if (message == "UploadFile"){
						cout << "Recibir archivo desde OMP\n";

						string message1 = receiveMSG(sd); /*Binary data file of the video.*/

						int bytesVideo = message1.length(); /*Length of the binary data.*/

						string name = receiveMSG(sd); /*Name of the Video.*/

						Document document = Document(name, bytesVideo); /*A new document is created to save the video register; with name and size.*/

						collections.addDocument(document); /*This new Document is saved into the collections to keep regiter of all the videos..*/

						/*iI the binary data is not divisble bewteen three, 0's are added to the string of data.*/
						while (message1.length()%3 !=0){
							message1+="0";
						}

						int lengCut = (message1.length()) / 3; /*Sets the length to be divided by three.*/
						while(message1 != ""){
							string cut = message1.substr(0, lengCut); /*Cuts the string, into three parts.*/
							dataVideo.push_back(cut); /*Keeps all three parts into a vector of all the data.*/
							message1 = message1.substr(lengCut, message1.length() -1); /*Gets the parity from the three parts.*/
						}
						/*Divides the data file into four parrts, the last one is the parity.*/
						string A1 = dataVideo.operator [](0); /*Identify the first part as A1.*/
						string A2 = dataVideo.operator [](1); /*Identify the first part as A2.*/
						string A3 = dataVideo.operator [](2); /*Identify the first part as A3.*/
						string Ap = controller.parityMgmt(A1, A2, A3); /*Identify the first part as Ap.*/
						cout << "save parity Ap" << endl;

						cout << "cantidad de nodos: " << (int)socketNode.size() << endl;

						/*Sends all four parts to the Disk Nodes to be saved. All three first parts are send as generic data. The Parity is saved apart.*/
						cout << "largo de A1: " << A1.length() << endl;
						sendMSG(socketNode.operator [](0), "SaveData");
						sendMSG(socketNode.operator [](0), A1);

						cout << "largo de A2: " << A2.length() << endl;
						sendMSG(socketNode.operator [](1), "SaveData");
						sendMSG(socketNode.operator [](1), A2);

						cout << "largo de A3: " << A3.length() << endl;
						sendMSG(socketNode.operator [](2), "SaveData");
						sendMSG(socketNode.operator [](2), A3);

						cout << "largo de Ap: " << Ap.length() << endl;
						sendMSG(socketNode.operator [](3), "SaveParity");
						sendMSG(socketNode.operator [](3), Ap);

						cout << "complete receive data video\n";
					}

					/*if the messages from the Odyssey Media Player is "Complete Upload", this Server answer back with "Upload your file.".*/
					if(message == "Complete Upload"){
						sendMSG(sd, "Upload your file!!");
					}
					/*If the message is "Streaming" the Odyssey Media Player is asking for the reproduce of a video..*/
					if(message == "Streaming"){
						string nameVideo = receiveMSG(sd); /*Odyssey Media Player must send the name of the video for the previous search.*/

						/*Makes the search: Linear Search from all the Documents at the Collection's vector. */
						if(collections.searchDocument(nameVideo)){
							int sizeVideo = collections.getDocumentVector().at(0).getSize(); /*if the video exists, it gets the size of the file.*/

							/*It gets all the binary data from all the Disks Nodes. Including Parity.*/
							sendMSG(socketNode.operator [](0), "SendData");
							string A1 = receiveMSG(socketNode.operator [](0));

							sendMSG(socketNode.operator [](1), "SendData");
							string A2 = receiveMSG(socketNode.operator [](1));

							sendMSG(socketNode.operator [](2), "SendData");
							string A3 = receiveMSG(socketNode.operator [](2));

							sendMSG(socketNode.operator [](3), "Send Parity");
							string Ap = receiveMSG(socketNode.operator [](3));

							/*In case that one Disk Node is lost from the Server connections
							 * or the data is not send or lost, the Server checks the data send
							 * from all the Disks Node. If one is missing, using the ControllerNodes's
							 * parity functions the missing data is recover and the original data is
							 * get back. The missing data is not saved, is used to recreate the original
							 * binary data of the file and sent to the Odyssey Media Player to stream the
							 * video.*/

							/*If A1 is missing.*/
							if (A1 == ""){
								cout << "se borro A1\n";
								A1 = controller.parityMgmt(A2, A3, Ap);
								cout << "largo de A1 paridad: "  << A1.length() << endl; /*FLAG	that the missing data string is recover.*/
							}
							/*If A2 is missing.*/
							if (A2 == ""){
								cout << "se borro A2\n";
								A2 = controller.parityMgmt(A1, A3, Ap);
								cout << "largo de A2 paridad: "  << A2.length() << endl; /*FLAG	that the missing data string is recover.*/
							}
							/*If A2 is missing.*/
							if (A3 == ""){
								cout << "se borro A3\n";
								A3 = controller.parityMgmt(A1, A2, Ap);
								cout << "largo de A3 paridad: "  << A3.length() << endl; /*FLAG	that the missing data string is recover.*/
							}
							cout << "se creo la paridad\n"; /*FLAG that all the data is recover.*/
							string data = A1 + A2 + A3; /*Recover of all the data together.*/
							data = data.substr(0, sizeVideo); /* Recover original binary data, taking out all the 0's added.*/
							cout << "largo de data binaria: " << data.length() << endl; /*FLAG that the original size sent at first is the same to sent back.*/
							sendMSG(sd, data); /*Send the data to the Odyssey Media Player.*/

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

/**
 * Receive the messages from the client.
 *
 * @param socketClient
 * @return message string
 */
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
