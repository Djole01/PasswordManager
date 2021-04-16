#include "encryptionFile.h"
#include "myHiddenCharManipulaion.h"
using namespace std;

void encrypt(string fileName)
{
	string tempTxt;
	string pathTempTxt = "/.tmpCrypt.txt";
	tempTxt = getenv("HOME") + pathTempTxt;

    char ch;
    fstream fps, fpt;
    fps.open(fileName, fstream::in);
    if(!fps)
    {
        cout<<"\nError Occurred, Opening the Source File (to Read)!";
        exit(-1);
    }
    fpt.open(tempTxt, fstream::out);
    if(!fpt)
    {
        cout<<"\nError Occurred, Opening/Creating the tmp File1!";
        exit(-1);
    }
    HIDDENROUND1
	/* hidden char manipulation from myHiddenCharManipulaion.h
	 * while(fps>>noskipws>>ch){
	 * ch = ch + x;    // for example
	 * fpt<<ch;
	 * }
	 */
    fps.close();
    fpt.close();



    fps.open(fileName, fstream::in);
    fpt.open(tempTxt, fstream::out);
    HIDDENROUND2
    fps.close();
    fpt.close();



    fps.open(fileName, fstream::out);
    if(!fps)
    {
        cout<<"\nError Occurred, Opening the Source File (to write)!";
        exit(-1);
    }
    fpt.open(tempTxt, fstream::in);
    if(!fpt)
    {
        cout<<"\nError Occurred, Opening the tmp File!";
        exit(-1);
    }
    while(fpt>>noskipws>>ch)
        fps<<ch;
    fps.close();
    fpt.close();
    cout<<"\nFile '"<<fileName<<"' Encrypted Successfully!";
    cout<<endl;
}

void decrypt(string fileName)
{
	string tempTxt;
	string pathTempTxt = "/.tmpCrypt.txt";
	tempTxt = getenv("HOME") + pathTempTxt;

    char ch;
    fstream fps, fpt;

    fps.open(fileName, fstream::out);
    if(!fps)
    {
        cout<<"\nError Occurred while Opening the Source File!";
        exit(-1);
    }
    fpt.open(tempTxt, fstream::in);
    if(!fpt)
    {
        cout<<"\nError Occurred while Opening/Creating tmp File2!";
        exit(-1);
    }
    HIDDENDECRYPT1
    fps.close();
    fpt.close();

    fps.open(fileName, fstream::out);
    fpt.open(tempTxt, fstream::in);
    HIDDENDECRYPT2
    fps.close();
    fpt.close();

    cout<<"\nFile '"<<fileName<<"' Decrypted Successfully!";
    cout<<endl;
}



