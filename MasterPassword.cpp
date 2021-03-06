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
#include "MasterPassword.h"

using namespace std;

int masterPasswordIsSet();
void writeMasterPass(string mp);
void passCheck(string teMP);

int flag;
int flag2;
void readFromFIleMaster() {

	flag = masterPasswordIsSet();
	if (flag == 0){	// password isnt set, create one

		string masterPassword;
		string masterPassword2;
		cout << "Master password not set.\nEnter new Master password:\n";
		cin >> masterPassword;
		cout << "Confirm it by entering it again:\n";
		cin >> masterPassword2;
		if (masterPassword == masterPassword2){
			cout << "Password set";
			writeMasterPass(masterPassword);
		}
	}
	else {	// password is set, log in.

		while (flag2 == 0){
		string tempMP;
		cout << "enter master password:\n";
		cin >> tempMP;
		passCheck(tempMP);
		}
	}
}

int masterPasswordIsSet(){

	// open MasterPass.txt for reading
		ifstream read("/home/sdfe/1_Personal_Work/cpp_workspace/PasswordManager/src/MasterPass.txt");

		// if reading is successful
		if (read.is_open()) {

			// read first line to see if master password has been set already.

			string isSet1;
		    getline(read, isSet1);
			flag = std::stoi( isSet1 );
			return flag;

		} else {
			cout << "Unable to open the file!" << endl;
			exit(-1);
		}
}

void writeMasterPass(string mp){
		// creating the file object
	    fstream writing;

	    // open the file for writing
	    writing.open("/home/sdfe/1_Personal_Work/cpp_workspace/PasswordManager/src/MasterPass.txt" , ios_base::out | ios_base::trunc);

	    if (!writing.is_open()) {
	        cout << "Failed to open the file!" << endl;
	        exit(-1);
	    }

	    // file is open, let's move on...
	    writing << 1 << "\n" << mp <<  endl;
	    writing.close(); // close the file where the rows were stored in.
}

void passCheck(string teMP){

	// open MasterPass.txt for reading
			ifstream read("/home/sdfe/1_Personal_Work/cpp_workspace/PasswordManager/src/MasterPass.txt");

			// if reading is successful
			if (read.is_open()) {

				// read second line to see if master password matches the entered one.

				string realMP;
				int line_no = 0;
				while (line_no != 1 && getline(read, realMP)) {
				    ++line_no;
				}
				if (line_no == 1) {
					read >> realMP;
				}
				else {
					cout << "Error with master password file" << endl;
				}

				if (realMP == teMP){
					cout << "Login successful!" << endl;
					flag2 = 1;
				}
				else {
					cout << "Login failed, master password does not match!" << endl;
				}

			} else {
				cout << "Unable to open the file!" << endl;
				exit(-1);
			}
}
