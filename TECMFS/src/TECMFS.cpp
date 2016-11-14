//============================================================================
// Name        : TECMFS.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "tecmfs.raid5/Block.h"
#include "tecmfs.raid5/Disk.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	 mkdir("/home/randy/holili", 0700);


	Disk testDisk = Disk('T', "IP", 9080);
//
//	const char *pathBlockA="/home/randy/Disk1/BlockA.txt"; /*Create the path and the file for the blocks to be saved.*/
//	ofstream file(pathBlockA);
//	//file << "";

//
//	Block testingBlock = Block();
//	cout << testingBlock.getID() <<endl;
//
//	testingBlock.saveData("1100101010101010101010100001");
//
//	testingBlock.readData();



	return 0;
}

