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

/**
 * Constructor.
 */
Block::Block(){

}

/**
 * Constructor with the path.
 */
Block::Block(string path) {
	this->path = "/home/randy/git/TECMFS/TECMFS/";
	this->ID = generateID();
	//this->size
	//this->file
}

/**
 * Destroyer
 */
Block::~Block() {

}

/**
 * Converts an number (int) into a string.
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


void Block::saveData(string data){
	 ofstream myfile ("blockA.txt");
	  if (myfile.is_open())
	  {
		myfile << data << endl;
		myfile.close();
	  }
	  else cout << "Unable to open file.";
}



//void Block::readData(){
//	string line;
//	ifstream blockFile ("block.txt");
//	if (blockFile.is_open()){
//		while ( blockFile (blockFile,line)){
//		  cout << line << '\n';
//		}
//		blockFile.close();
//	}
//	else cout << "Unable to open file";
//}


string Block::getData(){
	string data,line;
	//ifstream blockFile ("example.txt");
	if (blockFile.is_open()){
		while ( getline (blockFile,line)){
			data+=line;
		}
		blockFile.close();
	}
	else cout << "Unable to open file";
}


