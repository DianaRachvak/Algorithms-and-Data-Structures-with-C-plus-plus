/*
Diana Rachvak
Description: *Bank accounts program using classes, separate
             compilation files,pointers and dynamic memory allocation*
             This is a C++ program that allows user to perform
             simple ATM transactions. It prints out a menu
             with choice of transactions then calls a series
             of functions to perform these transactions.
             All data for input is taken from a file BAinput.txt and
             BAinput2.txt. All output goes to a file BAoutput3.txt.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Bank.h"

using namespace std;

//all functions prototypes
void printMenu(void);
void pause(void);
void read_accts(Bank &bank, ifstream&);
void print_accts(const Bank &bank, ofstream&);
void balance(const Bank& bank, ifstream&, ofstream&);
void deposit(const Bank& bank, ifstream&, ofstream&);
void withdrawal(const Bank& bank,ifstream&,ofstream& );
void new_acct(Bank& bank, ifstream&, ofstream&);
void delete_acct(Bank& bank,ifstream&, ofstream&);
void acctInfo(const Bank& bank, ifstream&, ofstream&);
void acctInfoPlusTrans(const Bank& bank, ifstream&, ofstream&);
void print_transHistory(const Bank &bank, ofstream&);
void closeAcct(const Bank &bank, ifstream&, ofstream&);
void reopenAcct(const Bank &bank, ifstream&, ofstream&);

//main function
int main()
{
    //taking all data for user's input from a file
    //ifstream inFile2("con");
    ifstream inFile("C:\\Users\\diana_000\\Documents\\C++HWs"
                   "\\AdvancedC++\\BankAcct3Try\\BAinput.txt");
    ifstream inFile2("C:\\Users\\diana_000\\Documents\\C++HWs"
                     "\\AdvancedC++\\BankAcct3Try\\BAinput2.txt");
    //ifstream inFile2("con");

    //all output goes to a file
    //ofstream toFile("con");
    ofstream toFile("C:\\Users\\diana_000\\Documents\\C++HWs"
                    "\\AdvancedC++\\BankAcct3Try\\BAoutput3.txt");

    toFile<<endl<<"********Diana Rachvak********"<<endl;
    toFile<<endl<<" <Final Bank Accounts Program> "<<endl<<endl;

    Bank bankObj;

    char transaction;
    bool not_done= true; //boolean flag

    read_accts(bankObj, inFile);

    toFile<<" There are "<<bankObj.getNumOfAccts()<<" accounts"<<endl;
    print_accts(bankObj, toFile);

     //do-while loop
    do{
        printMenu();// prints a menu to a user

        cout<<endl<<"Enter your choice of a transaction: ";
        inFile2>>transaction;
        toFile<<endl;

        //switch statement for every possible choice of user's input
        switch(transaction)
        {
        case 'Q':
        case 'q':
            toFile<<"**New list of accounts and their info**"
                  <<endl;
            toFile<<" there are "<<bankObj.getNumOfAccts()
                  <<" accounts after all transactions"<<endl;
            print_accts(bankObj, toFile);
            print_transHistory(bankObj, toFile);
            not_done=false;
            break;
        case 'A':
        case 'a':
            acctInfo(bankObj, inFile2, toFile);
            break;
        case 'B':
        case 'b':
            balance(bankObj, inFile2, toFile);
            break;
        case 'C':
        case 'c':
            closeAcct(bankObj, inFile2, toFile);
            break;
        case 'D':
        case 'd':
            deposit(bankObj, inFile2, toFile);
            break;
        case 'N':
        case 'n':
            new_acct(bankObj, inFile2, toFile);
            break;
        case 'R':
        case 'r':
            reopenAcct(bankObj, inFile2, toFile);
            break;
        case 'T':
        case 't':
            acctInfoPlusTrans(bankObj, inFile2, toFile);
            break;
        case 'W':
        case 'w':
            withdrawal(bankObj, inFile2, toFile);
            break;
        case 'X':
        case 'x':
            delete_acct(bankObj,inFile2,toFile);
            break;
        default:
            toFile<<transaction<<" You entered invalid choice."
                  <<" Try again"<<endl<<endl;
        }//end switch statement

    } while(not_done);   //end of the do-while loop

    inFile.close();
    inFile2.close();
    toFile.close();
    return 0;
}//end main

/*
*Function void read_accts()
*Input:
*    bank- reference to the Bank object
*    inFile1- a reference to an input file
*Process:
*  Reads in the initial accounts database into an array of pointers
*  and counts the number of accounts
*  Uses method addAcctNumb() to set an object's data members
*Output:
*  Fills in the initial accounts database
*/
void read_accts(Bank &bank, ifstream& inFile1)
{
    string lastname, firstname, socialSN,acctType, aStatus;
    int acctNumber;
    double balance;

    Name name;
    Depositor depositor;

    while(inFile1>>lastname)
    {
       inFile1>>firstname;
       inFile1>>socialSN;
       inFile1>>acctNumber;
       inFile1>>acctType;
       inFile1>>balance;
       inFile1>>aStatus;

       bank.addAcctNumb(Depositor(Name(firstname,lastname), socialSN),
                        acctNumber, acctType, balance, aStatus);
    }
    return;
}

