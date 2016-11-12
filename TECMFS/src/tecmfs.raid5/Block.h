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
	string ID; /*Identificator of this Block*/
	int size; /*Size of the block: bytes.*/
	string path; /*Path of the location of the save data.*/

	Block(); /*Constructor.*/
	Block(string Path); /*Constructor with the path.*/
	virtual ~Block(); /*Destoyer.*/

	/*Getters of the attributes.*/
	string getID();
	int getSize();
	string getPath();

	/*Methods*/
	void saveData(string data); /*Writes the data on the file.*/
	void readData(); /*Read the data on th file.*/
	void checkSize(); /*Checks the size of the file.*/
	bool maxSize(); /*Verifies if there's free space on the file.*/
	string getData(); /*Gets the data of the block.*/


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
