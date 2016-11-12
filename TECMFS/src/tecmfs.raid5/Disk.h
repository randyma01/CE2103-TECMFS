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
	/*Attributes*/
	string ip; /*IP number for the Disk.*/
	int port; /*PORT number of the Disk.*/
	char pathDirectory; /*Path of the location of the save data.*/
	char name; /*Name of the disk.*/
	vector<Block> blocksVector;/*Vector full of the Blocks of the Disk.*/


public:


	/*Methods*/
	Disk(); /*Constructor.*/
	Disk(char name, string IP, int port); /*+++++++++++++.*/
	virtual ~Disk(); /*Destroyer.*/

	/*Getters*/
	string getIP();
	int getPort();
	char getPathDirectory();
	char getName();
	vector<Block> getBlocksVector();

	/*Setters*/
	void setIP(string ip);
	void setPort(int port);
	void setPath(char path);
	void setName(char name);

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
