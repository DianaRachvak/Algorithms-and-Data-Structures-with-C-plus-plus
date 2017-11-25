/* Name Class Specification */

#ifndef NAME_H
#define NAME_H

#include <iostream>
#include <string>
using namespace std;

//Name class declarations
class Name {
    string last;
    string first;
  public:
    // Constructors
    /* Name default constructor:
     * Input:
     *  none
     * Process:
     *  sets object's data members to default values
     * Output:
     *  object's data members are set
     */
    Name()
    {
        //cout << "Name default constructor is running" << endl;
        first = "";
        last = "";
    }


    /* Name constructor 2 - accepts 2 arguments:
     * Input:
     *  firstname - client's first name
     *  lastname - client's last name
     * Process:
     *  sets the member variable first = firstname
     *  sets the member variable last = lastname
     * Output:
     *  object's data members are set
     */
    Name(string firstname, string lastname)
    {
        //cout << "Name constructor 2 is running" << endl;
        first = firstname; last = lastname;
    }

    // mutators (or setter member functions)
    void setLastname(string last_name);
    void setFirstname(string first_name);

    // accessors (or getter member functions)
    string getLastname() const;
    string getFirstname() const;
};
#endif
