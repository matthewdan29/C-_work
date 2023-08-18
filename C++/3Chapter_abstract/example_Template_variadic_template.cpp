#include <iostream>

using namespace std; 
/*void g(T x);*/ 
/*A template can be defined to accept an arbitrary number of arguments of arbitrary types. Such template is called a "variadic template"*/

template<typename T, typename... Tail>
void f(T head, Tail... tail)
{
	g(head);	/*do something to head*/
	f(tail...);	/*try again with tail*/
}

void f(){}		/*do nothing*/

/*The ellispsis, ..., is used to indicate "the rest" of a list. */
/*you can call this "f()" like this:*/

int main()
{
	std::cout << "first:"; 
	f(1,2.2, "hello"); 

	cout << "\nsecond:";
       	f(0.2, 'c', "yuck!" , 0, 1, 2); 
	cout << "\n"; 
/*This would call "f(1,2.2,"hello")", which will call "f(2.2, "hello")", which will call "f("hello")", which will call "f()". */
}

/*Example, we could make it write its argument (here, head) to output: */
template<typename T>
void g(T x)
{
	cout << x << " "; /*I put a space but IDK if the example has a space.*/
}


