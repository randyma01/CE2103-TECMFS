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
	string length; /*Length (milliseconds) of the Video.*/
	int size; /*(Size (bytes) of the Video. ).*/
	string owner; /*Name of the owner of the Video.*/
	string description; /*Small description of the Video.*/
	string title; /*Title of the video*/
	string date; /*Encoded Date of the file*/
//	string Disk; /**/


public:
	/*Methods.*/
	Document(); /*Consturctor.*/
	Document (string name, int size, string length, string description, string owner, string title, string date); /*Destoyer.*/
	virtual ~Document();

	/*Getters.*/
	int getSize();
	string getName();
	string getLength();
	string getOwner();
	string getDescription();
	string getTitle();
	string getDate();

	string setName(string name);
	string setLength(string length);
	string setDescription(string description);
	string setTitle(string title);
	string setDate(string date);

};

#endif /* TECMFS_SERVER_DOCUMENT_H_ */