/*
*Function void print_accts()
*Input:
*    bank- const reference to the Bank object
*    inFile2- reference to an input file
*    toFile2- reference to an output file
*Process:
*    prints out all accounts and their info
*Output:
*    prints out accounts and info
*/
void print_accts(const Bank &bank, ofstream& toFile2)
{
    Name name;
    Depositor depositor;
    const Account *account;

    toFile2<<"**Present accounts information**"<<endl;
    toFile2<<"<Name>          <SSN>    <acct Number>  <acct Type>  "
             "  <Balance>\t<Status>"<<endl;

    for (int n=0; n < bank.getNumOfAccts(); n++)
    {
        account=bank.getAccount(n);
        depositor= account->getDepositor();
        name= depositor.getName();

        toFile2<<name.getFirstname();
        toFile2<< " " << name.getLastname();
        toFile2<< "\t" << depositor.getSSN();
        toFile2<< "\t" << account->getAccountNumber();
        toFile2<< "\t" << account->getAccountType();
        toFile2.width(8);
        toFile2<< "\t" << account->getBalance();
        toFile2<< "\t\t" << account->getAcctStatus();
        toFile2<<endl;
    }
    return;
}

/*
*Function void balance()
*Input:
*    bank- reference to the Bank object
*    inFile3- a reference to an input file
*    toFile3- a reference to an output file
*Process:
*    asks a user for an account number and prints out its
*    present balance
*Output:
*    prints out a balance of an account
*/
void balance(const Bank& bank, ifstream& inFile3, ofstream& toFile3)
{
   int index, accountNumber;
   Account *account;
   string transType="balance"; double amount=0;
   Transaction transaction;

   cout<<"please enter your account number: ";
   inFile3>>accountNumber;
   toFile3<<endl<<"*Balance transaction*"<<endl;
   toFile3<<"account number:    "<<accountNumber<<endl;

   index = bank.findAccount(accountNumber);

   if(index==-1)
       toFile3<<"account number doesn't exist. Please try again"
              <<endl<<endl;
   else
    {
       account = bank.getAccount(index);
       if(account->getAcctStatus()=="open")
        {
           toFile3<<"balance is:    "<<account->getBalance()
                  <<endl<<endl;
           transaction=Transaction(transType,amount);
           bank.getAccount(index)->addNewTransaction(transaction);
        }
       else
        toFile3<<"Account is currently closed"<<endl<<endl;
    }

   //pause();
   return;

}

