/*
 * Sockets.h
 *
 *  Created on: Nov 21, 2016
 *      Author: randy
 */

#ifndef TECMFS_SERVER_SERVERSOCKETS_H_
#define TECMFS_SERVER_SERVERSOCKETS_H_

#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <net/if.h>
#include <errno.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <vector>

#include "Document.h"
#include "Collections.h"
#include "ControllerNode.h"



#define MAXDATA 64000000
#define MAXCONNECTIONS 5
#define PORT 8080


using namespace std;
/**
 * Server Sockets is a class that manages the connecions
 * and the data transfer through it. It connects the
 * Odissey Media Player and the Disk Node.
 */
class ServerSockets {



public:
	/*Methods.*/
	ServerSockets();/*Constructor.*/
	virtual ~ServerSockets(); /*Destructor.*/
	void run();/*Makes the connection.*/


private:
	/*Attributes.*/
	int socketServer; /*Socket integer manager.*/
	socklen_t cliLen; /*Socket client.*/

	/*Methods.*/
	void sendMSG(int client, string msg); /*Send messages to the client.*/
	string receiveMSG(int client); /*Receive messages from the client.*/

};

#endif /* TECMFS_SERVER_SERVERSOCKETS_H_ */








