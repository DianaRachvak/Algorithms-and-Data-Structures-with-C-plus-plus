#include <iostream>
#include <iomanip>

using namespace std;

class Insurance{
    int PID;
    double TIV_2011, TIV_2012, LAT, LON;
 public:
    Insurance(){} //default constructor

    //constructor with 5 parameters
    Insurance(int PID_1, double TIV2011, double TIV2012, double Lat,
              double Lon)
    {
        PID = PID_1;
        TIV_2011 = TIV2011;
        TIV_2012 = TIV2012;
        LAT = Lat;
        LON = Lon;
    }

    //getters
    double getTIV_2011()const { return TIV_2011; }
    double getTIV_2012()const { return TIV_2012; }
    double getLAT()const { return LAT; }
    double getLON() const { return LON; }
};

int main()
{
 int max= 20;
 int id;
 double tiv_2011, tiv_2012, lat, lon;

 Insurance insurance[max];
 char choice;
 bool not_done = true;
 int n = 0;

 do
 {
   cout<<"If you wish to enter the data type \"Y\". Type \"N\" to quit.";
   cin>>choice;
   cout<<endl;

   switch(choice)
   {
   case 'Y':
   case 'y':
       cout<<"Enter ID #: ";
       cin>>id;
       cout<<endl<<"Enter TIV_2011: ";
       cin>>tiv_2011;
       cout<<endl<<"Enter TIV_2012: ";
       cin>>tiv_2012;
       cout<<endl<<"Enter latitude: ";
       cin>>lat;
       cout<<endl<<"Enter longtitude: ";
       cin>>lon;
       cout<<endl<<endl;

       insurance[n] = {id, tiv_2011, tiv_2012, lat, lon};
       n++;
       break;
    case 'N':
    case 'n':
        not_done = false;
        break;
    default:
        cout<<"You entered invalid choice. Try again."<<endl;
   }// end of the switch statement

 }while (not_done); //end of the do-while loop

 //part of the code that compares values and prints the sum
 double sum = 0;

 for (int i=0; i<max; i++)
 {
    if (insurance[i].getTIV_2011() == insurance[i+1].getTIV_2011()
        && insurance[i].getLAT() != insurance[i+1].getLAT()
        && insurance[i].getLON() != insurance[i+1].getLON())
        sum+= insurance[i].getTIV_2012();
 }
  cout<<"The sum is: "<<setprecision(2)<<fixed<<sum;

 return 0;
}
