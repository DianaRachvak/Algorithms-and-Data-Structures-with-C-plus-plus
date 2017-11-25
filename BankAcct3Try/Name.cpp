/* Name Class Implementation */
/* Name.cpp*/

#include <string>
#include "Name.h"
using namespace std;


/* Name member function setLastname:
 * Input:
 *  lastname - object's last name
 * Process:
 *  sets the value member variable last
 * Output:
 *  none
 */
void Name::setLastname(string lastname)
{
    last = lastname;
    return;
}

/* Name member function setFirstname:
 * Input:
 *  firstname - object's first name
 * Process:
 *  sets the value member variable first
 * Output:
 *  none
 */
void Name::setFirstname(string firstname)
{
    first = firstname;
    return;
}

/* Name member function getLastname:
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable last
 * Output:
 *  returns the object's last name
 */
string Name::getLastname() const
{
    return (last);
}

/* Name member function getFirstname:
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable first
 * Output:
 *  returns the object's first name
*/
string Name::getFirstname() const
{
    return (first);
}
