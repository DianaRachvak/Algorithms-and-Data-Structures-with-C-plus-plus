/*
Diana Rachvak
Description: *Bank accounts using classes*
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
#include <string>
#include <cstdlib>

using namespace std;
const int MAX_NUM=40;

//class declarations
class Name{
public:
    string first;
    string last;
};

class Depositor{
public:
    Name name;
    string SSN;
};

class BankAccount{
public:
    Depositor client;
    int acctNumber;
    string acctType;
    double balance;
};



//all functions prototypes
void printMenu(void);
int find_acct(const BankAccount account[],int num_accts,
              int requested_account);
int read_accts(BankAccount account[], int max_accts, ifstream&);
int new_acct(BankAccount account[],int num_accts, ifstream&,
             ofstream&);
void withdrawal(BankAccount account[],int num_accts,ifstream&,
                ofstream&);
void deposit(BankAccount account[],int num_accts, ifstream&,
             ofstream&);
void balance(const BankAccount account[],int num_accts,ifstream&,
               ofstream&);
void print_accts(const BankAccount account[],int num_accts, ifstream&,
                  ofstream&);
int delete_acct(BankAccount account[],int num_accts, ifstream&,
                ofstream&);
void acctInfo(const BankAccount account[], int num_accts,ifstream&,
              ofstream&);
int find_acct2(const BankAccount account[],int num_accts,
              int requested_account);
void pause(void);

//main function
int main()
{
    //taking all data for user's input from a file
    //ifstream inFile2("con");
    ifstream inFile ("C:\\Users\\diana_000\\Documents\\C++HWs"
                     "\\AdvancedC++\\bankAccounts2\\BAinput.txt");
    ifstream inFile2("C:\\Users\\diana_000\\Documents\\C++HWs"
                     "\\AdvancedC++\\bankAccounts2\\BAinput2.txt");
    //ifstream inFile2("con");

    //all output goes to a file
    //ofstream toFile("con");
    ofstream toFile ("C:\\Users\\diana_000\\Documents\\C++HWs"
                     "\\AdvancedC++\\bankAccounts2\\BAoutput.txt");

    toFile<<endl<<"********Diana Rachvak********"<<endl<<endl;

    BankAccount account[MAX_NUM];

    char transaction;
    bool not_done= true; //boolean flag for exiting the do-while loop
    int numAccts;

    //finds an exact number of accounts
    numAccts=read_accts(account, MAX_NUM, inFile);
    toFile<<"There is total of "<<numAccts<<" accounts"<<endl;

    print_accts(account, numAccts, inFile, toFile);

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
            toFile<<"**New list of accounts and their info**"
                  <<endl;
            toFile<<"There is total of "<<numAccts<<" accounts now"
                  <<endl;
            print_accts(account, numAccts, inFile, toFile);
            not_done=false;
            break;
        case 'A':
        case 'a':
            acctInfo(account, numAccts, inFile2, toFile);
            break;
        case 'B':
        case 'b':
            balance(account, numAccts, inFile2, toFile);
            break;
        case 'D':
        case 'd':
            deposit(account, numAccts, inFile2, toFile);
            break;
        case 'W':
        case 'w':
            withdrawal(account, numAccts, inFile2, toFile);
            break;
        case 'N':
        case 'n':
            numAccts = new_acct(account, numAccts,inFile2,toFile);
            break;
        case 'X':
        case 'x':
            numAccts=delete_acct(account,numAccts,inFile2,toFile);
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
*    account- bank accounts' database
*    max_accts- maximum number of accounts
*    inFile1- a reference to an input file
*Process:
*    fills up the account database
*Output:
*    returns actual number of accounts
*/
int read_accts(BankAccount account[],int max_accts, ifstream& inFile1)
{
    int i=0;
    while(inFile1>>account[i].client.name.first && i<max_accts)
    {
       inFile1>>account[i].client.name.last;
       inFile1>>account[i].client.SSN;
       inFile1>>account[i].acctNumber;
       inFile1>>account[i].acctType;
       inFile1>>account[i].balance;
       i++;
    }
    return i;
}

/*
*Function void print_accts()
*Input:
*    const account- bank accounts' database, not changeable
*    num_accts- number of present accounts
*    inFile2- reference to an input file
*    toFile2- reference to an output file
*Process:
*    prints out all accounts and their info
*Output:
*    prints out accounts and info
*/
void print_accts(const BankAccount account[],int num_accts,
                 ifstream& inFile2,ofstream& toFile2)
{
    toFile2<<"**Present accounts information**"<<endl;
    toFile2<<"<Name>          <SSN>      <acct Number> <acct Type>    "
             "<Balance>"<<endl;

    for (int n=0; n<num_accts; n++)
    {
        toFile2<<account[n].client.name.first;
        toFile2<< " " << account[n].client.name.last;
        toFile2<< "\t" << account[n].client.SSN;
        toFile2<< "\t" << account[n].acctNumber;
        toFile2<< "\t" << account[n].acctType;
        toFile2.width(8);
        toFile2<< "\t" << account[n].balance;
        toFile2<<endl;
    }
    return;
}

