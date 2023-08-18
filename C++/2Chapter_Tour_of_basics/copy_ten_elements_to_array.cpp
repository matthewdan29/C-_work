#include <iostream>
 /*This "for" loop statement can be read as "set i to zero; while i !< 10 copy the ith element and increment i" */

void copy_fct()
{
	int v1[10] = {0,1,2,3,4,5,6,7,8,9};
	int v2[10];			/* to become a copy of v1 */

	for (auto i=0; i != 10; ++i)
		v2[i] = v1[i]; 
}
