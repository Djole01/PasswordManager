/*
 * UserOptions.cpp
 *
 *  Created on: May 8, 2020
 *      Author: root
 */

#include <iostream>

using namespace std;


int UIoptions(){

	int option;
	cout << "Choose an option from below: " << endl;
	cout << "  |  1. List  |";
	cout << "  2. Enter new  |";
	cout << "  3. Edit  |";
	cout << "  4. Exit  |";

	cin >> option;
	if(cin.fail()){
		cin.clear();
		cin.ignore();
	}
	cin.ignore();
	return option;
}
