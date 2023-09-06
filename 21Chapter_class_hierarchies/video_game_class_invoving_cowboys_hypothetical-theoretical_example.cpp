#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*Consider the example of a class of a "draw()" member function in a video game involving cowboys below.*/

class Window
{
public:
       void draw(); 			/*display image*/
	/*...*/       
}; 

class Cowboy
{
public: 
	void draw(); 			/*pull gun from holster*/
	/*...*/
}; 

class Cowboy_window : public Cowboy, public Window
{
	/*...*/
}; 

/*How do we override "Cowboy::draw()" and "Window::draw()"? The two functions have radically different meaning (sematics) but are identical in name and type; you need to override them by two separate functions. there is no direct language solution to this (exotic) problem, but adding intermediate classes will do: like below*/

struct WWindow : Window
{
	using Window::Window; 			/*inherit constructors*/
	virtual void win_draw() = 0; 		/*force derived class to override*/
	void draw() override final{win_draw();}	/*display image*/
}; 

struct CCowboy : Cowboy
{
	using Cowboy::Cowboy; 			/*inherit constructors*/
	virtual void cow_draw() = 0; 		/*force derived class to override*/
	void draw() override final {cow_draw();}	/*pull gun from holster (Side Note: if you played the popular game Red Dead Redemption 2 this code brings a little more importance to learning C++)*/
}; 

class Cowboy_window : public CCowboy, public WWindow
{
public: 
	void cow_draw() override; 
	void win_draw() override; 
	/*...*/
}; 
/*If the developer designed "Window" been a bit more carefule and specified "draw()" to be const, the whole problem would have evaporated. That's fairly typical*/
