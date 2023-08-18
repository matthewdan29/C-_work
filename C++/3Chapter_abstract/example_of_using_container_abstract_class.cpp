#include <iostream>

void use(Container& c)
{
	const int sz = c.size(); 
	
	for (int i = 0; i != sz; ++i)
		cout <<c[i]<<'\n'; 
}
/*"use()" uses the "Container" interface in complete ignorance of implementation. */
