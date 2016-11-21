/*
 * DoublyLinkedList.h
 *
 *  Created on: Nov 15, 2016
 *      Author: randy
 */

#ifndef TECMFS_SERVER_DOCUMENTSINGLELIST_H_
#define TECMFS_SERVER_DOCUMENTSINGLELIST_H_

#include <iostream>
#include <stdio.h>
#include <sstream>

#include "Document.h"

using namespace std;


class DocumentSingleList {

private:
	/*Attributes.*/

	struct Node{			/*Struct for the list.*/
		Document value;		/*Document.*/
		Node *next;			/*Node.*/
		int posc;			/*Position i at the list.*/
	};

	int len; /*Legnth of the list.*/
	struct Node *head; /*Node from the head of the list..*/


public:
	/*Methods.*/

	DocumentSingleList();  		  /*Constructor,*/
	virtual ~DocumentSingleList(); /*Destroyer.*/

	/*Basic functions.*/
	void insertData(Document addData); /*.Insert a new data to the list.*/
	void deleteData(Document delData); /*Deletes a data from the list.*/
	void printList();				   /*Print in screen all the data from the list.*/
	Document getDataX(int x);		   /*Gets a document from a certain position in the list.*/
	bool searchByName(string name); /*Search on the list by the name of the Document.*/


};








#endif /* TECMFS_SERVER_DOCUMENTSINGLELIST_H_ */


