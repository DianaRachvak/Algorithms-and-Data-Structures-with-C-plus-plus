#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void checkSpace(string);

int main()
{
    string userInput;

    cout<<"Enter a string: ";
    getline(cin, userInput);

    checkSpace(userInput);

    for (int n=0; n<userInput.length(); n++)
    {
        cout<<userInput[n];
    }

    return 0;
}
void checkSpace(string userStr)
{
    //char c;
    for (int i=0; i<userStr.length(); i++)
    {
        //c = userStr[i];
        if (userStr[i]==' ')
        {
            userStr[i]='%20';
        }
    }

}
