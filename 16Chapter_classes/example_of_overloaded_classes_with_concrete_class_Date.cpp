#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*It is often useful to add functions to enable conventional notaion. "operator==()" defines the equality operator, "==", to work for "Date"s:*/

inline bool operator==(Date a, Date b)			/*equality*/
{
	return a.day()==b.day() && a.month()==b.month() && a.year()==b.year(); 
}

/*Other obcious candidates are:*/

bool operator!=(Date, Date); 				/*inequality*/
bool operator<(Date, Date); 				/*less than*/
bool operator>(Date, Date); 				/*greater than*/
/*...*/

Date& operator++(Date& d){return d.add_day(1);}		/*increase Date by one day*/
Date& operator--(Date& d){return d.add_day(-1); }	/*decrease Date by one day*/

Date& operator+=(Date& d, int n){return d.add_day(n);}	/*add 'n' days*/
Date& operator-=(Date& d, int n){return d.add_day(-n);} /*subtract 'n' days*/

Date operator+(Date d, int n){return d+=n;}		/*output 'd'*/
Date operator-(Date d, int n){return d+=n;}		/*subtract 'n' days*/

ostream& operator<<(ostream&, Date d); 			/*output 'd'*/
istream& operator>>(istream&, Date& d); 		/*read into 'd'*/
/*These operators are defined in "Chrono" together with "Date" to avoid overloaded problems and to benefit from argument-dependent lookup.*/


/*PERSONALY: I'm a fan of operator for classes specaily coming from python and java it forces you to know what the operations is and to know the symbol like char */
