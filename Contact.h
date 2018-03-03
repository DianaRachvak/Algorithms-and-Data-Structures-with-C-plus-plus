//Contact.h
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
using namespace std;

class Contact {
    string first;
    string last;
    string phoneNum;
    string address;
    string city;
    string state;

public:
    //default constractor, initializes all the values
    //to an empty string
    Contact ()
    { first = " "; last = " "; phoneNum = " "; address = " ";
      city = " "; state = " ";
    }

    //constructor with 6 parameters
    Contact (string firstC, string lastC, string phoneNumC,
             string addressC, string cityC, string stateC)
    {
         first= firstC;
         last= lastC;
         phoneNum = phoneNumC;
         address = addressC;
         city = cityC;
         state = stateC;
    }

    //constructor that initializes only the name and the phone number
    Contact (string firstName, string lastName, string phoneNumber)
    {
        first = firstName;
        last = lastName;
        phoneNum = phoneNumber;
    }

    //overloaded operators
    friend bool operator == (const Contact& left, const Contact& right);
    friend bool operator != (const Contact& left, const Contact& right);
    friend bool operator < (Contact& left, Contact& right);
    friend bool operator > (Contact& left, Contact& right);
    friend ostream &operator << (ostream &out, Contact &a);

    //setter
    void changeAll(string, string, string, string, string, string);

    //getters
    string getFirst() const;
    string getLast() const;
    string getPhoneNum() const;
    string getAddress() const;
    string getCity() const;
    string getState() const;
};
#endif
