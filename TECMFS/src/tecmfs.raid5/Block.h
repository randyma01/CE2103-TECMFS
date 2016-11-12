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

private:
	/*Attributes*/
	string ID; /*Identificator of this Block*/
	int size; /*Size of the block: bytes.*/
	const char * path; /*Path of the location of the save data.*/
	char name; /*Name of the block.*/


public:
	/*Methods*/
	Block();/*Constructor.*/
	Block(char name, const char *path); /*Constructorwith the name.*/
	virtual ~Block(); /*Destoyer.*/

	/*Getters.*/
	string getID();
	int getSize();
	const char * getPath();
	char getName();

	/*Functions for the Block.*/
	void saveData(string data); /*Writes the data on the file.*/
	void readData(); /*Read the data on th file.*/
	string getData(); /*Gets the data of the block.*/
	void clenBlock();; /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	int checkSizeData(); /*Checks the size of the file.*/
	bool freeSize(); /*Verifies if there's free space on the file.*/


	/*Auxiliar Functions.*/
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
