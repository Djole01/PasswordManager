#include "encryptionFile.h"
using namespace std;

void encrypt(string fileName)
{
    char ch;
    fstream fps, fpt;
    fps.open(fileName, fstream::in);
    if(!fps)
    {
        cout<<"\nError Occurred, Opening the Source File (to Read)!";
        exit(-1);
    }
    fpt.open("tmp.txt", fstream::out);
    if(!fpt)
    {
        cout<<"\nError Occurred, Opening/Creating the tmp File1!";
        exit(-1);
    }
    while(fps>>noskipws>>ch)
    {
        ch = ch+100;
        fpt<<ch;
    }
    fps.close();
    fpt.close();
    fps.open(fileName, fstream::out);
    if(!fps)
    {
        cout<<"\nError Occurred, Opening the Source File (to write)!";
        exit(-1);
    }
    fpt.open("tmp.txt", fstream::in);
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
    char ch;
    fstream fps, fpt;
    fps.open(fileName, fstream::out);
    if(!fps)
    {
        cout<<"\nError Occurred while Opening the Source File!";
        exit(-1);
    }
    fpt.open("tmp.txt", fstream::in);
    if(!fpt)
    {
        cout<<"\nError Occurred while Opening/Creating tmp File2!";
        exit(-1);
    }
    while(fpt>>noskipws>>ch)
    {
        ch = ch-100;
        fps<<ch;
    }
    fps.close();
    fpt.close();
    cout<<"\nFile '"<<fileName<<"' Decrypted Successfully!";
    cout<<endl;
}
