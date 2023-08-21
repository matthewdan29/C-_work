#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*An array is an aggregate of elements of the same type. In its simplest from, a "struct" is an aggregate of elements of arbitrary types:*/

struct Address{
	const char* name;		/*Matthew Daniels*/
	int number; 			/*61*/
	const char* street;		/*South St*/
	const char* town;		/*New Providence*/
	char state[2];			/*'N' 'J'*/
	const char* zip;		/*07974*/
}/*This defines a type called Address consisting of the items you need in order to send mail to someone in the US*/

/*Variables of type "Address" can be declared exactly like other variables, and the individual "members" can be accessed using the '.' (dot) operator.*/

void f()
{
	Address jd; 
	jd.name = "Matthew Daniels"; 
	jd.name = 61;
}

/*Veriables of "struct" type can be initialized using the {} notation.*/

Address jd = {
	"Matthew Daniels",
	61, "South St", 
	"New Providence",
	{'N', 'J'}, "07974"
}; 


/*Structures are often accessed through ponters using the "->" operator*/

void print_addr(Address* p)
{
	cout << p->name << '\n' << p->number << ' ' << p->street << '\n' << p->state[0] << p->state[1] << ' ' << p->zip << '\n'; 
}/*When 'p' is a pointer, "p->m" is equivalent to (*p).m*/

/*you can pass a struct by reference and accessed using the '.' operator:*/

void print_addr2(const Address& r)
{
	cout << r.name << '\n' << r.number << ' ' << r.street << '\n' << r.state[0] << r.state[1] << ' ' << r.zip << '\n'; 
}

/*Objects of structure types can be assigned, passed as function arguments, and returned as the result from a function.*/

Address current; 

Address set_current(Address next)
{
	address prev = current; 
	current = next; 
	return prev; 
}
/*you can define (= and !=) but not available by default.*/


