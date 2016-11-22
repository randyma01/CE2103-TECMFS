/*
 * Sockets.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: randy
 */

#include "ServerSockets.h"

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

ServerSockets::ServerSockets() {
}

ServerSockets::~ServerSockets() {
}


void ServerSockets::error(const char *msg){
    perror(msg);
    exit(1);
}

void ServerSockets::dostuff (int sock){
	int n;
	char * buffer;//char buffer[256];
	bzero(buffer,256);
	n = read(sock,buffer,99999999);
	if (n < 0) error("ERROR reading from socket");

	printf("Here is the message: %s\n",buffer);

	cout << buffer << endl;

	n = write(sock,"I got your message",18);
	if (n < 0) error("ERROR writing to socket");
}


int ServerSockets::run(){

	int sockfd, newsockfd, portno, pid;
	socklen_t clilen;
	struct sockaddr_in serv_addr, cli_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0){
		cout<<("ERROR opening socket");
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi("8080");
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr *)&serv_addr,
		  sizeof(serv_addr)) < 0){
		  cout<<("ERROR on binding") << endl;
		  return -1;
	}

	listen(sockfd, 5);
	clilen = sizeof(cli_addr);
	struct ifreq ifr;
	ifr.ifr_addr.sa_family = AF_INET;
	/*
	 * "wlp10s0" in GQosmio
	 *
	 * command ifconfig:
	 *  -> eth0
	 *  -> wlan0
	 *  -> lo
	 *
	 */
	strncpy(ifr.ifr_name, "wlp3s0", IFNAMSIZ-1);
	ioctl(sockfd, SIOCGIFADDR, &ifr);
	cout << "Server IP: " << (inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr)) << endl;
	cout << "Server Port: " << (portno) << endl;

	while (2) {
	         newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);

	         if (newsockfd < 0)
	        	 cout <<("ERROR on accept");
	         pid = fork();
	         if (pid < 0)
	             cout <<("ERROR on fork");
	         if (pid == 0)  {
	             //close(sockfd);
	             dostuff(newsockfd);
	             //exit(0);
         }
	         else close(newsockfd);
	     } /* end of while */
	     close(sockfd);
	     return 0; /* we never get here */
}
