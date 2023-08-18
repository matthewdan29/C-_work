/*Every standard-library facility is provided through some standard header.*/
#include <string>
#include <list>

/*this makes the standard "string" and "list" available.
 *
 * The standard library is defined in a namespace called "std". To use standard library facilities, the std:: prefix can be used: */

std::string s {"Four legs Good; two legs Bad!"}; 
std::list<std::string> slogans {"War is peace", "Freedom is Slavery", "Ignorance is Strength"}; 

/*To compile and run the program fragments here, you must "#include" the appropriate header and make the names they declare accessible.*/

#include<string>	/*make the standard string facilities accessible*/
using namespace std;	/*make "std" names available without std:: prefix*/

string s 
{
	"C++ is a general-purpose programing language"
}; 	/*OK: string is std::string*/
