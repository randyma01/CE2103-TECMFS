/*
 * Parity.h
 *
 *  Created on: Nov 21, 2016
 *      Author: randy
 */

#ifndef TECMFS_SERVER_PARITY_H_
#define TECMFS_SERVER_PARITY_H_

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

class Parity {

public:

	/*Methods.*/
	Parity(); /*Constructor.*/
	virtual ~Parity(); /*Destroyer.*/

	string XOR(char a, char b); /*Makes the XOR logical function.*/
	string fillOnes(string str,int cant); /*Filled with ones.*/
	string createParity(string a,string b); /*Parity.*/

};

#endif /* TECMFS_SERVER_PARITY_H_ */
