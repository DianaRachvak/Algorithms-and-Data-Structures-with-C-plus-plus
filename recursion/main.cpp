/*
Diana Rachvak
Description: *Resursion and string reverser*
             This is a C++ program that recursively processes
             a function void sign() and recursively reverses user's
             string using a function void reverseStr().
             All output goes to the file recursionOutput.txt.
*/

#include <iostream>
#include <fstream>
using namespace std;

//functions prototypes
void sign (int n, ofstream & toFile1);
void reverseStr (string str, int n, ofstream & toFile2);

//start main
int main()
{
    ofstream toFile("recursionOutput.txt");
    //ofstream toFile("con");

    toFile<<endl<<"******Diana Rachvak******"<<endl<<endl;

    /***********************part 1**************************/

    toFile<<"****************part 1******************"<<endl;
    //processes number recursively
    sign(3, toFile);
    toFile<<endl<<endl;

    /***********************part 2**************************/

    string userString;

    toFile<<endl<<endl;
    toFile<<"***************part 2*******************"<<endl;

    cout<<" Enter a string you want to be printed in reverse: ";
    getline(cin, userString);
    toFile<<endl<<"you entered: "<<userString<<endl;
    toFile<<"in reverse: ";
    //prints a string in reverse
    reverseStr(userString, userString.length()-1, toFile);


    //repeat the process
    cout<<" Enter a string you want to be printed in reverse: ";
    getline(cin, userString);
    toFile<<endl<<"you entered: "<<userString<<endl;
    toFile<<"in reverse: ";
    //prints a string in reverse again
    reverseStr(userString, userString.length()-1, toFile);

    return 0;
}

/*
*Function void sign()
*Input:
*    n- integer to be used in recursion funsction
*    toFile1- reference to an output file
*Process:
*    recursive function that prints out "No parking" until n reaches 0
*Output:
*    prints out "No parking" until n reaches 0
*/
void sign(int n, ofstream & toFile1)
{
    toFile1<<"parking #: "<<n<<endl;

    if (n>0)
    {
        toFile1<<" No parking\n\n"; n--;
        sign(n , toFile1);
    }
    toFile1<<"parking #: "<<n<<" is returning"<<endl;
}

/*
*Function void reverseStr()
*Input:
*    str- string to be printed in reverse order
*    n- integer to be used in recursion funsction
*    toFile1- reference to an output file
*Process:
*    prints a string str in reverse order recursively
*Output:
*    prints a string str in reverse order
*/
void reverseStr (string str, int n, ofstream & toFile2)
{
    if(n<0)
        toFile2<<endl;
    else
    {
        toFile2<<str[n];
        reverseStr(str, n-1, toFile2);
    }
}
