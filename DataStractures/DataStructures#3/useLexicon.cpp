/*
Diana Rachvak
Description: *Program "Lexicon" that maintains a list of words and
              lets a user to perform a variety of functions like
              finding a word in a list, replacind a word, adding a
              word to the list, comparing lists from 2 files, etc.
              Program is written using separate compilation files.
*/

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "Lexicon.h"

using namespace std;

int main()
{
    ifstream inFile1("C:\\Users\\diana_000\\Documents\\C++HWs\\"
                    "AdvancedC++\\DataStractures\\DataStructures#3\\"
                    "lexicon1.txt");
    ifstream inFile2("C:\\Users\\diana_000\\Documents\\C++HWs\\"
                    "AdvancedC++\\DataStractures\\DataStructures#3\\"
                    "lexicon2.txt");

    Lexicon list1("lexicon1.txt"), list2("lexicon2.txt");

    //trying  containsWord() function
    string word;
    cout<<"Enter a word to find in a list: ";
    cin>>word;
    if(list1.containsWord(word)==0)
        cout<<"word is not on the list"<<endl;
    else
        cout<<"word "<<word<<" is on the list"<<endl;
    cout<<endl<<endl;

    //trying  startWith() function for a particular char
    char c;
    list<string> startC;
    list<string>:: iterator iter;
    cout<<"Enter a char to find all the words in a list that start "
          "with this char: ";
    cin>>c;
    startC = list1.startWith(c);
    for(iter = startC.begin(); iter != startC.end(); iter++)
    {
       cout<<*iter<<endl;
    }
    cout<<endl<<endl;

    //trying  startWith() function for a particular prefix
    string prefix;
    list<string> startP;
    list<string>:: iterator iter1;
    cout<<"Enter a prefix to find all the words in a list that start "
          "with this prefix: ";
    cin>>prefix;
    startP = list1.startWith(prefix);
    for(iter1 = startP.begin(); iter1 != startP.end(); iter1++)
    {
       cout<<*iter1<<endl;
    }
    cout<<endl<<endl;

    //trying  endWith() function for a particular char
    list<string> endC;
    list<string>:: iterator iter2;
    cout<<"Enter a char to find all the words in a list that end "
          "with this char: ";
    cin>>c;
    endC = list1.endWith(c);
    for(iter2 = endC.begin(); iter2 != endC.end(); iter2++)
    {
       cout<<*iter2<<endl;
    }
    cout<<endl<<endl;

    //trying  endWith() function for a particular suffix
    string suffix;
    list<string> endS;
    list<string>:: iterator iter3;
    cout<<"Enter a suffix to find all the words in a list that end "
          "with this suffix: ";
    cin>>suffix;
    endS = list1.endWith(suffix);
    for(iter3 = endS.begin(); iter3 != endS.end(); iter3++)
    {
       cout<<*iter3<<endl;
    }
    cout<<endl<<endl;

    //trying  addWord function
    string newWord;
    cout<<"Enter a new word to add to the list: ";
    cin>>newWord;
    list1.addWord(newWord);
    list2.addWord(newWord);
    cout<<endl<<endl;

    //trying  updateWord function
    string toChange, newChanged;
    cout<<"Enter a word you want to change: ";
    cin>>toChange;
    cout<<endl;
    cout<<"Enter a new word you want to change an old one with: ";
    cin>>newChanged;
    list1.updateWord(toChange, newChanged);
    list2.updateWord(toChange, newChanged);

    //checking the == operator
    if(list1 == list2)
        cout<<"List 1 and List 2 are EQUAL"<<endl<<endl;
    else
        cout<<"List 1 and List 2 are NOT equal"<<endl<<endl;

    //checking the << operator
    cout<<"LIST 1: \n"<<list1<<endl;

    inFile1.close();
    inFile2.close();
    return 0;
}
