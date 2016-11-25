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
 Disk::Disk(char name){
	 //this->readXMLConfig(); /*Sets the port and IP.*/
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

/**
 * Return the IP number of the Disk.
 *
 * @return ip string
 */
string Disk::getIP(){
	return ip;
}

/**
 * Return the Port number of the Disk.
 *
 * @return port int
 */
int Disk::getPort(){
	return port;
}

/**
 * Return the path of the directory where is
 * the file saved.
 *
 * @return pathDirectory const char*
 */
const char * Disk::getPathDirectory(){
	return pathDirectory;
}

/**
 * Return the name of the Disk.
 *
 * @return name char
 */
char Disk::getName(){
	return name;
}


/**
 * Return the the vector that contains all the
 * Blocks that made up the Disk.
 *
 * @return vectorBlocks vector<Blocks>
 */
vector<Block> Disk::getVectorBlocks(){
	return vectorBlocks;
}

/**
 * Return the Block A of the Disk.
 *
 * @return blockA Block
 */
Block Disk::getBlockA(){
	return blockA;
}

/**
 * Return the Block B of the Disk.
 *
 * @return blockB Block
 */
Block Disk::getBlockB(){
	return blockB;
}

/**
 * Return the Block C of the Disk.
 *
 * @return blockC Block
 */
Block Disk::getBlockC(){
	return blockC;
}

/**
 * Return the Block P of the Disk.
 *
 * @return blockP Block
 */
Block Disk::getBlockP(){
	return blockP;
}



void Disk::readXMLConfig(){

}

/**
 *
 */
void Disk::saveDataBlock(string data, int i){
	vectorBlocks.at(i).saveData(data);
}


void Disk::saveParity(string parity){
	vectorBlocks.at(4).saveData(parity);

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



