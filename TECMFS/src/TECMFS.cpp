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
//
//	RAIDClient diskNode1; /*RAIDCient object for connections.*/
//
//	diskNode1.startConnection(); /*Connection with the Server.*/
//	cout << diskNode1.receiveMsj() << endl;
//
//	diskNode1.sendMsj("DiskNode"); /*Sets this client as a Disk Node.*/
//
//	int posVec = 0; /*Positions of the Vector of all the Blocks.*/
//	while(true){
//		string msj = diskNode1.receiveMsj();
//
//		/*To save the information.*/
//		if(msj == "SaveData"){
//			string data = diskNode1.receiveMsj(); /*Receives data from the Server's Controller Node.*/
//			disk1.saveDataBlock(data, posVec); /*Saves the data at the Blocks's position in the Vector.*/
//			posVec++;
//		}
//
//		/*To save the parity.*/
//		else if(msj == "SaveParity"){
//			string parity = diskNode1.receiveMsj(); /*Receives the parity from the .*/
//			disk1.saveParity(parity); /*Saves the parity at the Block of the parity.*/
//		}
//
//		/*To send the data.*/
//		else if(msj == "SendData"){
//			string data1 = disk1.sendDataDisk(); /*Saves all the data from the Disk (all Blocks).*/
//			diskNode1.sendMsj(data1); /*Send the data to the Server's Controller Node.*/
//		}
//
//		/*To send the parity of the Disk (if it exists).*/
//		else if(msj == "Send Parity"){
//			string parity = disk1.sendParityDisk(); /*Gets the parity as a string.*/
//			diskNode1.sendMsj(parity); /*Send the parity to the Server's Controlle Node.*/
//		}
//		/*To delete information.*/
//		else if(msj == "DeleteDisk"){
//			disk1.cleanDisk(); /*Deletes all the data from the Disk.*/
//			diskNode1.sendMsj("DeleteNode");
//			//debería desconectarse
//		}
//	}




	return 0;
}

