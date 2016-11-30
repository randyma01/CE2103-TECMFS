/*
 * Collections.cpp
 *
 *  Created on: Nov 15, 2016
 *      Author: randy
 */

#include "Collections.h"

int indice;
bool answer;

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
bool Collections::searchDocument(string parameter){
	answer = false;
	for(int i = 0; i< (int) documentsVector.size(); i++){
		if(parameter == documentsVector.at(i).getName()){
			answer = true;
			indice = i;
			break;
		}
		else if(parameter == documentsVector.at(i).getDescription()){
			answer = true;
			indice = i;
			break;
		}
		else if(parameter == documentsVector.at(i).getLength()){
			answer = true;
			indice = i;
			break;
		}
		else if(parameter == documentsVector.at(i).getOwner()){
			answer = true;
			indice = i;
			break;
		}
		else if(parameter == documentsVector.at(i).getDate()){
			answer = true;
			indice = i;
			break;
		}
		else if(parameter == documentsVector.at(i).getTitle()){
			answer = true;
			indice = i;
			break;
		}
	}
	return answer;
}


Document Collections::getDocument(){
	if(answer){
		return documentsVector.at(indice);
	}
}
