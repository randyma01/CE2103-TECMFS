/*
 * Collections.h
 *
 *  Created on: Nov 15, 2016
 *      Author: randy
 */

#ifndef TECMFS_SERVER_COLLECTIONS_H_
#define TECMFS_SERVER_COLLECTIONS_H_

#include "DocumentSingleList.h"
#include "Document.h"

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

class Collections {

private:
	/*Attributos*/
	DocumentSingleList  documentList; /*Single List for managing all the Documents.*/
	string name = "Collection."; /*Set the name of the Collection.*/

public:
	/*Methods*/
	Collections();
	virtual ~Collections();

	/*Getters*/
	string getName();

	/*Setters*/
	void setName(string name);

	/*Functions*/
	void addDocument(Document newValue); /*Insert a new document in the Collection's List.*/
	void deleteDocument(Document delData); /*Delete a Document inside the Collection's List.*/
	void printCollection(); /*Prints the entire Collection's List.*/

};

#endif /* TECMFS_SERVER_COLLECTIONS_H_ */
