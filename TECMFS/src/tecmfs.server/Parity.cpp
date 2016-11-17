/*
 * Parity.cpp
 *
 *  Created on: Nov 16, 2016
 *      Author: ricardo
 */

#include "Parity.h"

Parity::Parity() {
	// TODO Auto-generated constructor stub

}

string Parity::miXor(char a, char b){
	if(a==b){
		return "0";
	}
	else{
		return "1";
	}
}


string Parity::rellenarUnos(string str,int cant){
	string resp=str;
	for(int i=0; i<cant;i++){
		resp+="1";
	}
	return resp;
}

string Parity::getParidad(string a,string b){
	if (a.length() > b.length()){
		b= rellenarUnos(b,  (a.length()- b.length()) );
	}
	else if(a.length() < b.length()){
		a= rellenarUnos(a,  (b.length()- a.length()) );
	}

	string resp="";
	for(int i=a.length()-1; i>=0; i--){
		resp= miXor(a[i], b[i]) += resp;
		cout<<i<<endl;

	}
	return resp;
}


Parity::~Parity() {
	// TODO Auto-generated destructor stub
}

