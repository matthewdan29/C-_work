#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*In programs where exceptions must be avoided, you can use "nothrow" versions of the "new" and "delete"*/

void f(int n)
{
	int* p = new(nothrow) 
		int[n]; 		/*allocate 'n' ints on the free store*/
	if (p == nullptr)		/*no memory availble*/
	{
		/*...handle allocation error..*/
	}

	/*....*/
	operator delete(nothrow, p); 		/*deallocate *p*/
}	

/*That "nothrow" is the name of an object of the standard-library type "nothrow_t" that is used for disambiguation; "nothrow" and "nothrow_t" are declared in "<new>"*/
/*The functions implementing this are found in "<new>":*/

void* operator new(size_t sz, const nothrow_t&) noexcept; 	/*allocate sz bytes*/
								/*return nullptr if allocatioin failed*/
void operator  delete(void* p, const nothrow_t&) noexcept; 	/*deallocate space allocated by new*/

void* operator new[](size_t sz, const nothrow_t&) noexcept; 	/*allocate sz bytes;*/
								/*return "nullptr" if allocation failed*/
								/*return nullptr if allocation failed*/
void operator delete[](void* p, const nothrow_t&) noexcept; 	/*deallocate space allocated by new*/

/*These "operator new" functions return "nullptr", rather than throwing "bad_alloc", if there is not sufficient memory to allocate.*/
