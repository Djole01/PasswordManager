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

int flag;
void readFromFIleMaster() {

	flag = masterPasswordIsSet();
	cout << flag << endl;
	if (flag == 0){	// password isnt set, create one

		string masterPassword;
		string masterPassword2;
		cout << "Master password not set.\nEnter new Master password:\n";
		cin >> masterPassword;
		cout << "Confirm it by entering it again:\n";
		cin >> masterPassword2;
		if (masterPassword == masterPassword2){
			cout << "Password set";
			// write file 1
			// writeMasterPass();
		}
	}
	else {	// password is set, log in.

		string tempMP;
		cout << "enter master password:\n";
		cin >> tempMP;
		// open the file and see if tempMp matches line 2.

	}


}


// todo
// ask the user to set a password if it's not done so already.
// if it is, ask user to enter that password, check if it matches.
// make this all a loop.

int masterPasswordIsSet(){

	// open MasterPass.txt for reading
		ifstream read("/home/sdfe/1_Personal_Work/cpp_workspace/PasswordManager/src/MasterPass.txt");

		// if reading is successful
		if (read.is_open()) {

			// read first line to see if master password has been set already.

			string isSet1;
			string masterPasswordIsSet;
			int line_no = 0;
			while (line_no != 1 && getline(read, isSet1)) {
			    ++line_no;
			}
			if (line_no == 1) {
				read >> isSet1;
			}
			else {
				cout << "Error with master password file" << endl;
			}

			flag = std::stoi( isSet1 );
			return flag;

		} else {
			cout << "Unable to open the file!" << endl;
			exit(-1);
		}
}
