#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*by the name of the file you can tell I used java interfaces lol*/
/*The different kinds of "lval_box"es are defined as classes derived from "lval_box".*/

class lval_slider : public lval_box
{
private: 
	/*...graphics stuff to define what the slider looks like, etc...*/
public: 
	lval_slider(int, int); 
	int get_value() override; 		/*get value from user and deposit it in val*/
	void prompt() override; 
}; /*The data members of "lval_box" were declared "protected" to allow access from derived classes. "lval_slider::get_value()" can deposit a value in "lval_box::val". A "protected" member is accessible from a classes own members and from members from members of derived classes, but not to general users.*/
