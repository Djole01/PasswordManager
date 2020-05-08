/*
 * ReadFile.h
 *
 *  Created on: Apr 20, 2020
 *      Author: Djordje
 */

#ifndef READFILE_H_
#define READFILE_H_

#include <string>
using namespace std;

#define ROWLENGTH 10
#define COLUMNLENGTH 3


class ReadFile{
public:
	string credentials[ROWLENGTH][COLUMNLENGTH];	// made separate arrays, not to break things with input
	void readFromFIle();
	void populateCredentials();
	void printFileContents();
private:				// code encapulation
	string portal; // platform/website/app
	string password;
	string username;
	string userInputArray[ROWLENGTH][COLUMNLENGTH];
};

#endif /* READFILE_H_ */
