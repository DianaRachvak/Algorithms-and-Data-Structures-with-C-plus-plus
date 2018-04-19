#include <map>
#include <fstream>
#include <iostream>
#include <cctype>
#include <stdlib.h>

using namespace std;

int main(int argc, const char* argv[])
{
    if (argc!=2) exit(1);
    ifstream infile (argv[1]);
    if(!infile) exit(2);

    map<char, int> occurence;
    char ch;

    while(infile>>ch)
    {
        if(isalnum(ch)) occurence[ch]++;

        //occurence[ch]++;   is equivalent to the code below
        /*
         *{
         *   map<char,int>::iterator found;
         *   found = occurence.find(ch);
         *
         *   if(found == occurence.end())
         *       occurence.insert(pair<char,int>(ch,1));
         *   else found-> second++;
         *}
         */
        map<char,int>::const_iterator it;
        for(it = occurence.begin(); it != occurence.end(); it++)
            cout<< it->first <<" : "<< it-> second<<endl;
    }

}
