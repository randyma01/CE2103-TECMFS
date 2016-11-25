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
#include "tecmfs.server/ControllerNode.h"



using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	ControllerNode bana;

	string A = "110101";
	string B = "111111";
	string C = "010101";
	string paridadTemporal = bana.superXOR(A,B);
	string paridadFinal = bana.superXOR(paridadTemporal,C);

	Disk disco = Disk('G');

	disco.saveDataBlock(A, 0);
	disco.saveDataBlock(B, 1);
	disco.saveDataBlock(C, 2);
	disco.saveDataBlock(paridadTemporal, 3);


//
//	//quiro recuperar C, por medio de los restantes A, B paridadFinal
//	string newC = bana.parityMgmt(C, B, paridadFinal);
//	cout << newC << endl;





	return 0;
}

