/*
 * Parity.h
 *
 *  Created on: Nov 16, 2016
 *      Author: ricardo
 */

#ifndef TECMFS_SERVER_PARITY_H_
#define TECMFS_SERVER_PARITY_H_

#include <iostream>


using namespace std;


class Parity {
public:
	Parity();
	string miXor(char a, char b);
	string rellenarUnos(string str,int cant);
	string getParidad(string a,string b);
	virtual ~Parity();
};

#endif /* TECMFS_SERVER_PARITY_H_ */
