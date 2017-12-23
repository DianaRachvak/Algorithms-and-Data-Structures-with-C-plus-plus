/*
Diana Rachvak
Description: *Bank accounts*
             This is a C++ program that allows user to perform
             simple ATM transactions. It prints out a menu
             with choice of transactions then calls a series
             of functions to perform these transactions. All data
             for input is taken from a file assignment6Input.txt and
             assignment6Input2.txt.
             All output goes to a file assignment6Output.txt.
*/
#include <iostream>
#include <fstream>

using namespace std;
const int MAX_NUM=40;

//all functions prototypes
void printMenu(void);
int find_acct(int acctnum_array[], int num_accts, int account);
int read_accts(int acctnum_array[], double balance_array[],
               int max_accts, ifstream&);
int new_acct(int acctnum_array[], double balance_array[],
             int num_accts, ifstream&, ofstream&);
void withdrawal(int acctnum_array[],double balance_array[],
                int num_accts,ifstream&, ofstream&);
void deposit(int acctnum_array[], double balance_array[],
             int num_accts, ifstream&, ofstream&);
void balanceOf(int acctnum_array[], double balance_array[],
               int num_accts,ifstream&, ofstream&);
void print_accts(int acctnum_array[], double balance_array[],
                 int num_accts, ifstream&, ofstream&);
int delete_acct(int acctnum_array[], double balance_array[],
                int num_accts, ifstream&, ofstream&);

