/*
 * Collections.cpp
 *
 *  Created on: Nov 15, 2016
 *      Author: randy
 */

#include "Collections.h"

/**
 * Constructor.
 */
Collections::Collections() {
}

/**
 * Destroyer.
 */
Collections::~Collections() {
}

/**
 *Return the name of the Collection.
 *
 *@return name string
 */
string Collections::getName(){
	return name;
}


/**
 * Return the vector that contains all the
 * documents.
 *
 * @return documentsVecto vector<Document>
 */
vector<Document> Collections::getDocumentVector(){
	return documentsVector;
}


/**
 * Insert a new document in the Collection's List.
 *
 * @param newValue Document
 */
void Collections::addDocument(Document newValue){
	documentsVector.push_back(newValue);
}


/**
 * Deletes the Document. It erase the object from the list
 * and also deletes the object itself.
 *
 * @return
 */
void Collections::deleteDocument(string delName){
	for(int i = 0; i< (int) documentsVector.size(); i++){
		if(delName == documentsVector.at(i).getName()){
			documentsVector.erase(documentsVector.begin() + i);
			documentsVector.at(i).~Document();
			break;
		}
	}
}

/**
 * Prinst all the names of the Documents inside the vector
 * of this collection.
 */
void Collections::printCollection(){
	for(int i = 0; i< (int) documentsVector.size(); i++){
		cout << "Name: " << documentsVector.at(i).getName() << endl;
	}
}

/**
 * Search on the vector of Documents of this Collections
 * the name enter. It return the Documents if exists.
 *
 * @param name string
 * @return doc Document
 */
Document Collections::searchDocument(string name){
	Document doc;
	for(int i = 0; i< (int) documentsVector.size(); i++){
		if(name == documentsVector.at(i).getName()){
			doc = documentsVector.at(i);
			break;
		}
	}
	return doc;
}
