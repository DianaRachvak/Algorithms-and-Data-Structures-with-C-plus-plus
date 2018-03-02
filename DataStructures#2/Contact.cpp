//Contact.cpp
#include "Contact.h"
#include <iostream>
#include <string>

//operator <<
ostream &operator << (ostream &out, Contact &a)
{
    out<<a.getFirst()<<" "<<a.getLast()<<"      Phone number: "
       <<a.getPhoneNum()<<endl;
    out<<a.getAddress()<<endl;
    out<<a.getCity()<<", "<<a.getState()<<endl;

    return out;
}

//operator ==
bool operator == (const Contact& left, const Contact& right)
{
    return left.first == right.first && left.last == right.last;
}

//operator !=
bool operator != (const Contact& left, const Contact& right)
{
    return left.first != right.first || left.last != right.last;
}

//operator >
bool operator > (Contact& left, Contact& right)
{
    return !(left==right || left < right);
}
//operator <
bool operator < (Contact& left, Contact& right)
{
    if (left.last < right.last)
        return true;
    else if(left.last==right.last && left.first < right.first)
        return true;
    else
        return false;
}

//setter
void Contact::changeAll(string firstF, string lastL, string phoneP,
               string addressA, string cityC, string stateS)
{
     first= firstF;
     last= lastL;
     phoneNum = phoneP;
     address = addressA;
     city = cityC;
     state = stateS;
}

//getters
string Contact::getFirst() const { return first; }
string Contact::getLast() const { return last; }
string Contact::getPhoneNum() const { return phoneNum; }
string Contact::getAddress() const { return address; }
string Contact::getCity() const { return city; }
string Contact::getState() const { return state; }
