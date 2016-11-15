/*
 * Collections.h
 *
 *  Created on: Nov 15, 2016
 *      Author: randy
 */

#ifndef TECMFS_SERVER_COLLECTIONS_H_
#define TECMFS_SERVER_COLLECTIONS_H_

#include "DocumentSingleList.h"

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

	DocumentSingleList  documentList; /*Single List for managing all the Documents.*/
	string name = "Collection."; /*Set the name of the Collection.*/

public:
	Collections();
	virtual ~Collections();
};

#endif /* TECMFS_SERVER_COLLECTIONS_H_ */
