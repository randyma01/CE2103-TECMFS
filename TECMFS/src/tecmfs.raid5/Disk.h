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

using namespace std;

class Disk {
public:

	/*Atributes*/
	char ID; /*Identificator of this disk.*/
	string ip; /*IP number for the Disk.*/
	int port; /*PORT number of the Disk.*/
	string pathDirectory; /*Path of the location of the save data.*/

//	Block blockA = Block(); /*Block A.*/
//	Block blockB = Block(); /*Block A.*/
//	Block blockC = Block(); /*Block A.*/
//	Block blockP = Block(); /*Block for the Parity.*/

	void receiveData(); /*Receive and save data into the file.*/
	void sendData(); /*Send the data that has in the file.*/
	bool hasData(); /*Check if the bile is busy.*/
	bool maxSize(); /*Check if there is free space.*/
	int checkSize(); /*Check the actual size of the file.*/

	Disk(); /*Constructor.*/
	//Disk();
	virtual ~Disk(); /*Destroyer.*/


};

#endif /* TECMFS_RAID5_DISK_H_ */
