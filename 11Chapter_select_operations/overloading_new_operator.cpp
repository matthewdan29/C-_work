#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*Consider a simple class:*/
class X 
{
public: 
	X(int); 
	/*...*/
};

/*you can place objects anywhere by providing an allocator function with extra arguments and then supplying such extra arguments when using "new"*/
void* operator new(size_t, void* p) {return p; }	/*explicit placement operator*/

void* buf = reinterpret_cast<void*> (0xF00F); 		/*significant address*/
X* p2 = new(buf) X; 					/*construct and X at buf; */
							/*invokes: operator new(sizeof(X), buf)*/


/*The "operator new()" is the simplest allocator. it is defined in the standard "header <new>".*/

void* operator new (size_t sz, void* p) noexcept; 	/*place object of size sz at p*/
void* operator new[](size_t sz, void* p) noexcept; 	/*place object of size at p*/

void operator delete(void* p, void*) noexcept; 		/*if (p) make *p invalid*/

void operator delete[](void* p, void*) noexcept; 	/*if (p) make *p invalid*/

/*The placement "new" construct can also be used to allocate memory from a specific arena: */

class Arena
{
public:
	virtual void* alloc(size_t) = 0; 
	virtual void free(void*) = 0; 
	/*...*/
	       
}; 

void* operator new(size_t sz, Arena* a)
{
	return a->alloc(sz); 
}

/*Now objects of arbitrary types can be allocated from different "Arena" as needed. */

extern Arena* Persistent; 
extern Arena* shared; 

void g(int i)
{
	X* p = new(Presistent) X(i); 			/*X in persistent storage*/
	X* q = new(Shared) X(i); 			/*X in shared memory*/
	/*...*/
}

/*Placeing an object in an area that is not controlled by the standard free-store manager implies that some care is required when destroying the object. The basic mechanism for that is an explicit call of a destructor: */

void destroy(X* p, Arena* a)
{
	p->~X(); 					/*call destructor*/
	a->free(p); 					/*fee memory*/
}
