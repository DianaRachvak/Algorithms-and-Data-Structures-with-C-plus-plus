/* DayOfYear Class Implementation */

#include <sstream>
#include <string>
#include "DayOfYear.h"

//initializing static members of a class
int DayOfYear::NumDaysInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,
                                   31};
string DayOfYear::twelveMonths[12]={"January","February","March",
                                    "April","May","June","July",
                                    "August","September","October",
                                    "November","December"};

/*
*Function int findMonth()
*Input:
*    day365- integer, to be represented as exact month
*Process:
*    defines integer's range,and returns exact month it corresponds to
*Output:
*    returns actual month
*/
string DayOfYear::findMonth(int day365)
{
    string local;

    if (day365>0 && day365<=31)
        local = "January";
    if(day365>31 && day365<=59)
        local="February";
    if(day365>59 && day365<=90)
        local="March";
    if(day365>90 && day365<=120)
        local="April";
    if(day365>120 && day365<=151)
        local="May";
    if(day365>151 && day365<=181)
        local="June";
    if(day365>181 && day365<=212)
        local="July";
    if(day365>212 && day365<=243)
        local="August";
    if(day365>243 && day365<=273)
        local="September";
    if(day365>273 && day365<=304)
        local="October";
    if(day365>304 && day365<=334)
        local="November";
    if(day365>334 && day365<=365)
        local="December";
    return local;
}

/*
*Function int findDay()
*Input:
*    numb365- integer, to be converted to an exact day of a month
*Process:
*    looks at array of months. finds month and its index.
*    uses that index to find how many days this month has.
*    subtracts all previous months from input number- returns the
*    actual day of the month.
*Output:
*    returns actual day of the month
*/
int DayOfYear::findDay(int numb365)
{
   int count=0;
   int sum=0;
   month = findMonth(numb365);

   for (int index=0; index<12; index++)
   {
       if(month==twelveMonths[index])
        {
            count=index;

            for(int j = 0 ; j < count; j++)
            { sum += NumDaysInMonth[j]; }
       }
   }
   actualDay = numb365 - sum;
   return actualDay;
}

/*
*Function int convertToDay()
*Input:
*    month365- string that holds exact month
*    day365- integer, to be converted to an exact day of a month
*Process:
*    compares input month365 to months in twelveMonths array.
*    finds corresponding month and its index.
*    uses that index to find how many days this month has.
*    subtracts all previous months from input number- returns
*    month and day converted into a single day number.
*Output:
*    returns converted day number
*/
int DayOfYear::convertToDay(string month365, int day365)
{
   int count=0;
   int sum=0;

   for (int index=0; index<12; index++)
   {
       if(month365==twelveMonths[index])
        {
            count=index;

            for(int j = 0 ; j < count; j++)
            { sum += NumDaysInMonth[j]; }
       }
   }
   day = day365 + sum;
   return day;
}

//prints out integers represented by month and day
//converts int to a string using typecast
string DayOfYear::print()
{
    string localDay = static_cast<ostringstream*>( &(ostringstream()
                                              << actualDay) )->str();
    return month + " " + localDay;
}


//retrieves the value of member variable day
int DayOfYear::getDay()const
{ return day; }

//retrieves the value of member variable month
string DayOfYear::getMonth()const
{ return month; }


//overloading prefix and postfix ++ operators
DayOfYear DayOfYear::operator++()
{
	++day;
	if(day>31){
        month="January";
        day=1;}
	return *this;
}

DayOfYear DayOfYear::operator++(int)
{
	DayOfYear temp(day);
	day++;
	if(day>31){
        month="January";
        day=1;}
	return temp;
}

//overloading prefix and postfix -- operators
DayOfYear DayOfYear::operator--()
{
    --day;
    if(day==0){
        month="December";
        day=31;}
    return *this;
}

DayOfYear DayOfYear::operator--(int)
{
    DayOfYear temp1(day);
    day--;
      if(day==0){
        month="December";
        day=31;}
    return temp1;
}
