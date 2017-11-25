/* Class Bank Implementationation */

#include "Bank.h"
#include <string>
using namespace std;

/*
*Function int findAccount()
*Input:
*    requested_account- account number to be find
*Process:
*    finds index of an account in bank accounts' database
*Output:
*    returns the index of an account
*/
int Bank::findAccount(int requested_acct) const
{
  for(int count=0; count<numOfAccts; count++)
     {
       if(account[count]->getAccountNumber()==requested_acct)
         return count;
     }
  return -1;
}

/*
*Function int findSSN()
*Input:
*    requested_SSN- social security number to be find
*Process:
*    finds index of a SSN in bank accounts' database
*Output:
*    returns the index of SSN
*/
int Bank::findSSN(string requested_SSN)const
{
   Depositor depositor;
   for(int count=0; count<numOfAccts; count++)
    {
       if(account[count]->getDepositor().getSSN()==requested_SSN)
          return count;
          //depositor.getSSN()
    }
  return -1;
}
//adds account to database and keeps track of the number of accounts
void Bank::addAcctNumb(Depositor depositor, int acctNumber,
                     string acctType,double balance,string acctStatus)
{
    account[numOfAccts]= new Account(depositor, acctNumber, acctType,
                                     balance, acctStatus);
    numOfAccts++;
}

//deletes an account from database
void Bank::deleteAcctNumb(int index)
{
    account[index]= account[numOfAccts-1];
    numOfAccts--;
}

// getter member functions
//retrieves the value of member variable index
Account* Bank::getAccount(int index) const
{ return (account[index]); }

//retrieves the value of member variable numOfAccts
const int Bank::getNumOfAccts()const
{ return (numOfAccts); }

//ads a transaction to an account
void Bank::setNewTrans(Transaction trans, int index)
{ account[index]->addNewTransaction(trans); }

//used to print transactions for an account
Transaction Bank::printTrans (int index, int index2)const
{ return account[index]->getTransaction(index2); }
