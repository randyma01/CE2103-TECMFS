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

	 mkdir("/home/randy/git/TECMFS/TECMFS/DiskT", 0700); /*Make the Directory with the given path.*/

	 const char *pathBlockA="/home/randy/git/TECMFS/TECMFS/DiskT/BlockA.txt"; /*Create the path and the file for the blocks to be saved.*/
	 const char *pathBlockB="/home/randy/git/TECMFS/TECMFS/DiskT/BlockB.txt"; /*Create the path and the file for the blocks to be saved.*/
	 const char *pathBlockC="/home/randy/git/TECMFS/TECMFS/DiskT/BlockC.txt"; /*Create the path and the file for the blocks to be saved.*/
	 const char *pathBlockP="/home/randy/git/TECMFS/TECMFS/DiskT/BlockP.txt"; /*Create the path and the file for the blocks to be saved.*/


	 /*Set the blocks.*/
	 this->blockA = Block('A', pathBlockA); /*Block A.*/
	 this->blockB = Block('B', pathBlockB); /*Block B.*/
	 this->blockC = Block('C', pathBlockC); /*Block C.*/
	 this->blockP = Block('P', pathBlockP); /*Block for the Parity.*/

	 /*Inserting the Blocks into the Vector.*/
	 vectorBlocks.push_back(blockA);
	 vectorBlocks.push_back(blockB);
	 vectorBlocks.push_back(blockC);
	 vectorBlocks.push_back(blockP);

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

vector<Block> Disk::getVectorBlocks(){
	return vectorBlocks;
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


void Disk::receiveData(string data){
	for(int i = 0; i<4; i++){
		if(this->getVectorBlocks().at(i).checkSizeData() == true ){
			this->saveDataBlock(data, this->getVectorBlocks().at(i));
			break;
		}
	}

}


void Disk::saveDataBlock(string data, Block block){
	  block.saveData(data);
}


void Disk::sendData(Block block){
	string data = block.getData();
	cout << data;
}

bool Disk::checkSize(){
	bool answer = false;
	if (this->getSizeDisk() < 40000000)
		answer= true;
	return answer;
}


int Disk::getSizeDisk(){
	int totalSize;
	for(int i = 0; i<4;i++){
		totalSize += this->getVectorBlocks().at(i).getSizeData();
	}
	return totalSize;
}

void Disk::deleteBlock(Block block){

	block.deleteFile();
	block.~Block();
//	string blockID = block.getID();
//	for(int i = 0; i<4;i++){
//		string vectorBlockID = this->getVectorBlocks().at(i).getID();
//		if(vectorBlockID == blockID){
//			this->getVectorBlocks().erase(this->getVectorBlocks().begin()+i);
//			block.deleteFile();
//			block.~Block();
//		}
//	}
}

void Disk::deleteDisc(){
	this->~Disk();
}



