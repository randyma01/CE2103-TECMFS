/*
 * DoublyLinkedList.cpp
 *
 *  Created on: Nov 15, 2016
 *      Author: randy
 */

#include "DocumentSingleList.h"

/**
 * Constructor
 */
DocumentSingleList::DocumentSingleList() {
	len=0;
	head=NULL;

}

/**
 * Destroyer
 */
DocumentSingleList::~DocumentSingleList() {
}


/**
 * Insert a new node in list with as a
 * newValue object (Document).
 *
 * @params newValue Document
 */
void DocumentSingleList::insertData(Document newValue) {	//adds a new node with the given value
	Node* newNode= new Node();
	newNode->value=newValue;

	if (head!=NULL){	//if list is not empty
		Node *temp=head;
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next = newNode;
		newNode->posc = len;
		len++;

	}else{	//if list is empty
		head=newNode;
		newNode->posc=0;
		len=1;
	}
}

/**
 * Deletes the first node as a nodeValue object
 * (Document) in the list.
 *
 * @params nodeValue Document
 */
void DocumentSingleList::deleteData(Document nodeValue){	//deletes the first node that is found with the given value
	string nodeValueName = nodeValue.getName();
	if (head==NULL){	//first case: Empty list
		cout << "ERROR"<<endl;
		return;
	}
	Node *temp=head;
	Node *temp2=temp->next;
	bool flagDeleated=false;
	if ((head->value.getName()==nodeValueName)){	//second case: found at the beginning
		head=head->next;
		temp=temp->next;
		flagDeleated=true;
	}
	else{	//third case: anywhere else
		while((flagDeleated == false)&&(temp2!=NULL)){
			if ((temp2->value.getName()==nodeValueName)){
				temp->next = temp2->next;
				temp=temp2;
				flagDeleated=true;
			}
			else{
				temp=temp2;
				temp2=temp2->next;
			}
		}
	}

	if(flagDeleated==false){
			cout<<"ERROR";
			cout<< "-1" <<endl;
			return;
		}

	while(temp!=NULL){
		temp->posc--;
		temp=temp->next;
	}
	len--;

}

/**
 * Print the list.
 */
void DocumentSingleList::printList() {
    Node *temp = head;
    while(temp!=NULL){
    	ostringstream ss;
    	ss << temp->value.getSize();
    	string size= ss.str();

    	string info=(" name: " + temp->value.getName()); // + "  size: " + temp->value.getName() + "  length: " + temp->value.getLength() + " owner: " + temp->value.getOwner());
        //cout<<temp->value;		//print the value
        cout << " [";
        cout << ("poscicion: ") ;	//print the position
        cout << (temp->posc) ;	//print the position
        cout <<info;
        cout << "] -> " <<endl ;

        temp=temp->next;
    }
    cout<<endl;
}

/**
 * Return an Document object from the list,
 * from the position insert in the parameter.
 *
 * @params x int
 */
Document DocumentSingleList::getDataX(int x){
	Node *temp=head;
	Document nodeValue;
	while(temp!=NULL){
		if (temp->posc == x){
			nodeValue = temp->value;
			break;
		}
		else{
			temp=temp->next;
		}
	}
	return nodeValue;
}


//
//string Document::searchByName(string name){
//	string answer;
//	Node *temp=head;
//	Document nodeValue;
//	return answer;


}
