/*
 * Block.h
 *
 *  Created on: Nov 10, 2016
 *      Author: randy
 */

#ifndef TECMFS_RAID5_BLOCK_H_
#define TECMFS_RAID5_BLOCK_H_

#include <iostream>
#include <fstream>

using namespace std;

class Block {
public:

	/*Attributes*/
	ifstream blockFile;
	string ID; /*Identificator of this Block*/
	int size = 20000; /*Size of the block: bytes.*/
	string path; /*Path of the location of the save data.*/

	Block(); /*Constructor.*/
	Block(string Path); /*Constructor with the path.*/
	virtual ~Block(); /*Destoyer.*/

	/*Getters*/
	string getID();
	int getSize();
	string getPath();

	void receiveData(); /*Receive and save data into the file.*/
	void sendData(); /*Send the data that has in the file.*/
	bool hasData(); /*Check if the bile is busy.*/
	bool maxSize(); /*Check if there is free space.*/
	int checkSize(); /*Check the actual size of the file.*/

	string generateID(); /*Generate a coded string as an ID.*/
	string generateIDAux(unsigned char const* bytes_to_encode, unsigned int in_len); /*Generate a coded string as an ID*/

	template <typename T>
	string NumberToString ( T Number ); /*Converts an integer into strings.*/

	string base64_chars =
				   	   	   	 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
							 "abcdefghijklmnopqrstuvwxyz"
							 "0123456789+/";


};

#endif /* TECMFS_RAID5_BLOCK_H_ */
