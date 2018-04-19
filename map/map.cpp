#include <map>
#include <utility>
#include <iostream>

using namespace std;

int main()
{
    map <string, int> personInfo;
    pair <string, int> person ("Diana", 6);
    personInfo.insert(person);
    personInfo. insert(pair <string, int> ("L", 4));
    map <string, int>::iterator found = personInfo.find("L");

    if(found!= personInfo.end())
    {
        cout<<"The key is "<<found->first;
        cout<<" and the value is "<<found->second<<endl;
    }
    else
        cout<<"the key is not in the map"<<endl;

    pair <map<string, int>::iterator, bool> answer;
    answer = personInfo.insert(pair<string,int> ("Maria", 5));

    if(answer.second)
        cout<<answer.first->first<<" not already there"<<endl;

    int value =personInfo["Diana"];
    personInfo["Diana"] = 7;
}