/*
*Function int find_acct()
*Input:
*    const account- bank accounts' database, constant
*    num_accts- number of present accounts
*Process:
*    finds index of an account in bank accounts' database
*Output:
*    returns the index of an account
*/
int find_acct(const BankAccount account[],int num_accts,
              int requested_account)
{
    for(int count=0; count<num_accts; count++)
    {
        if(account[count].acctNumber == requested_account)
            return count;
    }
    return -1;
}

/*
*Function void balance()
*Input:
*    account- bank accounts' database
*    num_accts- number of present accounts
*    inFile3- a reference to an input file
*    toFile3- a reference to an output file
*Process:
*    asks for an account number and prints out its' present balance
*Output:
*    prints out a balance of an account
*/
void balance(const BankAccount account[],int num_accts,
             ifstream& inFile3, ofstream& toFile3)
{
   int index, accountNumber;
   cout<<"please enter your account number: ";
   inFile3>>accountNumber;
   toFile3<<endl<<"*Balance transaction*"<<endl;
   toFile3<<"account number:    "<<accountNumber<<endl;

   index = find_acct(account,num_accts,accountNumber);
   if(index==-1)
       toFile3<<"account number doesn't exist. Please try again"<<endl<<endl;
   else
       toFile3<<"balance is:    "<<account[index].balance<<endl<<endl;

   pause();
   return;

}

/*
*Function void deposit()
*Input:
*    account- bank accounts' database
*    num_accts- number of present accounts
*    inFile4- a reference to an input file
*    toFile4- a reference to an output file
*Process:
*    performs deposit transaction by adding deposit amount to
*    the present balance of the account
*Output:
*    prints out a new balance of the account after deposit
*/
void deposit(BankAccount account[], int num_accts, ifstream& inFile4,
             ofstream& toFile4)
{
    int index, accountNumber;
    double newBalance, depositAmount;
    cout<<"please enter your account number ";
    inFile4>>accountNumber;
    toFile4<<endl<<"*Deposit transaction*"<<endl;
    toFile4<<"account number: "<<accountNumber<<endl;
    index=find_acct(account,num_accts,accountNumber);
    if(index==-1)
       toFile4<<"account number doesn't exist. Please try again"
              <<endl<<endl;
    else{
        cout<<"enter deposit amount ";
        inFile4>>depositAmount;
        toFile4<<"deposit amount     "<<depositAmount<<endl;
        if (depositAmount<=0)
            toFile4<<"invalid deposit amount"<<endl<<endl;
        else{
            toFile4<<"old balance    "<<account[index].balance<<endl;
            newBalance=account[index].balance+depositAmount;
            toFile4.setf(ios::fixed,ios::floatfield);
            toFile4.precision(2);
            toFile4<<"new balance    "<<newBalance<<endl<<endl;
        }
    }
    pause();
    return;
}

/*
*Function void withdrawal()
*Input:
*    account- bank accounts' database
*    num_accts- number of present accounts
*    inFile5- a reference to an input file
*    toFile5- a reference to an output file
*Process:
*    performs withdrawal transaction by subtracting withdrawal amount
*    from a present balance
*Output:
*    prints out the remaining balance of the account after withdrawal
*/
void withdrawal(BankAccount account[], int num_accts,
                ifstream& inFile5, ofstream& toFile5)
{
    int index, accountNumber;
    double newBalance, withdrawalAmount;
    cout<<"please enter your account number ";
    inFile5>>accountNumber;
    toFile5<<endl<<"*Withdrawal transaction*"<<endl;
    toFile5<<"account number: "<<accountNumber<<endl;

    index=find_acct(account,num_accts,accountNumber);

    if(index==-1)
       toFile5<<"account number doesn't exist. Please try again"
              <<endl;
    else{
        toFile5<<"old balance    "<<account[index].balance<<endl;
        cout<<"enter amount to withdraw ";
        inFile5>>withdrawalAmount;
        toFile5<<"withdrawal amount:   "<<withdrawalAmount<<endl;

        if (withdrawalAmount<=0)
            toFile5<<"invalid withdrawal amount"<<endl;
        else if (withdrawalAmount>account[index].balance)
            toFile5<<"Insufficient funds. "<<endl
                   <<"Withdrawal amount exceeds available balance"
                   <<endl<<endl;
        else{
            toFile5.setf(ios::fixed,ios::floatfield);
            toFile5.precision(2);
            newBalance=account[index].balance-withdrawalAmount;
            toFile5<<"new balance    "<<newBalance<<endl<<endl;}
    }
    pause();
    return;
}