/*
*Function void deposit()
*Input:
*    bank-reference to the Bank object
*    inFile4- a reference to an input file
*    toFile4- a reference to an output file
*Process:
*    performs deposit transaction by adding deposit amount to
*    the present balance of an account
*Output:
*    prints out a new balance of an account after deposit
*/
void deposit(const Bank& bank, ifstream& inFile4, ofstream& toFile4)
{
    int index, accountNumber;
    double depositAmount;
    string transType="deposit"; double transDepos;
    Account *account;
    Transaction transaction;

    cout<<"please enter your account number ";
    inFile4>>accountNumber;
    toFile4<<endl<<"*Deposit transaction*"<<endl;
    toFile4<<"account number: "<<accountNumber<<endl;

    index=bank.findAccount(accountNumber);

    if(index==-1)
       toFile4<<"account number doesn't exist. Please try again"
              <<endl<<endl;
    else{
        account = bank.getAccount(index);
        if(account->getAcctStatus()=="open")
            {
                cout<<"enter deposit amount ";
                inFile4>>depositAmount;
                toFile4<<"deposit amount: "<<depositAmount<<endl;

                if (depositAmount<=0)
                    toFile4<<"invalid deposit amount"<<endl<<endl;

                else{
                    toFile4<<"old balance: "<<account->getBalance()
                           <<endl;
                    account->makeDeposit(depositAmount);
                    toFile4.setf(ios::fixed,ios::floatfield);
                    toFile4.precision(2);
                    toFile4<<"new balance: "<<account->getBalance()
                           <<endl<<endl;

                    transDepos=depositAmount;
                    transaction=Transaction(transType,transDepos);
               bank.getAccount(index)->addNewTransaction(transaction);
                }
            }
            else
                toFile4<<"Account is currently closed"<<endl<<endl;
    }
    //pause();
    return;
}

/*
*Function void withdrawal()
*Input:
*    bank- reference to the Bank object
*    inFile5- a reference to an input file
*    toFile5- a reference to an output file
*Process:
*    performs withdrawal transaction by subtracting withdrawal amount
*    from a present balance of an account
*Output:
*    prints out the remaining balance of an account after withdrawal
*/
void withdrawal(const Bank& bank,ifstream& inFile5, ofstream& toFile5)
{
    int index, accountNumber;
    double withdrawalAmount;
    string transType="withdrawal"; double transWithdr;
    Account *account;
    Transaction transaction;

    cout<<"please enter your account number ";
    inFile5>>accountNumber;
    toFile5<<endl<<"*Withdrawal transaction*"<<endl;
    toFile5<<"account number: "<<accountNumber<<endl;

    index=bank.findAccount(accountNumber);

    if(index==-1)
       toFile5<<"account number doesn't exist. Please try again"
              <<endl;
    else{
        account = bank.getAccount(index);
        if(account->getAcctStatus()=="open")
            {
                toFile5<<"old balance:  "<<account->getBalance()
                       <<endl;
                cout<<"Enter amount to withdraw ";
                inFile5>>withdrawalAmount;
                toFile5<<"Withdrawal amount:   "<<withdrawalAmount
                       <<endl;

                if (withdrawalAmount<=0)
                    toFile5<<"Invalid withdrawal amount"<<endl;

                else if (withdrawalAmount>account->getBalance()){
                    toFile5<<"Insufficient funds. "<<endl
                           <<"Withdrawal amount exceeds available "
                           "balance"<<endl<<endl;}
                else{
                    account->makeWithdrawal(withdrawalAmount);
                    toFile5.setf(ios::fixed,ios::floatfield);
                    toFile5.precision(2);
                    toFile5<<"new balance    "<<account->getBalance()
                           <<endl<<endl;

                    transWithdr=withdrawalAmount;
                    transaction=Transaction(transType,transWithdr);
               bank.getAccount(index)->addNewTransaction(transaction);

                    }
            }
            else
                toFile5<<"Account is currently closed"<<endl<<endl;
        }
    //pause();
    return;
}

/*
*Function void new_acct()
*Input:
*    bank- reference to the Bank object
*    newTransaction- reference to the Bank object
*    inFile6- a reference to an input file
*    toFile6- a reference to an output file
*Process:
*    asks a user for a new account number and adds it to the database.
*    It also requests users name, SSN, type of an account, and initial
*    balance
*Output:
*    adds a new account and its info to the database
*/

