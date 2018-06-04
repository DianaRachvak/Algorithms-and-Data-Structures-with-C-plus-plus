/*
 * Diana Rachvak
 * Description: *Program "MyMap"*
 *               This is a C++ program that inmplements a map data
 *               structure using a hash table.
 */

#include "MyMap.h"
#include "Entry.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    MyMap useMap(10);
    useMap.insertK("Diana", 6);
    useMap.insertK("Rachvak", 7);
    useMap.insertK("Data Structures", 3);
    useMap.insertK("Brooklyn College", 2);

    //checks if a map contains a key
    if(useMap.containsKey("Rachvak"))
        cout<<"Map contains this key"<<endl;
    else
        cout<<"Map doesn't contain this key"<<endl;

    //checks if a map is empty
    if(useMap.emptyT()!=0)
        cout<<"Map is not empty"<<endl;
    else
        cout<<"Map is empty"<<endl;

    //checks the size of the map
    int s= useMap.sizeT();
    cout<<"Size of a map: "<<s<<endl;

    //checks if a map contains a value
    if(useMap.containsValue(4))
        cout<<"Map has this value"<<endl;
    else
        cout<<"Map doesn't have this value"<<endl;

    //checks erase function
    useMap.eraseK("Rachvak");

    cout<<"After deletion: ";
    if(useMap.containsKey("Rachvak"))
        cout<<"Map contains this key"<<endl;
    else
        cout<<"Map doesn't contain this key"<<endl;

    //checks [] operator
    int brackets = useMap["Data Structures"];
    cout<<"Key with a value of: "<<brackets<<endl;

    //checks if the key is in the map and returns it
    useMap["Diana"]=1;
    cout<<"Value in a map: "<<useMap.getValueOf("Diana")<<endl;
    cout<<"New value in a map: "<<useMap["K"]<<endl;
}
