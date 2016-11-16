/*
 * cliente.h
 *
 *  Created on: 14 nov. 2016
 *      Author: fernanda
 */

#ifndef API_SOCKETCTOJ_H_
#define API_SOCKETCTOJ_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * Class for the creation for a C/C++ socket.
 */

class SocketCtoJ {
private:
	int MAXDATASIZE;
	int descriptor;
public:
	SocketCtoJ();
	virtual ~SocketCtoJ();
	int startConnection(string host, int port);
	void receiveMsj();
	void sendMsj(string mensaje);
	char buffer[1024];
	char getBuffer();
};


#endif /* API_SOCKETCTOJ_H_ */
