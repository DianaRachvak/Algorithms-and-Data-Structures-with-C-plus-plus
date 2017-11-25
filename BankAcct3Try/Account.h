/* Account Class Specification */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include "Depositor.h"
#include "Transaction.h"
using namespace std;

const int MAX_TRANS=100;

//Name class declarations
class Account {
    Depositor depositor;
    int acctNumber;
    string acctType;
    string acctStatus;
    double balance;
    Transaction transaction[MAX_TRANS];
    int numTrans;
  public:

  //default constructor
  Account(){ numTrans = 0; }

  //constructor for transaction class
  Account(Transaction trans1[])
  {
      transaction[MAX_TRANS]=trans1[MAX_TRANS];
  }

    //constructor with 5 parameters
    Account(Depositor depos, int acctNum, string type,
            double bal, string status)
    {
        depositor= depos;
        acctNumber=acctNum;
        acctType= type;
        balance= bal;
        acctStatus= status;
    }

    //getters
    Depositor getDepositor()const;
    int getAccountNumber()const;
    string getAccountType()const;
    string getAcctStatus()const;
    double getBalance()const;
    Transaction getTransaction(int index)const;
    int getNumTrans()const;

    //setters
    bool setAcctNum(int acctNum);
    void makeDeposit(double);
    void makeWithdrawal(double);
    void addNewTransaction(Transaction add_trans);
    void setAcctStatus (string);
 };
#endif
