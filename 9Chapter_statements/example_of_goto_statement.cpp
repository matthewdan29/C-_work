#include <string>
#include <iostream>
#include <list>

/*One of the few sensible uses of "goto" in ordinary code is to break out from a nested loop or "switch"-statement*/

void do_something(int i, int j)
	/*do something to a two-dimensional matrix called "mn" */
{
	for (i = 0; i != n; ++i)
		for (j = 0; j != m; ++j)
			if (nm[i][j] == a)
				goto found; 
		/*not found*/
		/*...*/
	found:
       		/*nm[i][j] == a*/	
	
}/*Note that this "goto" just jumps forward to exit its loop. It does not introduce a new loop or enter a new scope. That makes it the least troublesome and least confusing use of a "goto". */
