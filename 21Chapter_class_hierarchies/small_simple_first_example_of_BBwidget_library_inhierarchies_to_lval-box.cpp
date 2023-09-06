/*If all of the classes in "lval_box" interfaced aka superset with "BBwidget".  for a GUI.*/

/*If all your classes inherit all the properties of a BBwidget. Every lval_box can be placed on the screen, obey the graphical style rules, be resized, be dragged around, etc, according to the standard set by BBwidget system. The class hierarchy would look like below (Dr. made it sound better I just put my thoughts and experince with such technology down)*/

class lval_box : public BBwidget{/*...*/}; 	/*rewritten to use BBwidget*/
class lval_slider : public lval_box{/*...*/}; 	
class lval_dial : public lval_box{/*...*/}; 
class Flashing_ival_slider : public lval_slider{/*...*/};  	/*i know but i've been using l too much to swich to I know just act like you didn't see it*/
class Popup_ival_slider : public lval_slider{/*...*/}; 
