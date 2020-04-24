//============================================================================
// Name        : ReadFile.cpp
// Author      : Djordje
// Version     :
// Copyright   : Your copyright notice
// Description : Read from text file.
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
		// read one string type value from the file
		//read >> words;
		// add it to array of passwords

		int i = 0;
		while (read >> portal >> username >> password) {
			credentials[i][0] = portal;
			credentials[i][1] = password;
			credentials[i][2] = username;
			i++;
		}

	} else {
		cout << "Unable to open the file!" << endl;
		exit(-1);
	}
}
void ReadFile::printFileContents(){
	rowLength= sizeof credentials / sizeof credentials[0];
	columnLength= sizeof credentials[0] / sizeof(string);

	// print out the contents of array
	for (int x = 0; x < rowLength; x ++){
		for (int y = 0; y < columnLength; y++) {
			cout << credentials[x][y] << " ";
		}
		cout << endl;
	}
}
