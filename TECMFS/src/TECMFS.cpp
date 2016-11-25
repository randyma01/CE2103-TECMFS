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
#include "tecmfs.server/Document.h"
#include "tecmfs.server/Collections.h"
#include "tecmfs.server/ServerSockets.h"



using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	string gold;

	for (int i = 0; i<250; i++){
		gold += "C";
	}

	cout << gold.length() << endl;

	gold += "·";




//	const char * path = "/home/randy/git/TECMFS/TECMFS/DiskT/BlockA.txt";
//
//
//	int fileSize;
//	streampos begin,end;
//	ifstream myfile(path);
//	begin = myfile.tellg();
//	myfile.seekg (0, ios::end);
//	end = myfile.tellg();
//	myfile.close();
//	fileSize = (end-begin);
//	cout << fileSize;


	//string line;
//	string info;
//
//	const char * path = "/home/randy/git/TECMFS/TECMFS/InformationNode.xml";
//
//	ifstream myfile(path);
//
//	char c;

//	if (myfile.is_open()){
//		while ( getline (myfile,line)){
//			 //cout << line << '\n';
//			 if (line == "<IP>"){
//				 myfile.get(c);
//				 if (c == '1' or c =='2' or c =='3' or c =='4' or c =='5' or c =='6' or c =='7'orc =='8'or =='9' or c =='0'){
//					 info +=c;
//				 }
//				cout << c << endl;
//			 }
//		}
//		myfile.close();
//	}
//	else cout << "Unable to open file";

	return 0;
}