/*
*Function int new_acct()
*Input:
*    account- bank accounts' database
*    num_accts- number of present accounts
*    inFile6- a reference to an input file
*    toFile6- a reference to an output file
*Process:
*    adds new user's account to database
*Output:
*    returns new total of account numbers
*/
int new_acct(BankAccount account[], int num_accts,ifstream& inFile6,
             ofstream& toFile6)
{
    int index, accountNumber;
    string first_name, last_name, socialSNumber, accountType;
    double initialBalance;

    cout<<"enter new account number ";
    inFile6>>accountNumber;
    toFile6<<"Your entered "<<accountNumber<<endl;

    index=find_acct(account,num_accts,accountNumber);

    if(index==-1){
            toFile6<<"New account successfully created!"<<endl;
            account[num_accts].acctNumber=accountNumber;

            cout<<" Enter you first name ";
            inFile6>>first_name;
            account[num_accts].client.name.first=first_name;

            cout<<" Enter your last name ";
            inFile6>>last_name;
            account[num_accts].client.name.last=last_name;
            toFile6<<"Your name is "<<first_name<<" "<<last_name<<endl;

            cout<<" Enter your Social Security Number ";
            inFile6>>socialSNumber;
            account[num_accts].client.SSN=socialSNumber;
            toFile6<<"Your Social Security Number is "<<socialSNumber<<endl;
            toFile6<<"Your account number is "<<accountNumber<<endl;

            cout<<" Enter your account type ";
            inFile6>>accountType;
            account[num_accts].acctType=accountType;
            toFile6<<"Your account type "<<accountType<<endl;

            cout<<" Enter your initial deposit amount ";
            inFile6>>initialBalance;
            account[num_accts].balance=initialBalance;
            toFile6<<"Your Balance is "<<initialBalance<<endl<<endl;
            num_accts++;
    }
    else
        toFile6<<"This account number already exists. "
               <<"Please try again"<<endl<<endl;
    pause();
    return num_accts;
}

/*
*Function int delete_acct()
*Input:
*    account- bank accounts' database
*    num_accts- number of present accounts
*    inFile7- a reference to an input file
*    toFile7- a reference to an output file
*Process:
*    deletes user's account from database
*Output:
*    returns new total of account numbers
*/
int delete_acct(BankAccount account[], int num_accts,
                ifstream& inFile7, ofstream& toFile7)
{
    int index, accountNumber;
    cout<< "enter account number you want to delete";
    inFile7>>accountNumber;
    toFile7<<endl<<"*Deletion of an account*"<<endl;
    toFile7<<"You entered account number "<<accountNumber
           <<" to delete"<<endl;

    index=find_acct(account,num_accts,accountNumber);
    if(index==-1){
        toFile7<<" Account number doesn't exist. Please try again"
               <<endl;
    }
    else if (account[index].balance!=0){
        toFile7<<" Account number can not be deleted at the moment. "
                 "Account has a balance: "<<account[index].balance
                 <<endl<<endl;
    }
    else{
        for (int i=index; i<num_accts-1; i++){
            num_accts--;
            account[index]=account[num_accts];
        }
        toFile7<<"Accomplished!"<<endl<<endl;
    }
    pause();
    return num_accts;
}

/*
*Function int find_acct2()
*Input:
*    const account- bank accounts' database, constant
*    num_accts- number of present accounts
*Process:
*    finds index of an account in bank accounts' database
*Output:
*    returns the index of an account
*/
int find_acct2(const BankAccount account[],int num_accts,
              string requested_account)
{
    for(int count=0; count<num_accts; count++)
    {
        if(account[count].client.SSN == requested_account)
            return count;
    }
    return -1;
}
/*
*Function void acctInfo()
*Input:
*    const account- bank accounts' database, constant
*    num_accts- number of present accounts
*    inFile8- a reference to an input file
*    toFile8- a reference to an output file
*Process:
*    prints out full account info
*Output:
*    prints out complete account info
*/
void acctInfo(const BankAccount account[], int num_accts,
              ifstream& inFile8, ofstream& toFile8)
{
    int index;
    string socialSNumber;
    toFile8<<"Account Info"<<endl;
    cout<<"enter your social security number"<<endl;
    inFile8>>socialSNumber;
    toFile8<<" You entered> "<<socialSNumber<<endl;

    index=find_acct2(account,num_accts,socialSNumber);
     if( index==-1)
        toFile8<<" Account number doesn't exist. Please try again"
               <<endl;
     else
        {
           toFile8<<"<Your Account Information>"<<endl;
           toFile8<<"Name: "<<account[index].client.name.first;
           toFile8<<" "<<account[index].client.name.last<<endl;
           toFile8<<"Social Security Number: "
                  << account[index].client.SSN<<endl;
           toFile8<<"Account Number: "<<account[index].acctNumber
                  <<endl;
           toFile8<<"Type of an Account: "<<account[index].acctType
                  <<endl;
           toFile8<< "Account Balance "<<account[index].balance<<endl<<endl;
        }
    pause();
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
    cout<<"A- account info"<<endl;
    cout<<"W- Withdrawal"<<endl;
    cout<<"D- Deposit"<<endl;
    cout<<"N- New account"<<endl;
    cout<<"B- Balance"<<endl;
    cout<<"Q- to quit"<<endl;
    cout<<"X- Delete account"<<endl<<endl;

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
