//============================================================================
// Name        : ReadFile.cpp
// Author      : Djordje
// Version     : 1
// Description : Reads from the text file, and prints it's contents.
// 			   : Populates the credentials array with the user input array.
//============================================================================

#include <iostream>
#include <fstream>
#include "ReadFile.h"
#include "MasterPassword.h"
#include "encryptionFile.h"
using namespace std;


void ReadFile::readFromFIle() {

	string pwFile;
	pwFile = "passwords.txt";
	// open passwords.txt for reading
	ifstream read(pwFile);
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
		read.close();

	} else {
		cout << "Unable to open the passwords file!" << endl;
		cout << "Creating new one." << endl;
		createNewFile(pwFile);
		ReadFile::readFromFIle();
	}
}

void ReadFile::populateCredentials(){

	for (int x = 0; x < ROWLENGTH; x ++){
		for (int y = 0; y < COLUMNLENGTH; y++) {
			credentials[x][y] = userInputArray[x][y];
			userInputArray[x][y] = "";
		}
	}
}

void ReadFile::printFileContents(){

	ReadFile::populateCredentials();
	bool emptyLine;
	// print out the contents of multi-dimensional array
	cout << endl;
	for (int x = 0; x < ROWLENGTH; x ++){
		for (int y = 0; y < COLUMNLENGTH; y++) {
			if(credentials[x][y] != ""){
				cout << credentials[x][y] << " ";
				emptyLine = 0;
			}
			else{
				emptyLine = 1;
			}
		}
		if(!emptyLine){
			cout << endl;
		}
	}
	cout << endl;
}
