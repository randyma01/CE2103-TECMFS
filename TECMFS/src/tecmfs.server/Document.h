/*
 * Document.h
 *
 *  Created on: Nov 14, 2016
 *      Author: randy
 */

#ifndef TECMFS_SERVER_DOCUMENT_H_
#define TECMFS_SERVER_DOCUMENT_H_


#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

/**
 * Document class, is a register NOSQL alike. Each new video
 * upload creates a new instantes of this class with the basic
 * information of the video.
 *
 */
class Document {

private:
	/*Attributes.*/
	string name; /*Name of the Video.*/
	int length; /*Length (seconds) of the Video.*/
	int size; /*(Size (bytes) of the Video. ).*/
	string owner; /*Name of the owner of the Video.*/
	char description[350]; /*Small description of the Video.*/
//	string Disk; /**/


public:
	/*Methods.*/
	Document(); /*Consturctor.*/
	Document (string name); /*Destoyer.*/
	virtual ~Document();

	/*Getters.*/
	string getName();
	int getLength();
	int getSize();
	string getOwner();
	char getDescription();

};

#endif /* TECMFS_SERVER_DOCUMENT_H_ */