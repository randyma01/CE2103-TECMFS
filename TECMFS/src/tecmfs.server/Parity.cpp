/*
 * Parity.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: randy
 */

#include "Parity.h"

Parity::Parity() {
}

Parity::~Parity() {
}



string Parity::XOR(char a, char b){
	if(a==b){
		return "0";
	}
	else{
		return "1";
	}
}


string Parity::fillOnes(string str,int cant){
	string resp=str;
	for(int i=0; i<cant;i++){
		resp+="1";
	}
	return resp;
}

string Parity::createParity(string a,string b){
	if (a.length() > b.length()){
		b= fillOnes(b,  (a.length()- b.length()) );
	}
	else if(a.length() < b.length()){
		a= fillOnes(a,  (b.length()- a.length()) );
	}

	string resp="";
	for(int i=a.length()-1; i>=0; i--){
		resp= XOR(a[i], b[i]) += resp;
		cout<<i<<endl;

	}
	return resp;
}

