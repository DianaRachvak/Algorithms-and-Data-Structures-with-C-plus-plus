// Lexicon.cpp

#include "Lexicon.h"
#include <list>
#include <algorithm>
#include <cstring>

//searches a list for a particular word
bool Lexicon::containsWord(const string &word)
{
   list<string>::iterator it;
   for(it=words.begin();it!=words.end();it++)
   {
       if((*it).compare(word) == 0)        //using function compare
           return true;                   //to find a word
   }
   return false;
}

//returns all the words that start with a particular char
list<string> Lexicon::startWith(char ch)
{
   list<string> temp;
   list<string>::iterator it;
   for(it=words.begin();it!=words.end();it++)
   {
       if((*it)[0] == ch)
           temp.push_back(*it);
   }
   return temp;
}

//if a word ends with a requested prefix,
//it returns all the words with this prefix
list<string> Lexicon::startWith(const string &prefix)
{
   list<string> temp;
   std::list<string>::iterator it;
   int len2 = prefix.length();//finding length of a prefix
   int i;
   bool flag = true; //setting a boolean flag

   for(it=words.begin();it!=words.end();it++) //loops through the list
   {
       int len = (*it).length(); //length of a "words" prefix
       flag = true;
       if(len < len2) //until length of input suffix is '>', continue
           continue;
       for(i=0; i<len2; i++) //inner for loop to fing prefix
       {
           if(prefix[i] != (*it)[i]) //finds prefix
           {
               flag = false;
               break;
           }
       }
       if(flag == true)             //if found a word with a suffix-
           temp.push_back(*it);    //adds it to temporary list
   }
   return temp; //returns all found words
}

//returns all the words that end with a particular char
list<string> Lexicon::endWith(char ch)
{
   list<string> temp;
   list<string>::iterator it;

   for(it=words.begin();it!=words.end();it++)
   {
       int len = (*it).length();
       if((*it)[len-1] == ch)
           temp.push_back(*it);
   }
   return temp;
}

//if a word ends with a requested suffix,
//it returns all the words with this suffix
list<string> Lexicon::endWith(const string &suffix)
{
   list<string> temp;
   list<string>::iterator it;
   int len2 = suffix.length(); //defining length of a suffix
   int i;
   bool flag = true; //boolean flag

   for(it=words.begin();it!=words.end();it++) //loops through the list
   {
       int len = (*it).length(); //length of a "words" suffix
       flag = true;
       if(len < len2) //until length of input suffix is '>', continue
           continue;
       for(i=0; i<len2; i++) //inner for loop to fing suffix
       {
           if(suffix[len2-i-1] != (*it)[len-i-1]) //finds suffix
           {
               flag = false;
               break;
           }
       }
       if(flag == true)             //if found a word with a suffix-
           temp.push_back(*it);    //adds it to temporary list
   }
   return temp; //returns all found words
}

//checks if a word exists in the list. if not, adds a word to the list
void Lexicon::addWord(const string &str)
{
    if(containsWord(str)==0);
    else words.push_back(str);
}

//checks if requested word "target" is on the list.
//if it is- replaces "target" with "replacement" word.
void Lexicon::updateWord(const string &target,
                         const string &replacement)
{
   list<string>::iterator it;
   for(it = words.begin(); it != words.end(); it++)
   {
       if((*it)==target)
           *it = replacement;
   }
}

//overloaded operators
//== operator
bool operator == (const Lexicon& d1, const Lexicon& d2)
{
//first creating 2 new lists
list<string> words1;
list<string> words2;

//using a function "copy" to copy contents of 2 lists into new lists
copy(d1.words.begin(), d1.words.end(),
     back_insert_iterator<list<string> >(words1));
copy(d2.words.begin(), d2.words.end(),
     back_insert_iterator<list<string> >(words2));

//sorting new lists
words1.sort();
words2.sort();

//comparing 2 new lists and return true if they are equal
if(words1==words2)
    return true;
else
    return false;
}

//<< operator
//prints out contents of a list
ostream &operator << (ostream& os, const Lexicon& d)
{
     list<string>::const_iterator it;

     for(it= d.words.begin(); it!= d.words.end(); it++)
        os<<*it<<endl;
     return os;
}
