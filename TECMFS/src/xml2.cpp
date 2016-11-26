//============================================================================
// Name        : xml2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "tinyxml2.h"
#include <cstdlib>
#include <cstring>


using namespace std;
using namespace tinyxml2;

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif



int main() {

	//FILE* fp = fopen( "info.xml", "r" );

	XMLDocument doc;
	doc.LoadFile("infoNode.xml");

	const char* ip = doc.FirstChildElement( "diskNode" )->FirstChildElement("config")->FirstChildElement("ip")->GetText();
	const char* port = doc.FirstChildElement( "diskNode" )->FirstChildElement("config")->FirstChildElement("port")->GetText();
	const char* path = doc.FirstChildElement( "diskNode" )->FirstChildElement("config")->FirstChildElement("path")->GetText();
	printf( "ip: %s\n", ip );
	printf( "port: %s\n", port );
	printf( "path: %s\n", path );
}
