#include <list>
#include <string>
#include <iostream>
using namespace std; 

template<class T>
void f1(initializer_list<T>); 

struct S
{
	int a; 
	string s; 
}; 
void f2(S); 

template<class T, int N>
void f3(T(&r)[N]); 

void f4(int); 

void g()
{
	f1({1,2,3,4}); 				/*'T' is int and the initializer_list has size() 4*/
	f2({1, "MKS"}); 			/*f2(S{1,"MKS"})*/
	f3({1,2,3,4}); 				/*T is int and N is 4*/
	f4({1}); 				/*f4(int{1})*/
}

/*If there is a possible ambiguity, an "initializer_list" parameter takes priority.*/

template<class T>
void f(initializer_list<T>); 

struct S
{
	int a; 
	string s; 
}; 

void f(S); 

template<class T, int N>
void f(T(&r)[N]); 

void f(int); 

void g()
{
	f({1,2,3,4}); 			/*T is int and the initializer_list has size() 4*/
	f({1, "MKS"}); 			/*calls f(S)*/
	f({1}); 			/*T is int and the initializer_list has size() 1*/
}
