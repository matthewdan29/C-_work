#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*"while" statement executes its controlled statement until its condition becomes false. */

template<class Iter, class Value>
Ilter find(Iter first, Iter last, Value val)
{
	while (first != && *first != val)
		++first; 
	return first; 
}/*Best practice is to prefer "while"-statement over "for"-statements when there isn't an obvios loop variable or where the update of a loop variable naturally comes in the middle of the loop body.*/
