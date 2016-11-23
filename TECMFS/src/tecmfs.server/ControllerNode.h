/*
 * ControllerNode.h
 *
 *  Created on: Nov 21, 2016
 *      Author: randy
 */

#ifndef TECMFS_SERVER_CONTROLLERNODE_H_
#define TECMFS_SERVER_CONTROLLERNODE_H_


#include <iostream>
#include <fstream>

using namespace std;

/**
 *Controller Node class manages the data that will be saved,
 *moved, chaged, and delete through the process. The data
 *is binary string and chars.
 */
class ControllerNode {

public:
	/*Methods*/
	ControllerNode();
	virtual ~ControllerNode();

	string XOR(char a, char b); /*Makes the XOR logical function.*/
	string fillOnes(string str,int cant); /*Filled with ones.*/
	string superXOR(string a,string b); /*Obtain the parity given two binary strings.*/
	string parityMgmt(string a, string b, string c); /*Recover the last information from the rest.*/
};

#endif /* TECMFS_SERVER_CONTROLLERNODE_H_ */
