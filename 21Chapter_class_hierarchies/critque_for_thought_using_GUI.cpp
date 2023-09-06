#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*Deriving "lval_box" from "BBwidget" elevated an implementation detail to a first-level design decision. 
 * That can be right. Using the environment defined by "Big Bucks Inc." may be key decision based on how our organization conducts its business. 
 * Whatif you we wanted to have implementations of our "lval_box"es for systems "Imperial Bananas," "liberated Software," and "compiler whizzes"? We would have to maintain four distinct versions of our program: */

class lval_box : public BBwidget{/*...*/}; 		/*BB version*/
class lval_box : public CWwidget{/*...*/}; 		/*CW version*/
class lval_box : public IBwidget{/*...*/}; 		/*IB version*/
class lval_box : public LSwindow{/*...*/}; 		/*LS version*/

/*We are unlikely to find a simple, coherent, two-letter prefix scheme.
 * The libraries from differnet purveyors would be in different namespaces and use different terminologyies for similar concepts, such as "BigBucks::Widget" "Wizzies::control", and "LS::window". 
 * But that does not affect our class hierarchy design discussion, so to simplify we ignore naming and namespaces issues.*/
