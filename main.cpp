#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main()
{
    char fileName[38];
    char ch;
    fstream fps;
    fstream fpt;

    cout<<"Enter the Name, Location and Extension of File: ";
    gets(fileName);
    fps.open(fileName,fstream::in);
    if(!fps)
    {
        cout<<"\nError Occurred, opening the source file, to read!";
        return 0;
    }
    fpt.open("tmp.txt,fstream::in");;
    if(!fpt)
    {
            cout<<"\nError occurred, oppening/creating the tmp file!";
            return 0;
    }
    while(fps>>noskipws>>ch)
    {
        ch=ch+100;
        fpt<<ch;
    }

    fps.close();
    fpt.close();
    fps.open(fileName, fstream::out);
    if(!fps)
    {
        cout<<"\nError occurred, opening the sources file, to write!";
        return 0;
    }
    fpt.open("tmp.txt,fstream::in");
    if(!fpt)
    {
        cout<<"\nError Occured, opening the tmp file!";
        return 0;
    }

    while(fpt>>noskipws>>ch)
    {
        fps<<ch;
    }

    fps.close();
    fpt.close();
    cout<<"\nFile '<<fileName<<' has been encrypted";
    cout<<endl;
    return 0;
}


//BRO WAIT TO FIGURE OUT THE ERROR!