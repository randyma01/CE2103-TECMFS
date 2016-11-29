/*
 * Document.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: randy
 */

#include "Document.h"

Document::Document() {
}

Document::Document(string name, int size){
	this->name = name;
	this->size = size;
}

Document::~Document() {
}

string Document::getName(){
	return name;
}

int Document::getLength(){
	return length;
}

int Document::getSize(){
	return size;
}

string Document::getOwner(){
	return owner;
}

char Document::getDescription(){
	return description[350];
}

