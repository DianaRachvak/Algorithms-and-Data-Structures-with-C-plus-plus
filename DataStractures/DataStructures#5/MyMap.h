//MyMap.h file

#ifndef MYMAP_H
#define MYMAP_H
#include "Entry.h"
#include <map>
#include <utility>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class MyMap{
    int vSize;
    vector<list<Entry> > table;
public:
    //MyMap constructor
    MyMap (int vSize = 0):table(vSize){};
    void insertK (const string& key, int value);
    bool containsKey (const string& key);
    bool containsValue(int value);
    void eraseK(const string& key);
    int getValueOf(const string& key);
    int& operator[](const string& key);
    int sizeT();
    bool emptyT();
    int hashF(const string& key)const; //hash function
    int resized(const string& fromHash);
};
#endif
