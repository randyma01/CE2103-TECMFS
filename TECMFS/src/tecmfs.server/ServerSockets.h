/*
 * ServerSockets.h
 *
 *  Created on: 10 nov. 2016
 *      Author: gustavo, randy, fernanda
 */

#ifndef SERVERSOCKETS_H_
#define SERVERSOCKETS_H_

#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
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
#include <pthread.h>
#include <fstream>

using namespace std;

#define MAXDATA 64000000
#define MAXCONNECTIONS 5
#define PORT 8080

class ServerSockets {

public:
	ServerSockets();
	void run();
	virtual ~ServerSockets();

private:
	int socketServer;
	socklen_t cliLen;
	void sendMSG(int client, string msg);
	string receiveMSG(int client);

};

#endif /* SERVERSOCKETS_H_ */
