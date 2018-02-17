/*
Diana Rachvak
Description: *Program "Contacts" using classes, separate
             compilation files, and overloaded operators*
             This is a C++ program that inmplements a contact book
             entry, tests veriety of overloaded operators functions
             and constructors.
*/
#include <iostream>
#include <string>
#include <fstream>
#include "Contact.h"

using namespace std;

int main()
{
    ofstream toFile("con"); //redirects output to a console
    //ofstream toFile("C:\\Users\\diana_000\\Documents\\C++HWs"
    //               "\\AdvancedC++\\DataStructures#1\\DToutput.txt");


    Contact contact1 ("Diana", "Rachvak", "347-890-1234",
                      "2900 Bedford Ave", "Brooklyn", "NY"),
            contact2 ("Kate", "Antipova", "347-123-4567",
                      "3456 5th Ave", "New York", "NY"),
            contact3 ("Kate", "Antipova", "888-987-6543"),
            contact4; //calls a default constructor

    /**********************************************************/

    //testing a constructor that initializes only the name and phone #
    toFile<<endl<<"<Contact #3> \n"<<contact3<<endl;

    /********************************************************/

    //testing == and != operators
    if (contact1 == contact2)
        toFile<<"Contacts' names are the same"<<endl;
    else if (contact1 != contact2)
        toFile<<"Contacts' names are not the same"<<endl;
    else
        toFile<<"there's an error"<<endl;
    toFile<<endl;

    if (contact3 == contact2)
        toFile<<"Contacts' names are the same"<<endl;
    else if (contact3 != contact2)
        toFile<<"Contacts' names are not the same"<<endl;
    else
        toFile<<"there's an error"<<endl;
    toFile<<endl;

    /********************************************************/

    //testing < and > operators
    if (contact1 < contact2)
    {
        toFile<<"Contact name "<<contact1.getLast()<<" is "
              "lexicographically before "<<contact2.getLast()
              <<endl;
    }
    else if(contact1 > contact2)
    {
        toFile<<"Contact name "<<contact1.getLast()<<" is "
              "lexicographically after "<<contact2.getLast()
              <<endl;
    }
    else
        toFile<<"there's an error"<<endl;
    toFile<<endl;

    /*********************************************************/

    //testing << operator
    toFile<<endl<<endl<<"<Contact #1> \n"<<contact1<<endl<<endl;
    toFile<<"<Contact #2> \n"<<contact2<<endl<<endl;

    /*********************************************************/

    // testing an update function void changeAll()
    contact4.changeAll("Pete", "Qr", "917- 098-7654",
                       "123 main st", "Queens", "NY");
    toFile<<"<Contact #4> \n"<<contact4<<endl;

    /**********************************************************/

    toFile.close();
    return 0;
}
