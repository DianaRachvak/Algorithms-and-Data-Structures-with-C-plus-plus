/* Account Class Implementation */

#include "Account.h"
#include <string>
using namespace std;

//retrieves the value of member variable depositor
Depositor Account::getDepositor()const
{ return(depositor); }

//retrieves the value of member variable acctNumber
int Account::getAccountNumber()const
{ return(acctNumber); }

//retrieves the value of member variable acctType
string Account::getAccountType()const
{ return(acctType); }

//retrieves the value of member variable balance
double Account::getBalance()const
{ return(balance); }

//retrieves the value of member variable status
string Account::getAcctStatus()const
{ return acctStatus; }

//retrieves the value of member variable numTrans
int Account::getNumTrans()const
{ return numTrans; }

//sets the value member variable acctNum
bool Account::setAcctNum(int acctNum)
{ acctNumber = acctNum;
    return true; }

//adds added amount to deposit variable
void Account::makeDeposit(double amount)
{ balance+=amount; }

//subtracts desired amount from a variable
void Account::makeWithdrawal(double amount)
{ balance-=amount; }

//retrieves the value of member variable transaction
Transaction Account::getTransaction(int index)const
{ return transaction[index]; }

//add new transaction to an account
void Account::addNewTransaction(Transaction add_trans)
{
    transaction[numTrans]=add_trans;
    numTrans++;
}

//sets the value member variable acctStatus
void Account::setAcctStatus(string newStatus)
{ acctStatus = newStatus; }
