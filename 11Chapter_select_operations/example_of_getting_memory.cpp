#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*Opertors "new", "delete", "new[]", "delete[]" are implemented using functions presented in the "<new> header"*/

void* operator new(size_t); 		/*allocate space for individual object*/
void operator delete(void* p); 		/*if (p) deallocate space allocated using operator new()*/

void* operator new[](size_t); 		/*allocate space for array */
void operator delete[](void* p); 	/*if (p) deallocate space allocated using operator new[]()*/

/* when operator "new" needs to allocate space for an object, it calls "operator new()" to allocate a suitable number of bytes. Similarly, when operator "new" needs to allocate space for an array, it calls "operator new[]()"*/


