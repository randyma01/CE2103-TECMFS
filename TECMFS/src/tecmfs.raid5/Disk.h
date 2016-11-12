/*
 * Disk.h
 *
 *  Created on: Nov 10, 2016
 *      Author: randy
 */

#ifndef TECMFS_RAID5_DISK_H_
#define TECMFS_RAID5_DISK_H_

#include "Block.h"


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Disk {

private:
	/*Atributes*/
	string ip; /*IP number for the Disk.*/
	int port; /*PORT number of the Disk.*/
	string pathDirectory; /*Path of the location of the save data.*/
	string name; /*Name of the disk.*/
	Block blockA = Block("A"); /*Block A.*/
	Block blockB = Block("B"); /*Block B.*/
	Block blockC = Block("C"); /*Block C.*/
	Block blockP = Block("Parity"); /*Block for the Parity.*/
	vector<Block> blocksVector = {blockA, blockB, blockC, blockP}; /*Vector full of the Blocks of the Disk.*/


public:
	/*Methods*/
	Disk(); /*Constructor.*/
	virtual ~Disk(); /*Destroyer.*/

	/*Functions of the disk.*/
	void receiveData(string data); /*Receive and save data into the file.*/
	void saveDataBlock(string data, Block block); /*Save the data into the block.*/
	void sendData(Block block); /*Send the data that has in the file.*/
	bool checkSize(); /*Check if there is free space in the disk. (Checks all blocks)*/
	int getSizeDick(); /*Returns the actual size of the disk by adding the data from all the blocks..*/
	void deleteBlock(Block block); /*Delete the desire block with all information related to it.*/
	void deleteDisc(); /*Delete this disk with all information related to it.*/

};

#endif /* TECMFS_RAID5_DISK_H_ */
