/*first off I know my naming of the file might be wrong*/
#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*Think of your creating an abstract class that is based from "Comm_sat" called class "Telstar". A qualified name, such as "Telstar::draw" can refer to a "draw" declared either in "Telstar" or in one of its base classes. example below*/

class Telstar : public Comm_sat
{
public: 
	void draw()
	{
		Comm_sat::draw(); 		/*finds "Displayed::draw"*/
		/*...own stuff...*/
	}
	/*...*/
}/*Thing of calling draw like the "tree -t" function on linux. When "Comm_sat::draw" doesn't relove to a "draw" declared in "Comm_sat" the compiler recurively looks in its base classes:
that is it looks for "Satellite::draw" and "Displayed::draw" and if necessary looks in their base classes. If exactly one match is found, that name will be used.
Otherwise, "Comm_sat::draw" is either not found or is ambiguous.*/
