#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

void printHelp() {
	cout << "This is the help page." << endl;
}

int main(int argc, char* argv[]) {
	//Check arguments
	if (argc != 2) {
		cout << "Invalid number of arguments." << endl;
		printHelp();
		return 1;
	}

	//Ask user for password
	cout << "Please enter the MySQL password: " << endl;
	string password; 
	cin >> password;
	//Test 
	cout << "Username: " << argv[1] << " Password: " << password << endl;
	
	//Run ARP scan
	string command = "arp -a";
	FILE *output = popen(command.c_str(), "r");
	if (!output) { //if output is null, popen failed
		cout << "Failed to execute arp command." << endl;
	}	
	char lineChr[100]; //char array used for fgets
	string lineStr, hostname, ip, mac;
	while (fgets(lineChr, 100, output) != NULL) {
		lineChr[strlen(lineChr)-1] = '\00';
		lineStr.assign(lineChr);
		int pos1 = lineStr.find("(");
		cout << lineStr << endl;
		hostname = lineStr.substr(0,pos1-1);
		cout << "Hostname: "<< hostname  << endl;
		int pos2 = lineStr.find(")");
		ip = lineStr.substr(pos1+1, pos2-pos1-1);
		cout << "IP: " << ip << endl;
		int pos3 = lineStr.find("at");
		mac = lineStr.substr(pos3+3, 17);
		cout << "MAC: " << mac << endl;
	}	

	//Read and parse output file

	//Add to database
	pclose(output);
}
