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

using namespace std;

int main() {

	string word;
	array<string,10> passwords;

	// open passwords.txt for reading
	ifstream read("/home/sdfe/1_Personal_Work/cpp_workspace/PasswordManager/src/passwords.txt");

	// if reading is successful
	if (read.is_open()) {
	// read one string type value from the file
	//read >> words;
	// add it to array of passwords

	int i = 0;
	while (read >> word) {
		cout << "row: " << word << endl;
		passwords[i] = word;
		i++;
	}

	} else {
	cout << "Unable to open the file!" << endl;
	exit(-1);
	}

	// print out the contents of array
	for (unsigned int x = 0; x < passwords.size(); x ++){
		cout << passwords[x] << endl;
	}
	return 0;
}

