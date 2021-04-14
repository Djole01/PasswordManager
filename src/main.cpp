//============================================================================
// Name        : writeToFIle.cpp
// Author      : Djordje
// Version     : 1
// Description : Password manager program. Let's user store a list of passwords,
// 				display the list and edit it. The passwords will be stored in a
// 				encrypted text file.
//============================================================================

#include <iostream>

#include "UserOptions.h"
#include "ReadFile.h"
#include "WritingFiles.h"
#include "MasterPassword.h"
#include "encryptionFile.h"

using namespace std;

int main() {
	ReadFile f1;
	string pwFile;
	pwFile = "passwords.txt";
	int option, exitFlag;

	readFromFIleMaster();
	if(FileExists(pwFile)){
		decrypt(pwFile);
	}
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
	encrypt(pwFile);
	return 0;
}

/* TODO
 - better encryption algo, and hide it from source files
 - make pw files not writable
*/
