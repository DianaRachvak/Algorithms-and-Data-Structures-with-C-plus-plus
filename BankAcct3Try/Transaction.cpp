/* Class Transaction Implementation */

#include "Transaction.h"
#include <string>
using namespace std;

//setters
//sets the value member variable transType
void Transaction::setTransType(string tType)
{ transType= tType; }

//sets the value member variable transAmount
void Transaction::setTransAmount(double tAmount)
{ transAmount= tAmount; }

//getters
//retrieves the value member variable transType
string Transaction::getTransType()const
{ return transType; }

//retriebes the value member variable transAmount
double Transaction::getTransAmount()const
{ return transAmount; }

