//============================================================================
// Name        : TECMFS.cpp
// Author      : randy, fernanda, ricardo
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
#include <cstdlib>
#include <cstring>



#include "tecmfs.raid5/tinyxml2.h"
#include "tecmfs.raid5/Block.h"
#include "tecmfs.raid5/Disk.h"
#include "tecmfs.raid5/RAIDClient.h"
#include "tecmfs.server/Document.h"
#include "tecmfs.server/Collections.h"
#include "tecmfs.server/ServerSockets.h"
#include "tecmfs.server/ControllerNode.h"

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;



int main() {
	cout << "!!!Hello TECMFS!!!" << endl; // prints !!!Hello World!!!

	Disk disk1 = Disk("D1");

	RAIDClient diskNode1; /*RAIDCient object for connections.*/

	diskNode1.startConnection(); /*Connection with the Server.*/
	cout << diskNode1.receiveMsj() << endl;

	diskNode1.sendMsj("DiskNode"); /*Sets this client as a Disk Node.*/

	int posVec = 0; /*Positions of the Vector of all the Blocks.*/
	while(true){
		string msj = diskNode1.receiveMsj();
		if(msj == " Holili" ){
			break;
		}

		else if(msj == "SaveData"){
			string data = diskNode1.receiveMsj();
			disk1.saveDataBlock(data, posVec);
			posVec++;
		}

		else if(msj == "SendData"){

		}
	}


// ControllerNode bana; /*Controller Node object for managing the data.*/
//	string A = "110101";
//	string B = "111111";
//	string C = "010101";
//	string paridadTemporal = bana.superXOR(A,B);
//	string paridadFinal = bana.superXOR(paridadTemporal,C);
//
 //   Disk disco = Disk("H");
//
//	disco.saveDataBlock(A, 0);
//	disco.saveDataBlock(B, 1);
//	disco.saveDataBlock(C, 2);
//	disco.saveDataBlock(paridadTemporal, 3);
//
//	string A2 = disco.sendDataDisk();
//
//	cout << A2 << endl;




	return 0;
}

