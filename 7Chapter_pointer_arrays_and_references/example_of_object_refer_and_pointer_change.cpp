#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*If you need to change which object to refer to, use a pointer. You can use "=", "+=", "-=", "++", and "--" to change the value of a pointer variable.*/

void fp(char* p)
{
	while(*p)
		cout << ++*p; 
}

void fr(char& r)
{
	while(r)
		cout << ++r;		/*opps: increment the char referred to, not the reference*/
					/*near-infinite loop!*/
}

void fr2(char& r)
{
	char* p = &r;			/*get a pointer to the object referred to*/
	while(*p)
		cout << ++*p;
}

/*If you want to be sure that a name always refers to the same object, use a reference:*/

template<class T> class Proxy		/*Proxy refers to the object with which it is initialized*/
{
	T& m; 
public: 
	Proxy(T& mm) :m{mm}{}
	/*...*/
}; 

template<class T> class Handle		/*Handle refers to its current object*/
{
	T* m; 
public: 
	Proxy(T* mm) :mm{mm}{}
	void rebind(T* mm) {m = mm;}
	/*...*/
}; 

/*If you want to use a user-defined operator on something that refers to an object, use a reference*/

Matrix operator+(const Matrix&, const Matrix&);		/*OK*/
Matrix operator-(const Matrix*, const Matrix*);		/*error: no user-defined type argument*/

Matrix y, z;
/*...*/
Matrix x = y+z; 		/*ok*/
Matrix x2 = &y - &z;		/*error and ugly*/


/*If you want a collection of something that refers to an object, you must use a pointer: */

int x, y; 
string& a1[] = {x,y};		/*error: array of references*/
string* a2[] = {&x, &y};	/*OK*/
vector<string&> s1 = {x,y};	/*error:vector references*/
vector<string*> s2 = {&x, &y};	/*Ok*/

/*There is no equivalent "null reference" so if you need a "no value" using a pointer may be most appropriate.*/

void fp(X* p)
{
	if (p == nullptr)
	{
		/*no value*/
	}
	else
	{
		/*use *p*/
	}
}

void fr(X& r)		/*common style*/
{
	/*assume that r is valid and use it*/
}

/*If you really want to, you can construct and check for a "null reference" for a particular type: */

void fr2(X& r)
{
	if (&r == &nullX)	/*or maybe r == nullX*/
	{
		/*no value*/
	}
	else
	{
		/*use r*/
	}
}

/*It is possible to create an invalid reference, but you have to go out of your way to do so.*/

char* ident(char *p) {return p;}

char& r{*ident(nullptr)};		/*invalid code*/

/*This code is not valid C++ code. Dont write such code even if your current implementation doesn't catch it.*/
