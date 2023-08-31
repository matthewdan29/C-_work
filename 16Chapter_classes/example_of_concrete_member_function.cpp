#include <string>
#include <list>
#include <iostream>
using namespace std; 
/*If your reading along in the book you might see that i'm rearaging something to make to better for learning and just better for me to understand also.*/
/*An implementtation for each member function must be provided.*/

Date::Date(int dd, Month mm, int yy)
	:d{dd}, m{mm}, y{yy}
{
	if (y == 0) 
		y = default_date.year(); 
	if (m == Month{}) 
		m = default_date().month(); 
	if (d == 0) 
		d = default_date().day(); 

	if (!is_valid())			/*the date given isn't valid*/
		throw Bad_date(); 
}

void fill(vector<Date>& aa)
{
	while (cin)
	{
		Date d; 
		try
		{
			cin >> d; 
		}
		catch (Date::Bad_date)
		{
			/*...my error handling...*/
			continue; 
		}
		aa.push_back(d); 
	}
}

/*Checking that a "{d,m.y}" set of values is a valid date is not a computation that dependson the representation of a "Date" so Implemented "is_valid()" in terms of a helper function */

bool Date::is_valid()
{
	return is_date(d, m, y); 
}

/*As common for such simple concrete type, the definition of "Date"'s member functions vary between the trivial and not-too-complicated example below*/

inline int Date::day() const
{
	return d; 
}

Date& Date::add_month(int n)
{
	if (n == 0)
		return *this; 

	if (n > 0)
	{
		int delta_y = n/12;		/*Number of whole years*/
		int mm = static_cast<int>(m)+n%12; 	/*number of months ahead*/
		if (12 < mm)			/*note: dec is represented by 12*/
		{
			++delta_y; 
			mm -= 12; 
		}
		/*...handle the cases where the month "mm" doesn't have day 'd'*/
		y += delta_y; 
		m = static_cast<Month>(mm); 
		return *this; 
	}

	/*... handle negative 'n'...*/
	return *this; 
}
