/*
 * Disk.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: randy
 */

#include "../tecmfs.raid5/Disk.h"

#include "Block.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>


/**
 * Constructor.
 */
Disk::Disk() {
}

/**
 *
 */
 Disk::Disk(const char * name, string IP, int port){
	 this->ip = IP;
	 this->port = port;
	 this->name = name;
	 this->pathDirectory += name; /*Path of the Directory of the Disk.*/

	 mkdir("/home/randy/git/TECMFS/TECMFS/Disk"+name, 0700); /*Make the Directory with the given path*/
	 const char *pathBlock="/home/randy/git/TECMFS/TECMFS/Disk"+name;

	 Block blockA = Block("A", pathBlock); /*Block A.*/
	 Block blockB = Block("B", pathBlock); /*Block B.*/
	 Block blockC = Block("C", pathBlock); /*Block C.*/
	 Block blockP = Block("Parity", pathBlock); /*Block for the Parity.*/
	 blocksVector.push_back(blockA);
	 blocksVector.push_back(blockB);
	 blocksVector.push_back(blockC);
	 blocksVector.push_back(blockP);

 }


/**
 * Destroyer.
 */
Disk::~Disk() {
}


