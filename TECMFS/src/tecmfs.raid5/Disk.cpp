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
 Disk::Disk(string name){
	 XMLDocument doc;
	 doc.LoadFile("configurationNode.xml");
	  const char* ip = doc.FirstChildElement( "diskNode" )->FirstChildElement("config")->FirstChildElement("ip")->GetText();
	  const char* port = doc.FirstChildElement( "diskNode" )->FirstChildElement("config")->FirstChildElement("port")->GetText();
	  const char* path = doc.FirstChildElement( "diskNode" )->FirstChildElement("config")->FirstChildElement("path")->GetText();

	 this->ip = ip;
	 this->port = port;
	 this->pathDirectory = path;
	 this->name = name; /*Set Name.*/

	 cout <<  "Path of the Disk: " << pathDirectory << pathDirectory[15] <<endl;

	 //mkdir("/home/randy/git/TECMFS/TECMFS/DiskT/", 0700); /*Make the Directory with the given path.*/

	 mkdir("/home/randy/DiskT", 0700); /*Make the Directory with the given path.*/

	 const char *pathBlockA="/home/randy/DiskT/BlockA.txt"; /*Create the path and the file for the blocks to be saved.*/
	 const char *pathBlockB="/home/randy/DiskT/BlockB.txt"; /*Create the path and the file for the blocks to be saved.*/
	 const char *pathBlockC="/home/randy/DiskT/BlockC.txt"; /*Create the path and the file for the blocks to be saved.*/
	 const char *pathBlockP="/home/randy/DiskT/BlockP.txt"; /*Create the path and the file for the blocks to be saved.*/


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
 * @return ip const char *
 */
const char *  Disk::getIP(){
	return ip;
}

/**
 * Return the Port number of the Disk.
 *
 * @return port const char *
 */
const char *  Disk::getPort(){
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
 * @return name string
 */
string Disk::getName(){
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

/**
 * Receive data (string) and a number (int) of the block
 * to save the data.
 *
 * @param data string, i int
 */
void Disk::saveDataBlock(string data, int i){
	vectorBlocks.at(i).saveData(data);
}

/**
 * Receive the calculated parity (string) and saved
 * on the specific Block of the Disk to the parity.
 *
 * @param parity data
 */
void Disk::saveParity(string parity){
	vectorBlocks.at(3).saveData(parity);

}

/**
 *Takes from the Disk's Blocks all information
 *and keep the Blocks empty.
 */
string Disk::sendDataDisk(){
	string allData, dataA, dataB, dataC;
	dataA = vectorBlocks.at(0).getData();
	dataB = vectorBlocks.at(1).getData();
	dataC = vectorBlocks.at(2).getData();
	allData = dataA + dataB + dataC;
	//this->cleanDisk();
	return allData;
}



/**
 * Empty of the files that makes up the Disk.
 */
void Disk::cleanDisk(){
	vectorBlocks.at(0).cleanBlock();
	vectorBlocks.at(1).cleanBlock();
	vectorBlocks.at(2).cleanBlock();
	vectorBlocks.at(3).cleanBlock();
}

/**
 * Check the size of the Disk, if it is possible
 * to save data.
 *
 * @return answer bool
 */
bool Disk::checkSize(){
	bool answer = false;
	if (this->getSizeDisk() < 40000000)
		answer= true;
	return answer;
}


/**
 *Get the size of the Disk by adding the
 *individual sizes of all the Blocks.
 *
 *@return totalSize int
 */
int Disk::getSizeDisk(){
	int totalSize;
	for(int i = 0; i<4;i++){
		totalSize += this->getVectorBlocks().at(i).getSizeData();
	}
	return totalSize;
}

/**
 * Delete an espific Block from the Disk.
 */
void Disk::deleteBlock(int i){
	vectorBlocks.at(i).deleteFile();
	vectorBlocks.at(i).~Block();
}