void new_acct( Bank& bank, ifstream& inFile6, ofstream& toFile6)
{
    int accountNumber, index, index2;
    string first_name, last_name, socialSNumber, accountType,
           accountStatus;
    double initialBalance;
    string transType="new account"; double transNewAcct;

    Name name;
    Depositor depositor;
    Transaction transaction;

    cout<<"enter new account number ";
    inFile6>>accountNumber;
    toFile6<<"*New Accout Transaction* "<<endl;
    toFile6<<"Account number: "<<accountNumber<<endl;

    index=bank.findAccount(accountNumber);
    if(index==-1)
    {
        toFile6<<"New account successfully created!"<<endl;

        cout<<" Enter you first name: ";
        inFile6>>first_name;
        cout<<" Enter your last name: ";
        inFile6>>last_name;
        cout<<" Enter your SSN: ";
        inFile6>>socialSNumber;
        cout<<" Enter your account type: ";
        inFile6>>accountType;
        cout<<" Enter your initial deposit amount: ";
        inFile6>>initialBalance;

        accountStatus="open";

        bank.addAcctNumb(Depositor(Name(first_name,last_name),
                         socialSNumber), accountNumber, accountType,
                         initialBalance, accountStatus);

        toFile6<<"Your name is: "<<first_name<<" "<<last_name<<endl;
        toFile6<<"Your SSN is: "<<socialSNumber<<endl;
        toFile6<<"Your account number: "<<accountNumber<<endl;
        toFile6<<"Your account type: "<<accountType<<endl;
        toFile6<<"Your balance: "<<initialBalance<<endl;
        toFile6<<"Your account status: "<<accountStatus<<endl<<endl;

        index2=bank.findAccount(accountNumber);
        if(index2!=-1)
            {
                transNewAcct=initialBalance;
                transaction=Transaction(transType,transNewAcct);
              bank.getAccount(index2)->addNewTransaction(transaction);
            }
    }
    else
        toFile6<<"This account number already exists. "
               <<"Please try again"<<endl<<endl;
    //pause();
    return;
}

/*
*Function void delete_acct()
*Input:
*    bank- reference to the Bank object
*    inFile7- a reference to an input file
*    toFile7- a reference to an output file
*Process:
*    asks user for an account number and deletes it from the database
*Output:
*    deletes user's account from the database
*/

void delete_acct(Bank& bank,ifstream& inFile7, ofstream& toFile7)
{
    int accountNumber, index;
    Account *account;

    cout<< "enter account number you want to delete: ";
    inFile7>>accountNumber;
    toFile7<<endl<<"*Deletion of an account*"<<endl;
    toFile7<<"Account number: "<<accountNumber<<endl;

    index= bank.findAccount(accountNumber);

    if(index==-1)
    {
        toFile7<<"Account number doesn't exist. Please try again"
               <<endl<<endl;
    }


    else {
            account=bank.getAccount(index);
            if(account->getAcctStatus()=="open")
            {
                if(bank.getAccount(index)->getBalance()!=0)
                    {
                    toFile7<<"Account number can not be deleted at "
                             "the moment. Account has a balance: "
                             <<bank.getAccount(index)->getBalance()
                             <<endl<<endl; }
                else{
                    bank.deleteAcctNumb(index);
                    toFile7<<"Accomplished!"<<endl<<endl; }
            }
            else
                toFile7<<"Account is currently closed"<<endl<<endl;
    }

    //pause();
    return;
}

