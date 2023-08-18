#include <iostream>
#include <string>
#include <list>

/*The following program output is 10*/
void f()
{
	cout << 10;
}

/*now 10 is assigned to 'i' */
void g()
{
	int i {10}; 
	cout << i; 
}

/*you can also combine output in obvious ways*/
void h(int i)
{
	cout << "the value of i is"; 
	cout << i; 
	cout << '\n'; 
}

/*The result of an output expression can itself be used for further output.*/
void h2(int i)
{
	cout << "the value of i is "<< i << '\n'; 
}

/*Note that a character is output as a character rather than as a numberical value.*/

void k()
{
	int b = 'b'; /*note: char implicitly converted to int*/
	char c = 'c'; 
	cout << 'a' << b << c; 
}
/*The output is going to be a98c C++ uses ASCll encoding.*/
