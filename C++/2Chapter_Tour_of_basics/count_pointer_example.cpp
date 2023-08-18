#include<iostream>


int count_x(char* p, char x)
/* count the number of occurrences of x in p[]*/
/* p is assumed to point to a zero-terminated array of char (or to nothing)*/
{
	if (p == nullptr)
		return 0; 
	int count = 0; 
	for (; *p != 0; ++p)
		if (*p == x)
			++count; 
	return count; 
}
