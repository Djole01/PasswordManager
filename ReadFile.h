/*
 * ReadFile.h
 *
 *  Created on: Apr 20, 2020
 *      Author: root
 */

#ifndef READFILE_H_
#define READFILE_H_

#include <string>
using namespace std;

class ReadFile{
public:
	string credentials[10][3];
	void readFromFIle();
	void printFileContents();
private:				// code encapulation
	int rowLength;
	int columnLength;
	string portal; // platform/website/app
	string password;
	string username;
};

#endif /* READFILE_H_ */