/*
*Function void acctInfo()
*Input:
*    bank- reference to the Bank object
*    inFile8- a reference to an input file
*    toFile8- a reference to an output file
*Process:
*    requests an account number and then prints out full account info
*Output:
*    prints out account info
*/
void acctInfo(const Bank& bank, ifstream& inFile8, ofstream& toFile8)
{
    int index;
    string socialSNumber;

    Name name;
    Depositor depositor;
    const Account *account;

    toFile8<<"*Account Info*"<<endl;
    cout<<"enter your social security number"<<endl;
    inFile8>>socialSNumber;
    cout<<" You entered> "<<socialSNumber<<endl;

    index = bank.findSSN(socialSNumber);

     if( index==-1)
        toFile8<<" Account number doesn't exist. Please try again"
               <<endl;
    else
    {
        account=bank.getAccount(index);
        if(account->getAcctStatus()=="open")
            {
                depositor= account->getDepositor();
                name= depositor.getName();

                toFile8<<"<Your account information>"<<endl;
                toFile8<<"Name is: "<<name.getFirstname();
                toFile8<< " " << name.getLastname()<<endl;
                toFile8<< "SSN: " << depositor.getSSN()<<endl;
                toFile8<<"Account number: "
                       <<account->getAccountNumber()<<endl;
                toFile8<< "Account type: " <<account->getAccountType()
                       <<endl;
                toFile8<< "Balance: " << account->getBalance()<<endl;
                toFile8<<endl;
            }
        else
            toFile8<<"Account is currently closed"<<endl<<endl;
    }
    //pause();
    return;
}

/*
*Function void acctInfo()
*Input:
*    bank- reference to the Bank object
*    inFile9- a reference to an input file
*    toFile9- a reference to an output file
*Process:
*    requests an account number and then prints out full account info
*    and all account transactions
*Output:
*    prints out account info and transactions
*/
void acctInfoPlusTrans(const Bank& bank, ifstream& inFile9,
                       ofstream& toFile9)
{
    int index, acctNumber;
    int numTransact=0;

    Name name;
    Depositor depositor;
    Account *account;
    Transaction trans1;

    toFile9<<"*Account Info Plus Transactions*"<<endl;
    cout<<"Enter your account number"<<endl;
    inFile9>>acctNumber;

    index = bank.findAccount(acctNumber);

     if(index==-1)
        toFile9<<" Account number doesn't exist. Please try again"
               <<endl;
    else{
        account=bank.getAccount(index);
        if(account->getAcctStatus()=="open")
            {
                depositor= account->getDepositor();
                name= depositor.getName();

                toFile9<<"<Your account information>"<<endl;
                toFile9<<"Name is: "<<name.getFirstname();
                toFile9<<" " << name.getLastname()<<endl;
                toFile9<<"SSN: " << depositor.getSSN()<<endl;
                toFile9<<"Account number: "
                       <<account->getAccountNumber()<<endl;
                toFile9<<"Account type: " <<account->getAccountType()
                       <<endl;
                toFile9<<"Balance: " <<account->getBalance()<<endl;
                toFile9<<"Account status: "<<account->getAcctStatus()
                       <<endl;

                numTransact=bank.getAccount(index)->getNumTrans();
                if (numTransact!=0)
                    {
                        toFile9<<"Transactions for account: "
                               <<acctNumber<<endl;
                        toFile9<<"Type    Amount"<<endl;

                        for (int i=0; i<numTransact; i++)
                            {
                            trans1= bank.printTrans(index,i);
                            toFile9<<trans1.getTransType()<<"  ";
                            toFile9<<trans1.getTransAmount()<<endl;
                            }
                        toFile9<<endl;
                    }
                else
                    toFile9<<"No transactions were made for this "
                             "account"<<endl<<endl;
            }
        else
            toFile9<<"Account is currently closed"<<endl<<endl;

    }
    //pause();
    return;
}

