#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*below is a example of construction of a value of type 'T' for a value 'e'*/

auto d1 = double{2};				/*d1 == 2.0*/
double d2 {double{2}/4}; 			/*d1 == 0.5*/

/*Part of the attraction of the "T{v}" notation is that it will perform only "well-behaved" conversions*/

void f(int); 
void f(double); 

viod g(int i, double d)
{
	f(i); 						/*call f(int)*/
	f(double{i}); 					/*error: {} doesn't do int to float conversion*/

	f(d); 						/*call f(double)*/
	f(int{d}); 					/*error: {} doesnt trucate*/
	f(static_cast<int>(d)); 			/*call f(int) with a truncated value*/
	f(round(d)); 					/*call f(double) with a rounded value*/
	f(static_cast<int>(Iround(d))); 		/*call f(int) with a round value*/
							/*if the d is overflows the int this still truncates*/
}

/*I dont consider truncation of floating-point numbers "well behaved," so having to be explicit when you want it is a good thing. If rounding is desirable, you can use the stdlib function "round()"; it performs "convertional 4/5 rounding," 7.9 to 8 and 7.4 to 7*/

/*if the size of an "int" is the same as the size of a "double", then some such conversions must lost information. Consider: */
static_assert(sizeof(int)==sizeof(double), "unexpected sizes"); 

int x = numeric_limits<int>::max(); 		/*largest possible integer*/
double d = x; 
int y = x; 

/*The constructor notation "T{}" is used to express the default value of type "T".*/

template<class T> void f(const T&); 

void g3()
{
	f(int{}); 				/*default int value*/
	f(complex<double>{}); 			/*default complex value*/
	/*...*/
}
