/*
Diana Rachvak
Description: *File and I/O operations*
             This is a C++ program that allows user to choose the name
             of the input and output files. Then it reads sentences
             from the input file and changes the first letter of the
             sentence to an upper-case letter and the rest to the
             lowercase. It prints modified sentences to an output
             file.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    fstream inFile, toFile;
    string inputFile, outputFile, buffer;
    const int MAX= 300;
    char fromInfile[MAX];

    //user creates an input file
    cout << "Type in the name of the first file that will be used "
            "for input: ";
    getline(cin, inputFile);
    inputFile+=".txt";
    cout<<endl<<"input file name is: "<<inputFile<<endl<<endl;
    inFile.open(inputFile.c_str(), ios::in|ios::app);

    //checks if input file was created
    if (!inFile)
    {
        cout<<"Error opening input file"<<endl;
    }


    //user creates an output file
    cout << "Type in the name of the second file that will be used "
            "for output: ";
    getline(cin, outputFile);
    outputFile+=".txt";
    cout<<endl<<"output file name is: "<<outputFile<<endl<<endl;
    toFile.open(outputFile.c_str(), ios::out);

    //checks if output file was created
    if (!toFile)
    {
        cout<<"Error opening output file"<<endl;
    }

    //prints an input file contents to an output file
    toFile<<"****************************************************"
          <<endl;
    toFile<<"Original sentenses from the input file> "<<inputFile
          <<endl;
    toFile<<"****************************************************"
          <<endl;
    getline(inFile, buffer);
    toFile<<buffer<<endl<<endl;

    inFile.clear();
    inFile.seekg(0,ios::beg);

    toFile<<"*******************"<<endl;
    toFile<<"Modified sentenses:"<<endl;
    toFile<<"*******************"<<endl;

    while(inFile.getline(fromInfile, MAX, '.'))
    {
        fromInfile[0]=toupper(fromInfile[0]);
        toFile<<fromInfile[0];

        int i=1;
        while (fromInfile[i]!='\0')
        {
            fromInfile[i]=tolower(fromInfile[i]);
            toFile<<fromInfile[i];
            i++;
        }
        toFile<<". ";
    }

    toFile.close();
    inFile.close();
    return 0;

}//end main
