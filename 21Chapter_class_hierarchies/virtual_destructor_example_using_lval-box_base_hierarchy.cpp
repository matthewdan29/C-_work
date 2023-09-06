#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*To ensure proper cleanup by defining a virtual destructor "lval_box::~lval_box()" in the base and overriding it suitably in derived classes. example below*/

void f(lval_box* p)
{
	/*...*/
	delete p; 
}
/*The "delete" operator explicitly destroys the object pointed to by 'p'. You have no way of knowing exactly to which class the object pointed to by 'p' belongs, but thanks to "lval_box"'s virtual destructor, proper cleanup as defined by that class destructor will be done*/

/*The "lval_box" hierarchy can now be defined like below*/
class lval_box{/*...*/}; 
class lval_slider
	:public lval_box, protected BBwidget{/*...*/}; 
class lval_dial
	:public lval_box, protected BBwidget {/*...*/}; 
class Flashing_ival_slider
	:public lval_slider {/*...*/}; 
class Popup_ival_slider
	:public lval_slider {/*...*/}; 
