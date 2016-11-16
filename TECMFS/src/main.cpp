#include "SocketCtoJ.h"

using namespace std;


int main(){

	int portN = 8080;
	string hostIP = "172.19.13.85";
	SocketCtoJ cliente;

	string message = "";
	string menu = "Escriba mensaje:";

	cliente.startConnection(hostIP,portN);

	while(true){
		cout<<menu<<endl;
		cin>>message;
		if(message!=""){
			cliente.startConnection(hostIP,portN);
			cliente.sendMsj(message);
			message = "";
		}
		cliente.receiveMsj();
	}

	}
