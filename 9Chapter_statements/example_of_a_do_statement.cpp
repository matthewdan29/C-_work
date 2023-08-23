#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*"do" statement is similar to a "while"-statement except that the condition comes after the body.*/

void print_backwards(char a[], int i)		/*i must be positive*/
{
	cout << '{'; 
	do
	{
		cout << a[--i]; 
	}
	while (i); 
	cout << '}'; 
}

