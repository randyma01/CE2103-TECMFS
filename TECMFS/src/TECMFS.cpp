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


//	ServerSockets holili = ServerSockets();
//	holili.run();


//
//	string holilili;
//	char jojo = 'je';
//
//	holilili += jojo;
//	holilili += jojo++;
//
//	cout << holilili;

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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

//	cout << info;


	//************ESCRIBIR XML Y LEERLO COMO PARAMETROS PARA LA CONEXCION

//	Document lo = Document("Lo");
//	Document lu = Document("Lu");
//	Document li = Document("Li");
//	Document la = Document("La");
//
//
//	DocumentSingleList listilla = DocumentSingleList();
//	listilla.insertData(lo);
//	listilla.insertData(lu);
//	listilla.insertData(li);
//	listilla.insertData(la);
//
//	listilla.printList();

//	cout << "holili" << endl;
//	cout << listilla.searchByName("lo");
//
////
//	Disk testDisk = Disk('k', "IP", 9080);
//	testDisk.receiveData("holi + lili");
//	testDisk.deleteBlock(testDisk.getVectorBlocks().at(2));

//	2 655 436 982
//	885 145 660.7

//	int myAge = 19;
//	cout << "Size of int " << sizeof(myAge) << endl;

	//testDisk.deleteBlock(testDisk.getVectorBlocks().at(1));

//	const char *path="/home/randy/git/TECMFS/TECMFS/DiskT/BlockA.txt";
//	{
//	  if( remove(path) != 0 )
//	    perror( "Error deleting file" );
//	  else
//	    puts( "File successfully deleted" );
//	  return 0;
//	}

	//testDisk.deleteBlock(testDisk.getVectorBlocks().at(0));

	//cout << testDisk.getVectorBlocks().size();
	//	 mkdir("/home/randy/holili", 0700);

//	long int y = 79;
//	int x = 1;
//
//	long long int z = 2;
//
//	cout << x+y+z;

	//Disk testDisk = Disk('k', "IP", 9080);

	//cout << testDisk.getBlocksVector().size();
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

