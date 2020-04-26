//============================================================================
// Name        : writeToFIle.cpp
// Author      : Viope C++ course
// Version     : 1
// Copyright   : Copyright 2020, Djordje Obradovic, All rights reserved.
// Description : Password manager program. Let's user store a list of passwords,
// 				display the list and edit it. The passwords will be stored in a
// 				encrypted text file.
//============================================================================



#include "ReadFile.h"
#include "WritingFiles.h"
using namespace std;

int main() {
	ReadFile f1;
	f1.readFromFIle();
	f1.printFileContents();
	writeToFile();

	return 0;
}

/* TODO
 - Encrpyt and decrypt the file every time it is opened and closed.
 - Provide an ui through command line.
*/
