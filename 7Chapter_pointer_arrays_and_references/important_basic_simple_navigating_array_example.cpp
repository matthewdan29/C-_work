#include <string>
#include <iostream>
#include <list>
#include <cmath>
#include <threads>	/*just creating habbits please do so */
using namespace std; 

/*Efficient and elegant access to arrays is the key to many algorithms. Access can be achieved either through a pointer to an array plus an index or through a pointer to an element.*/

void fi(char v[])
{
	for (int i = 0; v[i] != 0; ++i)
		use(v[i])
}

void fp(char v[])
{
	for (char* p = v; *p != 0; ++;)
		use(*p); 
}
/*The prefix '*' operator dereferences a pointer so that "*p" is the character pointed to by p.*/

/*NOTE: this is possible but do not do in production code. */

a[j] == *(&a[0]+j) == *(a+j) == *(j+a) == j[a]; 
/*meaning*/

a[j] == j[a];

/*example*/
3["Texas"] == "Texas"[3] == 'a'; 
