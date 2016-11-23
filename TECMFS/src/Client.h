/*
 * Client.h
 *
 *  Created on: 21 nov. 2016
 *      Author: gustavo, fernanda
 */

#ifndef CONNECTION_CLIENT_H_
#define CONNECTION_CLIENT_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <net/if.h>
#include <errno.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sys/stat.h>


using namespace std;

#define MAXDATASIZE 64000000

/**
 * Class for the creation for a C/C++ socket.
 */

class Client {

private:
	int descriptor;

public:
	Client();
	virtual ~Client();
	int startConnection(string host, int port);
	string receiveMsj();
	void sendMsj(string mensaje);
	char getBuffer();
};

#endif /* CONNECTION_CLIENT_H_ */
