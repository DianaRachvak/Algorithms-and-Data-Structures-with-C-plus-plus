#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
/*
bool has_duplicates (int n) {
    int used_digit[10]; // Flag to indicate digit has been used.

    if (n < 0) n = abs(n);
    if (n > 9999999999) return true;

    // Initialise dupe flags to false.
    for (int i = 0; i < 10; i++)
        used_digit[i] = 0;


    while (n != 0) {  // Already used? Return true.
        if (used_digit[n%10]) return true;
        used_digit[n%10] = 1;
        n /= 10;
    }
    return false; //no dupes
}
*/

bool contains_even(int n)
{
    int even = 0;
    while (n > 0)
    {
        int remainder = n % 10;
        if (remainder % 2 == 0)
            even++;
        n = n / 10;
    }

    if (even % 2 == 0)
        return 1;
    else
        return 0;
}

int to_reverse(int given_number) {
    int reversedNumber = 0, remainder;

    while(given_number != 0)
    {
        remainder = given_number%10;
        reversedNumber = reversedNumber*10 + remainder;
        given_number /= 10;
    }
    return reversedNumber;
}

string result_string (int input_number) {
    string result;
    int count = 0;

    do{
       input_number += to_reverse(input_number);
       count++;
    }while (contains_even(input_number));

    result = to_string(count) + " " + to_string(input_number);

    return result;
}


int main () {
    int n;
    //string final;

    cout<<"enter an integer: ";
    cin>>n;

    cout<<"final string: "<<result_string(n)<<endl;
}





