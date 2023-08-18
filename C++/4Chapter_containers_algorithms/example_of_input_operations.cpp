#include <iostream>
#include <list>
#include <string>

/*The operator ">>" (get from) is used as an input operator; cin is the standard input stream. The type of the right-hand operand of ">>" determines what input is accepted and what is the target of the input operation. */

void f()
{
	int i; 
	cin >> i;	/*read an integer into 'i'*/

	double d;
	cin >> d;	/*read a double-percision floating-point nuber into d*/
}

/*This reads a number, such as "1234", from the standard input into the integer variable 'i' and a floating-point number, such as 12.34e5, into the double-precision floating-point variable 'd'. */

/*reading into a string is a convenient way to read a sequence of characters.*/
void hello()
{
	cout << "Please enter your name\n"; 
	string str; 
	cin >> str; 
	cout << "Hello, " << str << "!\n";
}

/*if you type in Matthew the response is "Hello, Matthew"*/

/*Yes they got your boy "getline()"*/
void hello_line()
{
	cout << "Please enter your name\n"; 
	string str; 
	getline(cin, str); 
	cout << "Hello, " << str << "!\n"; 
}

/*The input "mattdan29 the power of youth" the output will be "mattdan29 the power of youth"*/


