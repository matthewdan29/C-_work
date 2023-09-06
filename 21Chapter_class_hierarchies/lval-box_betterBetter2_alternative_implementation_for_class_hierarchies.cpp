#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*REMEMBER: these are examples of abstract classes*/
/*One solution is to have a hierarchy consist of our orignal application-orented conceptual hierarchy of interfaces expressed as derived classes:*/
class lval_box {/*....*/}; 
class lval_slider
	:public lval_box{/*...*/}; 
class Flashing_ival_slider{/*...*/}; 		/*I know just if you use the code for your personal use you choice between 'i' or 'l'*/
	:public lval_slider{/*...*/}; 
class Popup_ival_slider
	:public lval_slider{/*...*/}; 
/*followed by the implementations of this hierarchy for various graphical user interface systems, expressed as derived classes:*/

class BB_ival_slider 
	:public lval_slider, protected BBslider{/*...*/}; 
class BB_flashing_ival_slider
	:public Flashing_ival_slider, protected BBwidget_with_bells_and_whistles{/*...*/}; 
class BB_popup_ival_slider
	:public Popup_ival_slider, protected BBslider{/*...*/}; 
class CW_ival_slider
	:public lval_slider, protected CWslider{/*...*/}; 
/*...*/

/*The original "lval_box" class hierarchy appears unchanged surrounded by implementation classes.*/

