//============================================================================
// Name        : ReadFile.cpp
// Author      : Djordje
// Version     : 1
// Copyright   : Copyright 2020, Djordje Obradovic, All rights reserved.
// Description : Reads from the text file, and prints it's contents.
// 			   : Populates the credentials array with the user input array.
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include "ReadFile.h"

using namespace std;


void ReadFile::readFromFIle() {

	// open passwords.txt for reading
	ifstream read("/home/sdfe/1_Personal_Work/cpp_workspace/PasswordManager/src/passwords.txt");

	// if reading is successful
	if (read.is_open()) {

		// read 3 strings in a row
		// add it to multi-dimensional array of input

		int i = 0;
		while (read >> portal >> username >> password) {
			userInputArray[i][0] = portal;
			userInputArray[i][1] = username;
			userInputArray[i][2] = password;
			i++;
		}

	} else {
		cout << "Unable to open the file!" << endl;
		exit(-1);
	}
}

void ReadFile::populateCredentials(){
	for (int x = 0; x < ROWLENGTH; x ++){
		for (int y = 0; y < COLUMNLENGTH; y++) {
			credentials[x][y] = userInputArray[x][y];
		}
	}
}

void ReadFile::printFileContents(){

	populateCredentials();
	// print out the contents of multi-dimensional array
	for (int x = 0; x < ROWLENGTH; x ++){
		for (int y = 0; y < COLUMNLENGTH; y++) {
			cout << credentials[x][y] << " ";
		}
		cout << endl;
	}
}
