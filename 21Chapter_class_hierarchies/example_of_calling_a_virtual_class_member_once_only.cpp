#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*The programmer can simulate the scheme used for constructors by callsing a virtual base class function only from the most derived class. IFF when defining the functioins for a class with a virtual base, the programmer in general can wants to know whether the base will be shared with other derived classes.*/

/*Assume below the base "Window" class knows how to draw its contents.*/
class Window
{
public: 
	/*basic stuff*/
	virtual void draw(); 
}; 

/*Next, you have various ways of decorating a window and adding facilities:*/

class Window_with border : public virtual Window
{
	/*border stuff*/
protected: 
	void own_draw(); 		/*display the border*/
public: 
	void draw() override; 
}; 

class Window_with_menu : public virtual Window
{
			/*menu stuff*/
protected: 
	void own_draw(); 		/*display the menu*/
public: 
	void draw() override; 
}; 

/*From this, we can compose a plausible "Clock" class*/

class Clock : public Window_with_border, public Window_with_menu
{
			/*clock stuff*/
protected: 
	void own_draw(); 		/*display the clock face and hands*/
public: 
	void draw() override; 
}; 

/*The "draw()" functions can now be defined using the "own_draw()" functions, so that a caller if any "draw()" gets "Window::draw()" invoked exactly once. This is done independently of the kind of "Window" for which "draw()" is invoked*/

void Window_with_border::draw()
{
	Window::draw(); 
	own_draw(); 				/*display the border*/
}

void Window_with_menu::draw()
{
	Window::draw(); 
	own_draw(); 				/*display the menu*/
}

void Clock::draw()
{
	Window::draw(); 
	Window_with_border::own_draw(); 
	Window_with_menu::own_draw(); 
	own_draw(); 				/*display the clock face and hands*/
}/*The qualified call, such as "Window::draw()", does not use the virtual call mechanism. 
It directly calls the explicitly named function, thus avoiding nasty infinite recursion.*/
