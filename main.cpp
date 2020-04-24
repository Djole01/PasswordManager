//============================================================================
// Name        : writeToFIle.cpp
// Author      : Viope C++ course
// Version     :
// Copyright   : Your copyright notice
// Description : Writing to a file in C++
//============================================================================

#include <iostream>
#include <string>
#include <array>
#include <fstream>
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
