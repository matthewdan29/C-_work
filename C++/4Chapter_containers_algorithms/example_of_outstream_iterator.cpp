#include <iostream>
#include <string>
#include <list>

using namespace std; 
/*This is an example of outstream iteration*/

ostream_iterator<string> oo 
{
	cout
};	/*write strings to cout*/

/*The effect of assigning to "*oo" is to write the assigned value to "cout"*/
int main()
{
	*oo = "Hello, ";	/*meaning cout<<"Hello"*/
	++oo; 
	*oo = "world!\n"; 	/*meaning cout<<"world!\n"*/
}

