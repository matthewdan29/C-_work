#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*this one line for statement gives you greater control of the iteratior*/
void f(int v[], int max)
{
	for (int i = 0; i != max; ++i)
		v[i] = i*i; 
}

/*this loop goes on forever*/

for (;;)	/*"forever"*/
{
	/*...*/
}
