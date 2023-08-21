#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*An enumerator can be initialized by a constant expression of intergral type.*/

enum class Printer_flags
{
	acknowledge = 1, 
	paper_empty = 2,
	busy = 4,
	out_of_black = 8, 
	out_of_color = 16, 
	/*...*/
}; 

/*The values for "Printer_flags" enumerators are chosen so that they can be combined by bitwise operations. */

/*An "enum" is a user-defined type, so we can define the '|' and '&' operators for it.*/

constexpr Printer_flags operator|(Printer_flags a, Printer_flags b)
{
	return static_cast<Printer_flags>(static_cast<int>(a))| static_cast<int>(b);
}

constexpr Print_flags operator&(Printer_flags a, Printer_flags b)
{
	return static_cast<Printer_flags>(static_cast<int>(a))&static_cast<int>(b); 
}

/*The explicit convertion are necessary because a "class enum" does not support implicit conversions. Given these definitions of '|' and '&' "Printer_flags", you can write*/

void try_to_print(Printer_flags x)
{
	if (x&Printer_flags::acknowledge)
	{
		/*...*/
	}
	else 
		if (x&Printer_flags::busy)
		{
			/*...*/
		}
		else 
			if (x&(Printer_flags::out_of_black|Printer_flags::out_of_color))
			{
				/*either we are out of black or we are out of color*/
				/*...*/
			}
	/*...*/
}



