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
	const char * pathDirectory = "/home/randy/git/TECMFS/TECMFS"; /*Path of the location of the save data.*/
	char name; /*Name of the Disk.*/
	int size = 40000000; /*Size of the Disk.*/

	vector<Block> vectorBlocks;/*Vector full of the Blocks of the Disk.*/
	Block blockA; /*First or Block A of the Disk.*/
	Block blockB; /*Second or Block B of the Disk.*/
	Block blockC; /*Third or Block C of the Disk.*/
	Block blockP; /*Fourth or Block P (Parity) of the Disk.*/



public:

	/*Methods*/
	Disk(); /*Constructor.*/
	Disk(char name); /*+++++++++++++.*/
	virtual ~Disk(); /*Destroyer.*/

	/*Getters*/
	string getIP();
	int getPort();
	const char * getPathDirectory();
	char getName();
	vector<Block> getVectorBlocks();
	Block getBlockA();
	Block getBlockB();
	Block getBlockC();
	Block getBlockP();

	/*Setters*/
	void setIP(string ip);
	void setPort(int port);
	void setPath(char path);
	void setName(char name);

	/*Functions of the disk.*/
	void readXMLConfig(); /*Reads the XML for the IP and the path for the Disk.*/
	void saveDataBlock(string data, int i); /*Save the data into the block.*/
	void saveParity(string parity); /*Sava the parity.*/
	string sendDataDisk(); /*Send the data that has in the file.*/
	void cleanDisk(); /*Erase all data from blocks.*/
	bool checkSize(); /*Check if there is free space in the disk. (Checks all blocks)*/
	int getSizeDisk(); /*Returns the actual size of the disk by adding the data from all the blocks.*/
	void deleteBlock(int i); /*Delete the desire block with all information related to it.*/
	void deleteDisc(); /*Delete this disk with all information related to it.*/

};

#endif /* TECMFS_RAID5_DISK_H_ */
