#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    list<string> words;
    words.push_back("one");
    words.push_back("two");
    words.push_back("three");
    words.push_back("four");
    words.push_back("five");

    list<string> words1;
    list<string> words2;
    list<string>::iterator iter1;
    list<string>::iterator iter2;

    copy(words.begin(), words.end(),
         back_insert_iterator<list<string> >(words1));
    copy(words.begin(), words.end(),
         back_insert_iterator<list<string> >(words2));

    words1.sort();
    words2.sort();

    for(iter1=words1.begin(); iter1!= words1.end();iter1++)
        cout<<*iter1<<" ";
    cout<<endl;

    for(iter2=words2.begin(); iter2!= words2.end();iter2++)
        cout<<*iter2<<" ";
    cout<<endl;

    string word;
    cout<<"enter a word: ";
    cin>>word;
    list<string>::iterator it;
   for(it=words1.begin();it!=words1.end();it++)
   {
       if((*it).compare(word) == 0)
           cout<<"found a word!!"<<endl;
   }


    if(words1==words2)
        cout<<"they are alike"<<endl;
    else
        cout<<"they are NOT alike"<<endl;

    return 0;
}
