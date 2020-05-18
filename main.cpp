//============================================================================
// Name        : writeToFIle.cpp
// Author      : Viope C++ course
// Version     : 1
// Copyright   : Copyright 2020, Djordje Obradovic, All rights reserved.
// Description : Password manager program. Let's user store a list of passwords,
// 				display the list and edit it. The passwords will be stored in a
// 				encrypted text file.
//============================================================================


#include "UserOptions.h"
#include "ReadFile.h"
#include "WritingFiles.h"
#include "MasterPassword.h"
#include <iostream>
using namespace std;

int main() {
	ReadFile f1;
	int option, exitFlag;
	readFromFIleMaster();
	exitFlag = 0;
	while(exitFlag == 0){
		option = UIoptions();
		switch (option) {
			case 1:
				f1.readFromFIle();
				f1.printFileContents();
				break;
			case 2:
				writeToFile();
				break;
			case 3:
				cout << "Goodbye! " << endl;
				exitFlag = 1;
				break;
			default:
				break;
		}
	}
	return 0;
}

/* TODO
 - Implement master password.
 - Encrpyt and decrypt the file every time it is opened and closed.
*/
