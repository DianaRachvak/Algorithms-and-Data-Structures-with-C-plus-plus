//entry class file

#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <utility>
#include <iostream>

using namespace std;

//Entry class will store a key and a value
//implementing an Entry class as a subclass of the STL pair
class Entry : public pair<string,int> {
public:
    //constructor
    Entry (const string& key, int value = 0):
           pair<string,int>(key,value){}
    string getKey() { return first;} //returns a key from a map
    int& getValue() { return second; } //returns a value of a key
    void setValue(int value) { second = value;} //sets a value
};
#endif

