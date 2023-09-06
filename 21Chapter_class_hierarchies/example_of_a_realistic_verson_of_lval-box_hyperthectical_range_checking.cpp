#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*A programmer might use these "lval classes" like below:*/
void interact(lval_box* pb)
{
	pb->prompt(); 		/*alert user*/
	/*...*/
	int i = pb->get_value(); 
	if (pb->was_changed())
	{
		/*... new value; do something...*/
	}
	else 
	{
		/*...do something else...*/
	}
}

void some_fct()
{
	unique_ptr<lval_box>p1{new lval_slider{0,5}}; 		/*"lval_slider" derived from "lval_box"*/
	interact(p1.get()); 

	unique_ptr<lval_box>p2 {new lval_dial{1,12}}; 
	interact(p2.get()); 
}/*Most application code is written in terms of (pointer to) plain "lval_box"es the way "interact()" is. 
   The application doesn't have to know about the potenially large number of variants of the "lval_box" concept.
   The knowlage of such specialized classes is isolated in the relatively few functioins that create such objects.
   This isolates users from changes in the implementations of the derived classes. 
   Most code can be oblivious to the fact that there are different kinds of "lval_box"es*/


