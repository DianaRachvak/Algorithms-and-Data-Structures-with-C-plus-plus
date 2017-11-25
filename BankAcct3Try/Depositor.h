/* Depositor Class Specification */

#ifndef DEPOSITOR_H
#define DEPOSITOR_H

#include <iostream>
#include <string>
#include "Name.h"
using namespace std;

//Depositor class declarations
class Depositor {
    Name name;
    string SSN;
  public:
    // Constructors
    //default constructor
    Depositor()
    { //cout<<"default constructor is running"<<endl;
    }

    //constructor with one parameter
    Depositor(string socialSNum)
    {
        SSN=socialSNum;
    }

    //constructor with 2 parameters
    Depositor(Name clientName, string social)
    {
        name = clientName;
        SSN = social;
    }

    //setters
    void setName(Name);
    void setSSN(string);

    //getters
    Name getName()const;
    string getSSN()const;

};
#endif
