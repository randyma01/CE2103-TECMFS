/*
 * Block.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: randy
 */

#include "../tecmfs.raid5/Block.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>

/**
 *
 */
Block::Block(){
}

/**
 * Constructor.
 */
Block::Block(char name, const char *path) {
	this->path = path; /*Set the path for the file, assing from the Disk.*/
	this->ID = generateID(); /*Set an ID for this ID block.*/
	this->size = 10000000; /*Set the size of the block, amounts in bytes.*/
	this->name = name; /*Set the name of the block.*/
	ofstream file(path); /*Creates a file inside the Disk file.*/
}

/**
 * Destroyer
 */
Block::~Block() {
}


/**
 * Return the ID of this block.
 *
 * @return ID
 */
string Block::getID(){
	return ID;
}

/**
 * Return the size of the block file.
 *
 * @size
 */
int Block::getSize(){
	return size;
}

/**
 * Return the path of the block file.
 *
 * @path
 */
const char * Block::getPath(){
	return path;
}

/**
 * Return the name of the block.
 *
 * @path
 */
char Block::getName(){
	return name;
}

/**
 * http://www.cplusplus.com/doc/tutorial/files/
 */
void Block::saveData(string data){
	string id = this->getID();
	const char * path = this->getPath();
	fstream myfile(path, fstream::in|fstream::out|fstream::app);
	if (myfile.is_open()){
		myfile << data << endl;
		myfile.close();
		cout << "All data was written and saved." << endl;
	}else{
		cout << "Unable to open file.";
	}
}

/**
 * http://www.cplusplus.com/doc/tutorial/files/
 */
void Block::readData(){
	string line;
	string id = this->getID();
	const char * path = this->getPath();
	ifstream myfile(path);
	if (myfile.is_open()){
		while ( getline (myfile,line)){
		  cout << line << '\n';
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}

/**
 * http://www.cplusplus.com/doc/tutorial/files/
 */
//CAMBIAR METODO DE LECTURA!!!!!!!!!!!!!!!!!!!!!!!!!1

string Block::getData(){
	string data,line;
	string id = this->getID();
	const char * path = this->getPath();
	ifstream myfile(path);
	if (myfile.is_open()){
		while ( getline (myfile,line)){
			data+=line;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	return data;
}


void Block::cleanBlock(){
	string id = this->getID();
	const char * path = this->getPath();
	ofstream myfile(path);
	if (myfile.is_open()){
		myfile <<"";
		myfile.close();
	}
	else cout << "Unable to open file.";
}


/**
 * http://www.cplusplus.com/doc/tutorial/files/
 */
int Block::getSizeData(){
	int fileSize;
	streampos begin,end;
	string id = this->getID();
	const char * path = this->getPath();
	ifstream myfile(path);
	begin = myfile.tellg();
	myfile.seekg (0, ios::end);
	end = myfile.tellg();
	myfile.close();
	fileSize = (end-begin);
	return fileSize;
}

bool Block::checkSizeData(){
	bool freeSpace = false;
	//int fileSize = this->getSizeData();
	if (this->size > this->getSizeData())
		freeSpace = true;
	return freeSpace;

}

void Block::deleteFile(){
	const char * path = this->getPath();
	if( remove(path)!=0 ){
		perror( "Error deleting file" );
	}else{
		cout << "File successfully deleted" << endl;
	}
}

/**
 * Converts an number (int) into a string.
 *
 * http://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
 *
 * @param <T> number
 * @return bool
 */
template <typename T>
string Block::NumberToString ( T Number ){
     ostringstream ss;
     ss << Number;
     return ss.str();
 }

/**
 * Creates an ID for one Block.
 *
 * @return id
 */
string Block::generateID(){
	string id, ID;
	clock_t start = clock();
	int timeInt = start;
	string s = NumberToString(timeInt);
	id = generateIDAux(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
	ID +=id;

		return ID;
}

/**
 * Auxiliar function to generateID().
 * Creates an ID for one Block.
 *
 * @return id
 */
string Block::generateIDAux(unsigned char const* bytes_to_encode, unsigned int in_len) {
	  string ret;
	  int i = 0;
	  int j = 0;
	  unsigned char char_array_3[3];
	  unsigned char char_array_4[4];

	  while (in_len--){
	    char_array_3[i++] = *(bytes_to_encode++);
	    if (i == 3){
	      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
	      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
	      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
	      char_array_4[3] = char_array_3[2] & 0x3f;

	      for(i = 0; (i <4) ; i++)
	        ret += base64_chars[char_array_4[i]];
	      i = 0;
	    }
	  }

	  if (i){
	    for(j = i; j < 3; j++)
	      char_array_3[j] = '\0';

	    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
	    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
	    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
	    char_array_4[3] = char_array_3[2] & 0x3f;

	    for (j = 0; (j < i + 1); j++)
	      ret += base64_chars[char_array_4[j]];

	    while((i++ < 3))
	      ret += ' ';
	  }
	  return ret;
}



