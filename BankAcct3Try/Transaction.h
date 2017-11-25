/* Class Transaction Specification */

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
using namespace std;

class Transaction{
    string transType;
    double transAmount;
public:
    //default constractor
    Transaction (){}

    Transaction (string transType1, double transAmount1)
    {  transType= transType1;
       transAmount= transAmount1; }

//setters
void setTransType(string tType);
void setTransAmount(double tAmount);

//getters
string getTransType()const;
double getTransAmount()const;

};
#endif
