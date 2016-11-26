/*
 * ServerSockets.cpp
 *
 *  Created on: 10 nov. 2016
 *      Author: gustavo, randy, fernanda, ricardo
 */

#include "ServerSockets.h"

vector<int> socketNode;
vector<string> dataVideo;

/**
 * Constructor. Set up the connection for the Server.
 */
ServerSockets::ServerSockets() {
	struct sockaddr_in serv_addr;
	socketServer = socket(AF_INET, SOCK_STREAM, 0);
	if (socketServer < 0){
		cout << "ERROR opening socket" << endl;
		exit(-1);
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);
	bzero(&(serv_addr.sin_zero), 8);

	if (bind(socketServer, (struct sockaddr *)&serv_addr,
			  sizeof(struct sockaddr)) < 0){
		cout<<("ERROR on binding") << endl;
		exit(-1);
	}

	listen(socketServer, MAXCONNECTIONS);

	struct ifreq ifr;
	ifr.ifr_addr.sa_family = AF_INET;
	/*
	 * "wlp10s0" in GQosmio
	 * command ifconfig
	 *
	 */
	strncpy(ifr.ifr_name, "wlp3s0", IFNAMSIZ-1);
	ioctl(socketServer, SIOCGIFADDR, &ifr);
	cout << "Server IP: " << (inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr)) << endl;
	cout << "Server Port: " << (PORT) << endl;

	cliLen = sizeof(struct sockaddr);

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
		int socketClient;
		struct sockaddr_in cli_addr;
		socketClient = accept(socketServer,(struct sockaddr *)&cli_addr, &cliLen);
		if (socketClient < 0){
			 cout << "ERROR on accept" << endl;
			 break;
		}

		int buffsize = (MAXDATA);
		setsockopt(socketClient, SOL_SOCKET, SO_RCVBUF, &buffsize, sizeof(buffsize));
		setsockopt(socketClient, SOL_SOCKET, SO_SNDBUF, &buffsize, sizeof(buffsize));

		/*1. Adds new client Node to the Vector.*/
		if (receiveMSG(socketClient) == "DiskNode"){
			socketNode.push_back(socketClient);
			sendMSG(socketClient, "agregado como nodo");
			cout << "cantidad de clientes: " << ((int)socketNode.size()) << endl;
		}
		/*2. Check if the Nide will be erase. If so, closes the conecctiona and deletes the client Node from the Server.*/
		for(int i = 0; i < (int)socketNode.size(); i++){
			if (receiveMSG(socketNode.operator [](i)) == "BorrarNode"){
				close(socketNode.operator [](i));
				socketNode.erase(socketNode.begin() + i);
			}
		}

		/*3. Conditions for the messages received.*/

			/*- Option for: "Upload Video".*/
		if(receiveMSG(socketClient) == "UploadVideo"){
			sendMSG(socketClient, "Solicitud Procesada");

			sleep(5);

			string binaryVideo = receiveMSG(socketClient);
			//cout << binaryVideo << endl;

			int lengCut = (binaryVideo.length()) / 6;
			while(binaryVideo != ""){
				string cut = binaryVideo.substr(0, lengCut);
				dataVideo.push_back(cut);
				binaryVideo = binaryVideo.substr(lengCut, binaryVideo.length() -1);
			}
//			//enviar cada parte a cada nodo
//			int nodo = 0;
//			for(int i = 0; i < (int)dataVideo.size(); i++){
//				if (nodo > (int)socketNode.size()){
//					nodo = 0;
//				}
//				sendMSG(socketNode.operator [](nodo), dataVideo.operator [](i));
//			}

		}

			/*- Option for: "".*/
		if(receiveMSG(socketClient) == "E"){

			sendMSG(socketNode.operator [](1), "prueba enviar dato al node 2");
		}



			/*- Option for: "Streaming".*/
		if(receiveMSG(socketClient) == "Streaming"){

		}

			/*- Option for: "SetMetaData".*/
		if(receiveMSG(socketClient) == "SetMetaData"){
			cout << "el mae quiere cambiar la metada" << endl;
			//mostrar metada del video que quiere con
			sendMSG(socketClient, "esta es la metada");
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

	int s = send(socketClient, buffer, lengthMSG+1, MSG_OOB|MSG_PEEK);
	if (s < 0){
		cout << "ERROR on send message to client" << endl;
		exit(-1);
	}

	//cout << "bytes send: " << s-1 << endl;
}

/**
 * Receives messages from the Client.
 * @param socketClient int
 */
string ServerSockets::receiveMSG(int socketClient){
	char *buffer = new char[MAXDATA];
	int r = recv(socketClient, buffer, MAXDATA, MSG_PEEK);
	if (r < 0){
		cout << "ERROR on receive message from client" << endl;
		exit(-1);
	}

	string message;
	message = buffer;
	cout << message << endl;
	return message;

	//cout << "bytes received: " << r << endl;

}
