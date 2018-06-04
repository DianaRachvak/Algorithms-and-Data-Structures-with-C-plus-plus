//myMap.cpp file

#include "MyMap.h"
#include <vector>

//hash function that takes a string and transforms it into an integer
int MyMap::hashF(const string& key)const{
    int total;
    for (int i=0; i<key.size(); i++)
        total+=key[i];
    return total;
}

//associating a key with an index in hash table
int MyMap::resized(const string& forHash){
    int toResize = hashF(forHash);
    return toResize % table.size();
}

//inserts given key-value pair into the map.
//if key already exists in the map, changes its value to "value",
//overwriting what was there
//if key is not in the map, inserts this key-value pair into the map
void MyMap::insertK(const string& key, int value){
    //associating a key with an index in hash table
    int mod = resized(key);

    //creating a new pair to be added into a map
    Entry newEntry(key, value);

    //check if key is already in a map
    if (!containsKey(key))
        table[mod].push_back(newEntry);//adds a pair if it's not there
    else{
        for(list<Entry>::iterator it = table[mod].begin();
            it!=table[mod].end(); it++){
                if(it->getKey()==key) //if value is in a map
                    it->getValue()=value; //changes value of a pair
                }
    }
}

//returns true iff key already exists in the map
bool MyMap::containsKey (const string& key){
    //associating a key with an index in hash table
    int mod = resized(key);
    //iterating through the list to see if it contains requested key
    for (list<Entry>::iterator it = table[mod].begin();
         it!= table[mod].end(); it++){
            if(it->getKey()==key) return true;
    }
    return false;
}

//returns true iff value appears in the map
bool MyMap:: containsValue (int value){
   //iterating through the whole table looking for an associated value
    for(int i=0; i<table.size();i++){
    //iterating through the list to see if it contains requested value
        for (list<Entry>::iterator it = table[i].begin();
             it!= table[i].end(); it++){
                if(it->getValue()==value) return true;
        }
    }
    return false;
}

//checks if key is in the map and removes the pair that contains
//this key
void MyMap::eraseK (const string& key){
    //associating a key with an index in hash table
    int mod = resized(key);
    //iterating through the list to see if it contains requested key
    for(list<Entry>::iterator it = table[mod].begin();
        it!=table[mod].end(); it++){
            if(it-> getKey()==key) //if the key is found- erase it
                table[mod].erase(it++);
    }
}

//checks if key is in the map and returns its associated value
//if key is not found- throws an exception
int MyMap::getValueOf (const string& key){
    //associating a key with an index in hash table
    int mod = resized(key);
    //first checks if key is the table
    if(!containsKey(key))
        throw string("Key is not in the table");
    else{
      //iterating through the list to see if it contains requested key
        for (list<Entry>::iterator it = table[mod].begin();
             it!=table[mod].end(); it++){
                if(it->getKey()==key)
                     return it->getValue();
        }
    }
}
//checks if key is in the map and returns a reference to its
//associated value. if key is not found- inserts a key with value 0
//and returns a reference to the newly created value
int& MyMap::operator[](const string& key){
    //associating a key with an index in hash table
    int mod = resized(key);
    //first checks if the key is the table
    if(!containsKey(key)){
        insertK(key, 0);
        return table[mod].back().getValue();//returns created value
    }
    else{
      //iterating through the list to see if it contains requested key
        for (list<Entry>::iterator it = table[mod].begin();
             it!=table[mod].end(); it++){
                if(it->getKey()==key) //if the key is there
                     return it->getValue(); //returns its value
        }
    }
}

int MyMap::sizeT() { return table.size(); } //returns # of el in a map
bool MyMap::emptyT() { return table.empty(); }//checks if map is empty
