#include <iostream>

using namespace std;

int main()
{
    int num, even=0, odd = 1;

    cout<<"enter a number: ";
    cin>>num;
    cout<<endl;

    while(num!=0)
    {
        if(num%2==0)
        {
            if(num>even)
                even = num;
        }
        else
        {
            if(num>odd)
                odd = num;
        }
        cout<<"enter a number: ";
        cin>>num;
        cout<<endl;
    }

    cout<<"largest even number was: "<<even<<endl;
    cout<<"largest odd number was: "<<odd<<endl;
}
