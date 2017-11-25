/* Class Bank Specification */

#ifndef BANK_H
#define BANK_H

#include <iostream>
#include "Account.h"
#include "Depositor.h"

using namespace std;
const int MAX_NUM=40;

//Bank class declarations
class Bank {
    Account * account[MAX_NUM];
    int numOfAccts;
  public:
    // default constructor
    Bank ()
    {
        numOfAccts=0 ;
    }

    //Destructor
    ~Bank()
    {
        while(numOfAccts > 0)
        {
            numOfAccts--;
            delete account[numOfAccts];
            account[numOfAccts] = NULL;
        }
    }

    // mutators (or setter member functions)
    void deleteAcctNumb(int index);
    int findAccount(int)const;
    int findSSN(string)const;
    void addAcctNumb(Depositor, int, string, double, string);

    // accessors (or getter member functions)
    Account* getAccount(int index) const;
    const int getNumOfAccts()const;
    void setNewTrans(Transaction trans, int index);
    Transaction printTrans (int index, int)const;

};
#endif
