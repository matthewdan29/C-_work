#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*this is the best C style of incramenting */
int i; 
for (i = 0; q[i] != 0; i++)
	p[i] = q[i];			/*verable at p[i] is now q[i]*/

p[i] = 0;				/*terminating zero*/


/*The variable 'i' used for indexing can be eliminated because 'p' and 'q' are pointers*/
while (*q != 0)
{
	*p = *q; 
	p++; 				/*point to next character*/
	q++; 				/*point to next character*/
}
*p = 0; 				/*terminating zero*/


/*Because the post-increment operation allows us first to use the value and then to increment it, we can rewrite the loop like below */

while (*q != 0)
{
	*p++ = *q++; 
}

*p = 0; /*terminating zero*/

/*The value of "*p++ = *q++" is "*q". We can therefore rewrite the example like this: */
while((*p++ = *q++) != 0){};
/*We dont notice that "*q" is zero until we already have copied it into "*p" and incremented 'p'. */


/*We can reduce the example further by observing that we dont need the empty block and that the "!=0" is redundant because the result of an integral condition is always compared to zero anyway. Thus, we get the version we set out to discover:*/
while(*p++ = *q++); 


/*NOTE: the most effcient way of copying a zero-terminated character string is typically the standard style string copy function: below*/
char* strcpy(char*, const char*); 		/*from <string.h>*/
