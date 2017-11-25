/*
Diana Rachvak
Description: *C-Strings*
             This is a C++ program that allows user to count vovels
             or/and consonants in a sentense. It prints out a menu
             with choices and then calls a series of functions to
             process user's sentense.
             All data for input is taken from a file CStringInput.txt.
             All output goes to a file CString.txt.
*/

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int countVovels(char str[]);
int countConsonants(char str[]);
void printMenu(void);

int main()
{
    const int LENGTH = 101;
    char input[LENGTH], choice;
    int numVovels, numConsonants;
    bool not_done= true;

    ofstream toFile("C:\\Users\\diana_000\\Documents\\C++HWs"
                    "\\AdvancedC++\\CStrings\\CString.txt");

    ifstream inFile("C:\\Users\\diana_000\\Documents\\C++HWs"
                    "\\AdvancedC++\\CStrings\\CStringInput.txt");
    //ifstream inFile("con");

    toFile<<"*****Diana Rachvak*****"<<endl<<endl;

    cout<<"Enter a sentense of not more than "<<LENGTH-1<<" letters: ";

    inFile.getline(input, LENGTH);

    toFile<<">>>You entered: ";
    for (int n=0; input[n]!='\0'; n++)
    {
        toFile<<input[n];
    } toFile<<endl;

    //beginning of the do-while loop
    do{
        cout<<endl<<"Choose an option from the menu of what you"
              " would like to do "<<endl<<"with your sentense."<<endl;

        printMenu();// prints a menu to a user

        inFile>>choice;
        toFile<<endl;

        //switch statement for every possible choice of user's input
        switch(choice)
        {
        case 'A':
        case 'a':
            toFile<<"You chose to count vowels in your sentense."
                  <<endl;
            input[LENGTH] = tolower(input[LENGTH]);
            numVovels = countVovels(input);
            toFile<<"There are "<< numVovels <<" vowels in your "
                    "sentense"<<endl;
            break;
        case 'B':
        case 'b':
            toFile<<"You chose to count consonants in your sentense."
                  <<endl;
            input[LENGTH] = tolower(input[LENGTH]);
            numConsonants = countConsonants(input);
            toFile<<"There are "<< numConsonants <<" consonants "
                    "in your sentense"<<endl;
            break;
        case 'C':
        case 'c':
            toFile<<"You chose to count both vowels and consonants in"
                    " your sentense."<<endl;
            input[LENGTH] = tolower(input[LENGTH]);
            numVovels = countVovels(input);
            numConsonants = countConsonants(input);
            toFile<<"There are "<< numVovels <<" vowels and "
                  <<numConsonants<<" consonants in your sentense"
                  <<endl;
            break;
        case 'D':
        case 'd':
            cout<<"Enter a sentense of not more than "<<LENGTH-1
                <<" letters: ";
            inFile.getline(input, LENGTH);

            toFile<<">>>You entered: ";
            for (int n=0; input[n]!='\0'; n++)
            { toFile<<input[n]; } toFile<<endl;

            break;
        case 'E':
        case 'e':
            toFile<<"You chose to exit. Good bye!"<<endl;
            not_done=false;
            break;
        default:
            toFile<<choice<<" You entered invalid choice."
                  <<" Try again."<<endl<<endl;
        }//end switch statement

    } while(not_done);  //end of the do-while loop


    inFile.close();
    toFile.close();
    return 0;

}//end main

/*
*Function int countVovels()
*Input:
*    str- an array of characters
*Process:
*    compares input array of char with an array of char
*    of vowels and returns a number of vowels in str.
*Output:
*    number of vowels in str
*/
int countVovels(char str[])
{
    char vowels[] = {'a','e','i','o','u','y'};
    int count=0;

    for (int n=0; str[n]!='\0'; n++)
    {
        for (int j=0;  vowels[j]!='\0' ; j++)
            {
                if(str[n]==vowels[j])
                    count++;
            }
    }
    return count;
}

/*
*Function int countConsonants()
*Input:
*    str- an array of characters
*Process:
*    compares input array of char with an array of char
*    of consonants and returns a number of consonants in str.
*Output:
*    number of consonants in str
*/
int countConsonants(char str[])
{
    char consonants[] = {'b','c','d','f','g','h','j','k','l','m','n',
                         'p','q','r','s','t','v','w','x','z','\0'};
    int count=0;

    for (int i=0; str[i]!='\0'; i++)
    {
        for (int j=0; consonants[j]!='\0' ; j++)
            {
                if(str[i]==consonants[j])
                    count++;
            }
    }
    return count;
}

/*
*Function void printMenu()
*Input:
*    none
*Process:
*    prints out the menu choice for a user
*Output:
*    prints out the menu
*/
void printMenu(void)
{
    cout<<endl<<endl;
    cout<< "******************************************************\n";
    cout<< "                          MENU                        \n";
    cout<< "******************************************************\n";
    cout<<"Type in a letter to select an option:"<<endl;
    cout<<"A- Count the number of vovels in the string"<<endl;
    cout<<"B- Count the number of consonants in the string"<<endl;
    cout<<"C- Count both the vovels and the consonants in the string"
        <<endl;
    cout<<"D- Enter another string"<<endl;
    cout<<"E- To exit the program"<<endl;
    cout<<"*********************************************************";
    cout<<endl<<"Your choice: ";

  return;
}
