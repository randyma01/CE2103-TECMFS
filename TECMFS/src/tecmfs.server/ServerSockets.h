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


using namespace std;
/**
 * Server Sockets is a class that manages the connecions
 * and the data transfer through it. It connects the
 * Odissey Media Player and the Disk Node.
 */
class ServerSockets {


public:
	/*Methods*/
	ServerSockets(); /*Constructor.*/
	virtual ~ServerSockets(); /*Destructor.*/

	void error(const char *msg); /*Control Errors.*/
	void dostuff (int sock); /*Controls the socket..*/
	int run(); /*Makes the connection.*/
};

#endif /* TECMFS_SERVER_SERVERSOCKETS_H_ */








