/*
 * ControllerNode.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: randy
 */

#include "ControllerNode.h"


#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

ControllerNode::ControllerNode() {
}

ControllerNode::~ControllerNode() {
}

/**
 * Receives two strings. Makes the XOR logical function,
 * if A and B are different returns 1, else return 0.
 *
 * @param a char, b char
 * @return binary string
 */
string ControllerNode::XOR(char a, char b){
	if(a==b){
		return "0";
	}
	else{
		return "1";
	}
}

/**
 * Receive a string and filled it with 1's.
 *
 * @param str string, cant int
 * @return resp string
 */
string ControllerNode::fillOnes(string str,int cant){
	string resp=str;
	for(int i=0; i<cant;i++){
		resp+="1";
	}
	return resp;
}

/**
 * Receives two string, and create the parity between them.
 * In case that the string are not equal length, it automatically
 * filles the shorter one with ones.
 *
 * @param a string, b string
 * @return parity string
 */
string ControllerNode::superXOR(string a,string b){
	if (a.length() > b.length()){
		b= fillOnes(b,  (a.length()- b.length()) );
	}
	else if(a.length() < b.length()){
		a= fillOnes(a,  (b.length()- a.length()) );
	}

	string resp="";
	for(int i=a.length()-1; i>=0; i--){
		resp= XOR(a[i], b[i]) += resp;
		//cout<<i<<endl;

	}
	return resp;
}

/**
 *Parity Management (Mgmt) help to recover the data
 *by using the parity of the data stored. Is must receive
 *by three pieces of data in order to found the missing.
 *
 *@param a string, b string, c string
 *@return d string
 */
string ControllerNode::parityMgmt(string a, string b, string c){
	string d;
	d = superXOR(a,b);
	d = superXOR(c,d);
	return d;

}