//start of the main function
int main()
{
    //taking all data for user's input from a file
    //ifstream inFile2("con");
    ifstream inFile ("C:\\Users\\diana_000\\Documents\\C++HWs"
                     "\\Chapter7\\assignment6Input.txt");
    ifstream inFile2("C:\\Users\\diana_000\\Documents\\C++HWs"
                     "\\Chapter7\\assignment6Input2.txt");

    //all output goes to a file
    //ofstream toFile("con");
    ofstream toFile ("C:\\Users\\diana_000\\Documents\\C++HWs"
                     "\\Chapter7\\assignment6Output.txt");

    toFile<<endl<<"********Diana Rachvak********"<<endl<<endl;

    char transaction;
    bool not_done= true; //boolean flag for exiting the do-while loop

    int acctNum[MAX_NUM];
    double balance[MAX_NUM];

    //finds an exact number of accounts
    int numAccts;
    numAccts=read_accts(acctNum, balance, MAX_NUM, inFile);
    toFile<<"There is total of "<<numAccts<<" accounts"<<endl;

    print_accts(acctNum, balance, numAccts, inFile, toFile);

     //do-while loop
    do{
        printMenu();// prints a menu to a user

        cout<<endl<<"Enter your choice of a transaction: " <<endl;
        inFile2>>transaction;
        toFile<<endl;

        //switch statement for every possible choice of user's input
        switch(transaction)
        {
        case 'Q':
        case 'q':
            toFile<<"**New list of accounts and their balances**"
                  <<endl;
            toFile<<"There is total of "<<numAccts<<" account now"
                  <<endl;
            print_accts(acctNum, balance, numAccts, inFile, toFile);
            not_done=false;
            break;
        case 'B':
        case 'b':
            balanceOf(acctNum, balance, numAccts, inFile2, toFile);
            break;
        case 'D':
        case 'd':
            deposit(acctNum, balance, numAccts, inFile2, toFile);
            break;
        case 'W':
        case 'w':
            withdrawal(acctNum, balance, numAccts, inFile2, toFile);
            break;
        case 'N':
        case 'n':
            numAccts = new_acct(acctNum, balance, numAccts, inFile2,
                                toFile);
            break;
        case 'X':
        case 'x':
            numAccts = delete_acct(acctNum, balance, numAccts,
                                   inFile2, toFile);
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
*Function int read_accts()
*Input:
*    acctnum_array- an array of integers
*    balance_array- an array of doubles
*    max_accts- maximum possible number of accounts
*    inFile1- a reference to an input file
*Process:
*    fills up the account number and balance arrays
*Output:
*    returns actual number of accounts
*/
int read_accts(int acctnum_array[], double balance_array[],
               int max_accts, ifstream& inFile1)
{
    int i=0;
    while(!inFile1.eof() && inFile1>>acctnum_array[i]
                                   >>balance_array[i])
    {
        if(i<max_accts)
           i++;
    }
    return i;
}

/*
*Function void print_accts()
*Input:
*    acctnum_array- an array of integers
*    balance_array- an array of doubles
*    num_accts- number of present accounts
*    inFile2- reference to an input file
*    toFile2- reference to an output file
*Process:
*    prints out all available accounts and their balances
*Output:
*    prints out accounts and balances
*/
void print_accts(int acctnum_array[], double balance_array[],
                 int num_accts,ifstream& inFile2, ofstream& toFile2)
{
    toFile2<<"**Present accounts and their balances**"<<endl;
    toFile2<<"Account number\tAccount balance"<<endl;
        for(int n=0; n<num_accts; n++){
            toFile2.width(8);
            toFile2<<acctnum_array[n];
            toFile2.width(17);
            toFile2<<balance_array[n]<<endl;
        }
    return;
}

/*
*Function int find_acct()
*Input:
*    acctnum_array- an array of integers
*    balance_array- an array of doubles
*    num_accts- number of present accounts
*Process:
*    finds the index of account in account array
*Output:
*    returns the index of account in account array
*/
int find_acct(int acctnum_array[], int num_accts, int account)
{
    for(int count=0; count<num_accts; count++)
        if(acctnum_array[count] == account)
            return count;
    return -1;
}

/*
*Function void balance()
*Input:
*    acctnum_array- an array of integers
*    balance_array- an array of doubles
*    num_accts- number of present accounts
*    inFile3- a reference to an input file
*    toFile3- a reference to an output file
*Process:
*    asks for an account number and prints out its' present balance
*Output:
*    prints out a balance of an account
*/
void balanceOf(int acctnum_array[], double balance_array[],
               int num_accts, ifstream& inFile3, ofstream& toFile3)
{
   int account,index;
   cout<<"please enter your account number: ";
   inFile3>>account;
   toFile3<<endl<<"*Balance transaction*"<<endl;
   toFile3<<"account number:    "<<account<<endl;

   index = find_acct(acctnum_array,num_accts,account);
   if(index==-1)
       toFile3<<"account number doesn't exist. Please try again"<<endl;
   else
       toFile3<<"balance is:    "<<balance_array[index]<<endl;

   return;

}

/*
*Function void deposit()
*Input:
*    acctnum_array- an array of integers
*    balance_array- an array of doubles
*    num_accts- number of present accounts
*    inFile4- a reference to an input file
*    toFile4- a reference to an output file
*Process:
*    performs deposit transaction by adding deposit amount to
*    the present balance of the account
*Output:
*    prints out a new balance of the account after deposit
*/
void deposit(int acctnum_array[], double balance_array[],
             int num_accts, ifstream& inFile4, ofstream& toFile4)
{
    int depositAmount, account, index;
    double newBalance;
    cout<<"please enter your account number ";
    inFile4>>account;
    toFile4<<endl<<"*Deposit transaction*"<<endl;
    toFile4<<"account number:   "<<account<<endl;
    index=find_acct(acctnum_array,num_accts,account);
    if(index==-1)
       toFile4<<"account number doesn't exist. Please try again"
              <<endl;
    else{
        cout<<"enter deposit amount ";
        inFile4>>depositAmount;
        toFile4<<"deposit amount     "<<depositAmount<<endl;
        if (depositAmount<=0)
            toFile4<<"invalid deposit amount"<<endl;
        else{
            newBalance=balance_array[index]+depositAmount;
            toFile4.setf(ios::fixed,ios::floatfield);
            toFile4.precision(2);
            toFile4<<"old balance    "<<balance_array[index]<<endl;
            toFile4<<"new balance    "<<newBalance<<endl;
        }
    }
    return;
}

/*
*Function void withdrawal()
*Input:
*    acctnum_array- an array of integers
*    balance_array- an array of doubles
*    num_accts- number of present accounts
*    inFile5- a reference to an input file
*    toFile5- a reference to an output file
*Process:
*    performs withdrawal transaction by subtracting withdrawal amount
*    from a present balance
*Output:
*    prints out a remaining balance of the account after withdrawal
*/
void withdrawal(int acctnum_array[],double balance_array[],
                int num_accts, ifstream& inFile5, ofstream& toFile5)
{
    int withdrawalAmount, account, index;
    double newBalance;
    cout<<"please enter your account number ";
    inFile5>>account;
    toFile5<<endl<<"*Withdrawal transaction*"<<endl;
    toFile5<<"account number:   "<<account<<endl;

    index=find_acct(acctnum_array,num_accts,account);

    if(index==-1)
       toFile5<<"account number doesn't exist. Please try again"
              <<endl;
    else{
        toFile5<<"old balance    "<<balance_array[index]<<endl;
        cout<<"enter amount to withdraw ";
        inFile5>>withdrawalAmount;
        toFile5<<"withdrawal amount:   "<<withdrawalAmount<<endl;

        if (withdrawalAmount<=0)
            toFile5<<"invalid withdrawal amount"<<endl;
        else if (withdrawalAmount>balance_array[index])
            toFile5<<"Insufficient funds. "<<endl
                   <<"Withdrawal amount exceeds available balance"
                   <<endl;
        else{
            toFile5.setf(ios::fixed,ios::floatfield);
            toFile5.precision(2);
            newBalance=balance_array[index]-withdrawalAmount;
            toFile5<<"new balance    "<<newBalance<<endl;}
    }
    return;
}

/*
*Function int new_acct()
*Input:
*    acctnum_array- an array of integers
*    balance_array- an array of doubles
*    num_accts- number of present accounts
*    inFile6- a reference to an input file
*    toFile6- a reference to an output file
*Process:
*    adds new user's account to database
*Output:
*    returns new total of account numbers
*/
int new_acct(int acctnum_array[], double balance_array[],
             int num_accts,ifstream& inFile6, ofstream& toFile6)
{
    int newAccount, index;
    cout<<"enter new account number ";
    inFile6>>newAccount;
    toFile6<<endl<<"*New account*"<<endl;
    toFile6<<"you entered "<<newAccount<<endl;
    index=find_acct(acctnum_array,num_accts,newAccount);

    if(index==-1){
            acctnum_array[num_accts] = newAccount;
            balance_array[num_accts]=0.00;
            num_accts++;
            toFile6<<"your balance is 0"<<endl;
            toFile6<<"New account successfully created!"<<endl;}
    else
        toFile6<<"This account number already exists. "
               <<"Please try again"<<endl;
    return num_accts;
}

/*
*Function int delete_acct()
*Input:
*    acctnum_array- an array of integers
*    balance_array- an array of doubles
*    num_accts- number of present accounts
*    inFile7- a reference to an input file
*    toFile7- a reference to an output file
*Process:
*    deletes user's account from database
*Output:
*    returns new total of account numbers
*/
int delete_acct(int acctnum_array[], double balance_array[],
                int num_accts, ifstream& inFile7, ofstream& toFile7)
{
    int deleteAcct, index;
    cout<<"enter account number you want to delete ";
    inFile7>>deleteAcct;
    toFile7<<endl<<"*Deletion of an account*"<<endl;
    toFile7<<"You entered account number "<<deleteAcct
           <<" to delete"<<endl;

    index=find_acct(acctnum_array,num_accts,deleteAcct);
    if(index==-1){
        toFile7<<" Account number doesn't exist. Please try again"
               <<endl;
    }
    else{
        for (int i =index; i<num_accts-1; i++){
            acctnum_array[i] = acctnum_array[i + 1];
            balance_array[i] = balance_array[i + 1];}
        num_accts--;

        toFile7<<"Accomplished!"<<endl;
    }
    return num_accts;
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
void printMenu(void) //done
{
    cout<<"type in a letter to select a transaction:"<<endl;
    cout<<"W- Withdrawal"<<endl;
    cout<<"D- Deposit"<<endl;
    cout<<"N- New account"<<endl;
    cout<<"B- Balance"<<endl;
    cout<<"Q- to quit"<<endl;
    cout<<"X- Delete account"<<endl;

  return;
}
