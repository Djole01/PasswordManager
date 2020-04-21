#include <iostream>
#include <fstream>
#include "WritingFiles.h"
using namespace std;

void writeToFile()
{
    // creating the file object
    fstream writing;

    // open the file for writing
    writing.open("/home/sdfe/1_Personal_Work/cpp_workspace/PasswordManager/src/passwords.txt" , ios_base::out | ios_base::app);

    if (!writing.is_open()) {
        cout << "Failed to open the file!" << endl;
        exit(-1);
    }

    // file is open, let's move on...
    string row;
    bool input_continues = true;

    cout << "Write your Input in the following order: identifier usename password.\nFinish by pressing 2x[return]." << endl;
    cout << "- - - - - - - - - -" << endl;

    while(input_continues) {

        getline(cin, row); // read the row from keyboard

        if (row.compare("") == 0) { // if row is empty
            // while-loop is false
        	input_continues = false;
        } else { // text written
            // write the row as is to the file
            // note that the line break character was not read
            // to the variable row, so let's add it here
            writing << row << endl;

        }
    }

    writing.close(); // close the file where the rows were stored in.
}
