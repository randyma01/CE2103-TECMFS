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


using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	 mkdir("/home/randy/holili", 0700);



/*******WRTTING***********/

// ofstream myfile ("example.txt");
//  if (myfile.is_open())
//  {
//	myfile << "This is a line.\n";
//	myfile << "This is another line.\n";
//	myfile << "This is another line.\n";
//	myfile << "This is another line.\n";
//	myfile << "This is another line.\n";
//	myfile << "This is another line.\n";
//	myfile << "This is another line.\n";
//	myfile << "This is another line.\n";
//	myfile << "This is another line.\n";
//	myfile << "This is another line.\n";
//	myfile << "This is another line.\n";
//	myfile << "This is another line.\n";
//	myfile.close();
//  }
//  else cout << "Unable to open file";

/*******READING***********/
// string line;
//  ifstream myfile ("example.txt");
//  if (myfile.is_open())
//  {
//	while ( getline (myfile,line) )
//	{
//	  cout << line << '\n';
//	}
//	myfile.close();
//  }
//
//  else cout << "Unable to open file";




/*******SIZING***********/
//	streampos begin,end;
//	ifstream myfile ("example.txt");
//	begin = myfile.tellg();
//	myfile.seekg (0, ios::end);
//	end = myfile.tellg();
//	myfile.close();
//	cout << "size is: " << (end-begin) << " bytes.\n";


	return 0;
}

