//============================================================================
// Name        : ReadFile.cpp
// Author      : Djordje
// Version     :
// Copyright   : Your copyright notice
// Description : Read from text file.
//============================================================================

#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include "ReadFile.h"

using namespace std;
void readFromFIle() {

	string portal; // platform/website/app
	string password;
	string username;

	array<string,10> portals;
	array<string,10> passwords;
	array<string,10> usernames;

	// open passwords.txt for reading
	ifstream read("/home/sdfe/1_Personal_Work/cpp_workspace/PasswordManager/src/passwords.txt");

	// if reading is successful
	if (read.is_open()) {
	// read one string type value from the file
	//read >> words;
	// add it to array of passwords

	int i = 0;
	while (read >> portal >> username >> password) {
		passwords[i] = password;
		portals[i] = portal;
		usernames[i] = username;
		i++;
	}

	} else {
	cout << "Unable to open the file!" << endl;
	exit(-1);
	}

	// print out the contents of array
	for (unsigned int x = 0; x < passwords.size(); x ++){
		cout << portals[x] << " " <<  usernames[x] <<" " << passwords[x] << endl;

	}
}
