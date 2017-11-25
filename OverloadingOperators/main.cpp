/*
Diana Rachvak
Description: *Overloading Operators*
             This program allows user to enter a number from 1 to 365
             and get exact month and day corresponding to a number.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "DayOfYear.h"
using namespace std;

int main()
{
    int dayNumber;
    string convertMonth;
    DayOfYear dayObj1, dayObj2, dayObj3;

    ifstream inFile("C:\\Users\\diana_000\\Documents\\C++HWs"
                  "\\AdvancedC++\\OverloadingOperators\\input6.txt");
    //ofstream toFile("con");
    ifstream inFile2("C:\\Users\\diana_000\\Documents\\C++HWs"
                "\\AdvancedC++\\OverloadingOperators\\input6(2).txt");

    ofstream toFile("C:\\Users\\diana_000\\Documents\\C++HWs"
                  "\\AdvancedC++\\OverloadingOperators\\output6.txt");
    //ofstream toFile("con");

    toFile<<"***Diana Rachvak***"<<endl<<endl;

    cout<<"Enter a day number from 1 to 365.(Enter -1 to stop): ";
    inFile>>dayNumber;
    toFile<<"************************************************"<<endl
          <<"**Number to be converted into month-day format**"<<endl
          <<"************************************************"<<endl;

    while(!inFile.eof())
    {
        //part #1
        if(dayNumber<1 || dayNumber>365)
            {
            toFile<<"You entered: "<<dayNumber<<endl;
            toFile<<"You entered invalid number.Try again"<<endl<<endl;
            cout<<"enter a day number(from 1 to 365): ";
            inFile>>dayNumber;
            }
        else{
            toFile<<"You entered: "<<dayNumber<<endl;
            dayObj1= DayOfYear(dayNumber);
            dayObj2=DayOfYear(dayNumber);
            toFile<<"It's "<<dayObj1.print()<<endl;

            dayObj1++;
            toFile<<"*Demonstrating postfix ++* ";
            toFile<<"Next day is: "<<dayObj1.getMonth()<<" "
                  <<dayObj1.getDay()<<endl;
            dayObj2--;
            toFile<<"*Demonstrating postfix --* ";
            toFile<<"Day before was: "<<dayObj2.getMonth()<<" "
                  <<dayObj2.getDay()<<endl;

            dayObj1= DayOfYear(dayNumber);
            dayObj2=DayOfYear(dayNumber);

            ++dayObj1;
            toFile<<"*Demonstrating prefix ++* ";
            toFile<<"Next day is: "<<dayObj1.getMonth()<<" "
                  <<dayObj1.getDay()<<endl;
            --dayObj2;
            toFile<<"*Demonstrating prefix --* ";
            toFile<<"Day before was: "<<dayObj2.getMonth()<<" "
                  <<dayObj2.getDay()<<endl<<endl;

            cout<<"enter a day number(from 1 to 365): ";
            inFile>>dayNumber;
            }
    }

    cout<<endl<<"Enter month and day to be converted into "
                      "exact day number: "<<endl;
    inFile2>>convertMonth>>dayNumber;

    toFile<<"*******************************************"<<endl
          <<"**Month and day converted into day number**"<<endl
          <<"*******************************************"<<endl;

    while(!inFile2.eof())
    {
        //part #2
        toFile<<"You entered: "<<convertMonth<<" "<<dayNumber<<endl;
        if(dayNumber>31)
        { toFile<<"You entered invalid day for a month. "<<endl
                <<"Program is being terminated."<<endl; }

        dayObj3 = DayOfYear(convertMonth,dayNumber);
        toFile<<"It's day #"<<dayObj3.getDay()<<endl<<endl;

        cout<<"Enter month and day to be converted into exact"
              " day number: ";
        inFile2>>convertMonth>>dayNumber;
    }

    toFile<<"Prints the line if prog is not termineted after part#2"
          <<endl;

    inFile.close();
    inFile2.close();
    toFile.close();
    return 0;
}
