#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


bool contains_even(int n)
{
    int num, remainder;

    if (n < 0) n = abs(n);

    while(n > 0)
    {
        num = n % 10;
        remainder = num % 2;

        if(remainder == 0) return true;

        n = n / 10;
    }
    return false;
}


int to_reverse (int given_number)
{
    int reversedNumber = 0, num;

    while(given_number != 0)
    {
        num = given_number%10;
        reversedNumber = reversedNumber*10 + num;
        given_number /= 10;
    }
    return reversedNumber;
}


string result_string (int input_number)
{
    string result;
    int count = 0;

    do{
       input_number += to_reverse(input_number);
       count++;
    }while (contains_even(input_number));

    result = to_string(count) + " " + to_string(input_number);

    return result;
}


int main()
{
    string line;
    int n;

    while (getline(cin, line)) {
        n = stoi(line);

        line = result_string (n);

        cout << line << endl;
    }
}
