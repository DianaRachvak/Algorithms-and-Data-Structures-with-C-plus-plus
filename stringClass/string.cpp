#include "string.h"
#include <cstring>
#include <cstdlib>
using namespace std;


ostream & operator<<(ostream &os, const String &s) {
    for (int i = 0 ; i < s.len ; i++)
      os << s.cs[i];
    return os;
}
bool operator==(const String &s1, const String &s2) {
    if(s1.length() != s2.length())
        return false;

    for(int i = 0; i < s1.length(); i++)
    {
        if(s1.cs[i] != s2.cs[i])
            return false;
    }
    return true;
}

String operator +(const String &s1, const String &s2) {
    return String(s1) += s2;
}

//constructor to initialize this->cs member with a C-string constant
String::String(const char * cs){
   len = strlen(cs);
   this->cs = new char[len+1];
   strcpy(this->cs, cs);
}

//copy constructor
String::String(const String &s){
    cs = new char[s.len+1];
    strcpy(cs, s.cs);
    len = s.len;
}

//destructor
String::~String() {
    if(len > 0)
        delete[] cs;
}

String& String::operator =(const String &s) {
    if (cs != 0) delete [] cs;

    cs = new char[s.len + 1];
    strcpy(cs, s.cs);
    len = s.len;
    return *this;
}

char& String::operator[] (int index) {
    if(index >= len) throw 1;
    return cs[index];
}

String& String::operator += (const String &s) {
    char* temp = cs;
    cs = new char[len + s.len + 1];
    strcpy(cs, temp);
    strcat(cs, s.cs);

    if(len != 0) delete [] temp;
    len += s.len;
    return *this;
}

//it returns first position of 'c' appearing in 'cs'
int String::find(char c) const{
    char* index;
    index = strchr(cs, c);

    return (index-cs+1);
}

int String::length() const {
    return len;
}

void String::clear() {
    while(len != 0) delete [] cs;
}










