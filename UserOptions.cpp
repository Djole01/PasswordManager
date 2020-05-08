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
	cout << "1. See list of saved credentials " << endl;
	cout << "2. Enter new credentials " << endl;
	cout << "3. Exit program " << endl;

	cin >> option;
	cin.ignore();
	return option;
}

