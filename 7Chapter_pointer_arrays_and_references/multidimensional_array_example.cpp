#include <list>
#include <string>
#include <string>
#include <iostream>

/*Multidimensional arrays are represented as arrays of arrays; a 3-by-5 array*/
int ma[3][5];			/*3 arrays with 5 ints each*/

/*You can initialize "ma" like this*/
void init_ma()
{
	for (int i = 0; i != 3; i++)
		for (int j = 0; j != 5; j++)
			ma[i][j] = 10*i+j; 
}
/*The array "ma" is simply 15 ints that we access as if it were 3 arrays of 5 ints.*/

/*its easy to just make it a main and look at the print out with very little reworking*/

void print_ma()
{
	for (int i = 0; i != 3; i++)
	{
		for (int j = 0; j != 5; j++)
			cout << ma[i][i] << '\t'; 
		cout << '\n'; 
	}

}
