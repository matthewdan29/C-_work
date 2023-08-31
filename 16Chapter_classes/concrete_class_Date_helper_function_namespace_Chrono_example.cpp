/*Hey at this point expect the file names to get longer because this is important if your going to develop code for C++*/
#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*The helper function must be defined somewhere: example where is below*/
bool Chrono::is_date(int d, Month m, int y)
{
	int ndays; 

	switch (m)
	{
		case Month::feb:			/*incase of leap year*/
			ndays = 28+is_leapyear(y); 
			break; 
		case Month::apr:case Month::jun:case Month::sep: case Month::nov: 
			ndays = 30; 
			break; 
		case Month::jan:case Month::mar:case Month::may: case Month::jul:case Month::aug:case Month::oct:case Month::dec:
			ndays = 31; 
			break; 
		default: 
			return false; 
	}
	return 1 <=d && d <= ndays; 
}/*This code shows that most computer scientist are paranoid. A "Month" shouldn't be outside the "jan" to "dec" range, but it is possible so Dr. Bjarne Stroustrup chekcs*/

/*The troublesome "default_date" finally becomes:*/
const Date& Chrono::default_date()
{
	static Date d {1, Month::jan, 1970}; 
	return d; 
}



