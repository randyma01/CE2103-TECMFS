/*
 * Document.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: randy
 */

#include "Document.h"

Document::Document() {
}

Document::Document(string name, int size, string length, string description,
		string owner, string title, string date){
	this->name = name;
	this->size = size;
	this->length = length;
	this->description = description;
	this->owner = owner;
	this->title = title;
	this->date = date;
}

Document::~Document() {
}

string Document::getName(){
	return name;
}

string Document::getLength(){
	return length;
}

int Document::getSize(){
	return size;
}

string Document::getOwner(){
	return owner;
}

string Document::getDescription(){
	return description;
}

string Document::getTitle(){
	return title;
}

string Document::getDate(){
	return date;
}


string Document::setDate(string date){
	this->date = date;
}

string Document::setDescription(string description){
	this->description = description;
}

string Document::setName(string name){
	this->name = name;
}

string Document::setTitle(string title){
	this->title = title;
}

string Document::setLength(string length){
	this->length = length;
}

