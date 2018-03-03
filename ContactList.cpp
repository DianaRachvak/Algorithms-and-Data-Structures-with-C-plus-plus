#include "ContactList.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

//search for a contact by last name
Contact& ContactList::findLastN(string lastName)
{
    for(int count=0; count<vec.size(); count++)
    {
        if(vec[count].getLast()==lastName)
           return vec[count];
    }
    return defaultContact;
}

//search for a contact by phone number
Contact& ContactList::findPhoneN(string phoneNumber)
{
    for(int count=0; count<vec.size(); count++)
    {
        if(vec[count].getPhoneNum()==phoneNumber)
           return vec[count];
    }
    return defaultContact;
}

//search first letter in last name function
vector<Contact> ContactList::findChar(string c)
{
    vector<Contact> tempVec;
    int i=0;
    for(int count=0; count<vec.size(); count++)
    {
        if(vec[count].getLast()==c)
        {
            tempVec[i] = vec[count];
            i++;
        }
    }
    return tempVec;
}

//search contacts living in particular city function
vector<Contact> ContactList::findCity(string findCity)
{
    vector<Contact> tempVec;
    int i=0;
    for(int count=0; count<vec.size(); count++)
    {
        if(vec[count].getCity()==findCity)
        {
            tempVec[i] = vec[count];
            i++;
        }
    }
    return tempVec;
}

//find if account exists
int ContactList::findContact(const Contact& newContact) const
{

    for(int count=0; count<vec.size(); count++)
     {
       if(vec[count] == newContact)
          return count;
     }
    return -1;
}

//allows to add a contact to a ContactList
void ContactList::addContact(Contact newContact)
{
    int index;
    index = findContact(newContact);
    if(index != -1)
    {
       vec.push_back(newContact);
    }

}

//returns the size of a ContactList
int ContactList::contactSize(void) { return vec.size(); }

//erases a contact
void ContactList::eraseContact(const Contact& contact)
{
    int index = findContact(contact);
    if(index==-1) return;
    else
    {
        vec[index] = vec.back();
        vec.pop_back();
    }
    //for(int i=index+1; i<vec.size(); i++)
      //  vec[i-1] = vec[i];
}

//findLast for erase
int ContactList::findLastErase(string lastName) const
{
    for(int count=0; count<vec.size(); count++)
    {
        if(vec[count].getLast()==lastName)
           return count;
    }
    return -1;
}
//overloaded operators
//[] operator
Contact& ContactList:: operator[](int index)
{
    if (index<0 || index >= vec.size())
        throw string ("Error. Index is out of bounds");
    return vec[index];
}

//<< operator
ostream &operator <<(ostream &out, ContactList &c)
{
    for (int i=0; i < c.vec.size(); i++ )
        out<<c.vec[i]<<"\n";

    return out;
}

