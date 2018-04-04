//specification file Lexicon.h

#ifndef LEXICON_H
#define LEXICON_H
#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

class Lexicon {
    list<string> words;

public:
    //default constructor
    Lexicon(){};

    //constructor that open a file and stores all the words in "words"
    Lexicon(const string& fileName)
    {
        ifstream file;
        file.open(fileName.c_str());
        if(!file) { throw string("Error! File was not found");}

        string word;
        while (!file.eof())
        {
            while(getline(file,word))
                words.push_back(word);
        }
    }

    //member functions
    bool containsWord(const string& word);
    list <string> startWith(char ch);
    list <string> startWith(const string& prefix);
    list <string> endWith(char ch);
    list <string> endWith(const string& suffix);
    void addWord(const string& str);
    void updateWord(const string& target, const string& replacement);

    //overloaded operators
    friend bool operator == (const Lexicon& d1, const Lexicon& d2);
    friend ostream &operator << (ostream& os, const Lexicon& d);
};
#endif