/*
*Function void print_transHistory()
*Input:
*    bank- reference to the Bank object
*    toFile10- a reference to an output file
*Process:
*    prints out transactions history of all currently active accounts
*Output:
*    prints out transactions history of accounts
*/
void print_transHistory(const Bank &bank, ofstream& toFile10)
{
    Account *account;
    Transaction transaction;
    int totalTrans=0;

    toFile10<<endl<<endl<<"**Accounts transaction history**"<<endl;
    toFile10<<"<Account>    <Type>      <Amount>"<<endl;

        for (int i=0; i < bank.getNumOfAccts(); i++)
        {
            account=bank.getAccount(i);
            toFile10<<bank.getAccount(i)->getAccountNumber()<<" ";
            if((bank.getAccount(i)->getNumTrans())==0)
                toFile10<<"no transactions were made"<<endl;

                for(int j=0; j<bank.getAccount(i)->getNumTrans(); j++)
                {
                    transaction= account->getTransaction(j);

                    toFile10.width(7);
                    toFile10<<" "<<transaction.getTransType();
                    toFile10.width(5);
                    toFile10<<" "<<transaction.getTransAmount();
                    totalTrans++;
                    toFile10<<endl;
                }
        }

        toFile10<<"There were total: "<<totalTrans<<" transactions"
               <<endl<<endl;
    return;
}

/*
*Function void closeAcct()
*Input:
*    bank- reference to the Bank object
*    inFile11- a reference to an input file
*    toFile11- a reference to an output file
*Process:
*    requests an account number and closes an account,
*    but doesn't delete it
*Output:
*    none. closes an account.
*/
void closeAcct(const Bank &bank,ifstream& inFile11,ofstream& toFile11)
{
    Account *account;
    int acctNumber, index;
    string newStat="closed";

    cout<<"Enter an account number you wish to close: ";
    inFile11>>acctNumber;
    cout<<"You entered: "<<acctNumber<<endl;
    toFile11<<"*Account Closure*"<<endl;
    toFile11<<"Account number: "<<acctNumber<<endl;

    index=bank.findAccount(acctNumber);

    if(index==-1)
       toFile11<<"account number doesn't exist. Please try again"
              <<endl<<endl;
    else
    {
        account = bank.getAccount(index);
        if(account->getAcctStatus()=="open")
            {
                account->setAcctStatus(newStat);
                toFile11<<"Account got closed"<<endl;
            }
    }
    return;
}


/*
*Function void reopenAcct()
*Input:
*    bank- reference to the Bank object
*    inFile11- a reference to an input file
*    toFile11- a reference to an output file
*Process:
*    requests an account number and reopens closed account
*Output:
*    none. reopens an account.
*/
void reopenAcct(const Bank &bank, ifstream& inFile12,
                ofstream& toFile12)
{
    Account *account;
    int acctNumber, index;
    string newStat="open";

    cout<<"Enter an account number you wish to reopen: ";
    inFile12 >> acctNumber;
    cout<<"You entered: "<<acctNumber<<endl;
    toFile12<<"*Reopening of an account*"<<endl;
    toFile12<<"Account number: "<<acctNumber<<endl;

    index=bank.findAccount(acctNumber);

    if(index==-1)
       toFile12<<"Account number doesn't exist. Please try again"
              <<endl<<endl;
    else
    {
        account = bank.getAccount(index);
        if(account->getAcctStatus()=="closed")
            {
                account->setAcctStatus(newStat);
                toFile12<<"Account is open again"<<endl;
            }
    }
    return;
}

/*
*Function void printMenu()
*Input:
*    none
*Process:
*    prints out the menu choice for a user
*Output:
*    prints out the menu
*/
void printMenu(void)
{
    cout<<endl<<endl;
    cout<< "****************************\n";
    cout<< "             MENU           \n";
    cout<< "****************************\n";
    cout<<"Type in a letter to select a transaction:"<<endl;
    cout<<"A- Account info"<<endl;
    cout<<"B- Balance"<<endl;
    cout<<"C- Close account"<<endl;
    cout<<"D- Deposit"<<endl;
    cout<<"N- New account"<<endl;
    cout<<"R- Reopen account"<<endl;
    cout<<"T- Account Info and Transaction History"<<endl;
    cout<<"W- Withdrawal"<<endl;
    cout<<"X- Delete account"<<endl;
    cout<<"Q- to quit"<<endl;

  return;
}

/* Function pause()
 * Input:
 *  none
 * Process:
 *  Pauses the program until a key is pressed
 * Output:
 *  none
 */
void pause(void)
{
    system("pause");
    return;
}
