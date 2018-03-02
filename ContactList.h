//ContactList.h
#ifndef CONTACTList_H
#define CONTACTList_H

#include "Contact.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ContactList {
    vector <Contact> vec;
    Contact defaultContact;
public:
    //constructor that creates empty ContactList
    ContactList() : vec(), defaultContact(){}

    //constructor with 2 parameters
    ContactList(Contact* contacts, int numContacts):
                vec(contacts, contacts+numContacts), defaultContact()
    {
    }
    //search for a contact by last name
    Contact& findLastN(string lastName) ;

    //search for a contact by phone number
    Contact& findPhoneN(string phoneNumber) ;

    //search first letter in last name function
    vector<Contact> findChar(string c);

    //search contacts living in particular city function
    vector<Contact> findCity(string findCity);

    //find if account exists
    int findContact(const Contact& newContact) const;

    //allows to add a contact to a ContactList
    void addContact(Contact newContact);

    //returns the size of a ContactList
    int contactSize(void);

    //erases a contact
    void eraseContact(const Contact& contact);

    //find last for erase
    int findLastErase(string lastName) const;

    //overloaded operators
    Contact &operator [] (int index);
    friend ostream &operator << (ostream &out, ContactList &c);

};
#endif
