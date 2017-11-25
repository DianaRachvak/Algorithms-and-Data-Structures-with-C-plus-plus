/* Depositor Class Implementation */
/* Depositor.cpp*/

#include "Depositor.h"
#include <string>
using namespace std;

//sets the value member variable d_name
void Depositor::setName(Name d_name)
{
   name=d_name;
}

//sets the value member variable social
void Depositor::setSSN(string social)
{
   SSN= social;
}

//retrieves the value of member variable name
Name Depositor::getName()const
{
   return(name);
}

//retrieves the value of member variable SSN
string Depositor::getSSN()const
{
   return(SSN);
}

