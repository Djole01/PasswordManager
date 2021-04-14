//============================================================================
// Name        : ReadFile.cpp
// Author      : Djordje
// Version     : 1
// Description : Reads from the text file, and prints it's contents.
// 			   : Populates the credentials array with the user input array.
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <stdio.h>

#include "MasterPassword.h"
#include "bcrypt.h"
#include "encryptionFile.h"


using namespace std;



int flag;
int flag2;

string mpdir = "MasterPass.txt";
	
void readFromFIleMaster() {
	
	flag = masterPasswordIsSet();
	if (flag == 0){	// password isn't set, create one
		remove("passwords.txt");
		string masterPassword;
		string masterPassword2;
		string hash;
		cout << "Master password not set.\nEnter new Master password:\n";
		cin >> masterPassword;
		cout << "Confirm it by entering it again:\n";
		cin >> masterPassword2;
		if (masterPassword == masterPassword2){
			hash = bcrypt::generateHash(masterPassword2);
			writeMasterPass(hash);
			cout << "Password set" << endl;
		}
		else{
			readFromFIleMaster();
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
		ifstream read(mpdir);

		// if reading is successful
		if (FileExists(mpdir) && read.is_open()) {

			// read first line to see if master password has been set already.

			string isSet1;
		    getline(read, isSet1);
		    if (isSet1 == ""){
		    	return 0;
		    }
		    else{
				flag = std::stoi( isSet1 );
				return flag;

		    }
		} else {
			cout << "Unable to open the masterPassword file!" << endl;
			cout << "Creating new one." << endl;
			createNewFile(mpdir);
			return masterPasswordIsSet();
		}
}

void writeMasterPass(string mp){
		// creating the file object
	    fstream writing;

	    // open the file for writing
	    writing.open(mpdir, ios_base::out | ios_base::trunc);

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
			ifstream read(mpdir);

			// if reading is successful
			if (read.is_open()) {

				// read second line to see if master password matches the entered one.

				string realMPHash;
				int line_no = 0;
				while (line_no != 1 && getline(read, realMPHash)) {
				    ++line_no;
				}
				if (line_no == 1) {
					read >> realMPHash;
				}
				else {
					cout << "Error with master password file" << endl;
				}

				if (bcrypt::validatePassword(teMP, realMPHash)){
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

bool FileExists(string FileName){
	namespace fs = std::__fs::filesystem;
	fs::path f{ FileName };
	if (fs::exists(f)) return true;
	else               return false;
}

void createNewFile(string FileName){

	std::ofstream fs(FileName);
	if(!fs)
		{
			std::cerr<<"Error, cannot open the output file."<<std::endl;
		}
	fs.close();
}
