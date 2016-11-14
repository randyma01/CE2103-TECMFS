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
 *Constructor.
 */
 Disk::Disk(char name, string IP, int port){
	 this->ip = IP; /*Set IP.*/
	 this->port = port; /*Set Port.*/
	 this->name = name; /*Set Name.*/

	 mkdir("/home/randy/git/TECMFS/TECMFS/Disk1", 0700); /*Make the Directory with the given path.*/

	 const char *pathBlockA="/home/randy/git/TECMFS/TECMFS/Disk1/BlockA.txt"; /*Create the path and the file for the blocks to be saved.*/
	 const char *pathBlockB="/home/randy/git/TECMFS/TECMFS/Disk1/BlockB.txt"; /*Create the path and the file for the blocks to be saved.*/
	 const char *pathBlockC="/home/randy/git/TECMFS/TECMFS/Disk1/BlockC.txt"; /*Create the path and the file for the blocks to be saved.*/
	 const char *pathBlockP="/home/randy/git/TECMFS/TECMFS/Disk1/BlockD.txt"; /*Create the path and the file for the blocks to be saved.*/


	 /*Set the blocks.*/
	 this->blockA = Block('A', pathBlockA); /*Block A.*/
	 this->blockB = Block('B', pathBlockB); /*Block B.*/
	 this->blockC = Block('C', pathBlockC); /*Block C.*/
	 this->blockP = Block('P', pathBlockP); /*Block for the Parity.*/

	 /*Inserting the Blocks into the Vector.*/
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


string Disk::getIP(){
	return ip;
}

int Disk::getPort(){
	return port;
}


const char * Disk::getPathDirectory(){
	return pathDirectory;
}

char Disk::getName(){
	return name;
}

vector<Block> Disk::getBlocksVector(){
	return blocksVector;
}


Block Disk::getBlockA(){
	return blockA;
}

Block Disk::getBlockB(){
	return blockB;
}

Block Disk::getBlockC(){
	return blockC;
}

Block Disk::getBlockP(){
	return blockP;
}




void receiveData(string data){
	//vector<Block> vectorBlocks = this.getBlocksVector();

	for(int i = 0; i<=4; i++){
		blocksVector.at(i).freeSize();
	}
}


void saveDataBlock(string data, Block block){

}


//void sendData(Block block); /*Send the data that has in the file.*/
//bool checkSize(); /*Check if there is free space in the disk. (Checks all blocks)*/
//int getSizeDick(); /*Returns the actual size of the disk by adding the data from all the blocks..*/
//void deleteBlock(Block block); /*Delete the desire block with all information related to it.*/
//void deleteDisc(); /*Delete this disk with all information related to it.*/



