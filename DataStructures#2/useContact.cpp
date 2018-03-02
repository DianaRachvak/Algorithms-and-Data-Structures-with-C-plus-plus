/*
Diana Rachvak
Description: *Program "ContactList" using classes, separate
             compilation files, and overloaded operators*
             This is a C++ program that inmplements a contact book
             entry, tests veriety of overloaded operators functions
             and constructors, uses vector.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Contact.h"
#include "ContactList.h"

using namespace std;

int main()
{
    ofstream toFile("con"); //redirects output to a console
    //ofstream toFile("C:\\Users\\diana_000\\Documents\\C++HWs"
    //               "\\AdvancedC++\\DataStructures#1\\DToutput.txt");

    //string findLast, findPhone, findAllLast, findCity;

    int const MAX= 10;
    ContactList userContact[MAX];

    userContact[0].addContact(Contact("Diana", "Rachvak", "347-890-1234",
                 "2900 Bedford Ave", "Brooklyn", "NY"));
    userContact[1].addContact(Contact("Kate", "Antipova", "347-123-4567",
                 "3456 5th Ave", "New York", "NY"));
    userContact[2].addContact(Contact("Kate", "Antipova","888-987-6543"));
    userContact[3].addContact(Contact()); //calls a default constructor



    //testing find a contact by last name function
    string userLast;
    cout<<"Enter a last name of a contact you want to find: ";
    cin>>userLast;
    toFile<<userContact->findLastN(userLast)<<endl<<endl;

    //testing find a contact by phone number function
    string userPhone;
    cout<<"Enter a phone number of a contact you want to find: ";
    cin>>userPhone;
    toFile<<userContact->findPhoneN(userPhone)<<endl<<endl;

    //testing a function that returns of all contacts containing
    //the same last name starting with a particular letter
    string userLetter;
    cout<<"Enter the first letter of a contact's last name "
          "you want to find: ";
    cin>>userLetter;
    userContact->findChar(userLetter);

    //testing a function that returns all the contacts living in a
    //particular city
    string userCity;
    cout<<"Enter a city to display all the contacts living there: ";
    cin>>userCity;
    userContact->findCity(userCity);

    //testing a function that allows to add a new contact
    string userFirst, userAddress, userState;
    cout<<"Enter new contacts info. \n Enter first name: ";
    cin>>userFirst;
    cout<<"\nEnter last name: ";
    cin>>userLast;
    cout<<"\nEnter phone number: ";
    cin>>userPhone;
    cout<<"\nEnter address: ";
    cin>>userAddress;
    cout<<"\nEnter city: ";
    cin>>userCity;
    cout<<"\nEnter state: ";
    cin>>userState;
    cout<<endl<<endl;

    userContact[4].addContact(Contact(userFirst, userLast, userPhone,
                 userAddress, userCity, userState));

    //testing a function that deletes a contact
    cout<<"Enter a number of a contact you wish to delete: ";
    userContact->eraseContact(Contact("Kate", "Antipova",
                                      "888-987-6543"));
    toFile.close();
    return 0;
}
