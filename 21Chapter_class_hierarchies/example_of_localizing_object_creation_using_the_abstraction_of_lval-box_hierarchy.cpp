/*As of now the creation of objects must be dont using implementation-specific names lke "CW_ival_dail" and "BB_flashing_ival_slider"
 * To minimize the number of places where such specific names occur, and object creation is hard to localize unless it is done systematically.
 * The solustion is to introduce an indirection. 
 * First, is a simple method. To introduce an abstract class to represent the set of creation operations: example below*/

class lval_maker
{
public: 
	virtual lval_dial* dial(int, int) = 0; 			/*make dial*/
	virtual Popup_ival_slider* popup_slider(int, int) = 0;	/*make popup slider*/
	/*...*/
}; /*For each interface from the "lval_box" family of classes that a user should know about, class "lval_maker" provides a function that makes an object. 
Such a class is called a "FACTORY" (imporatant topic in OOP), and its functions are sometimes called "virtual constructors". 
*/

/*We now represent each user-interface system by a class derived from "lval_maker":*/

class BB_maker : public lval_maker		/*make "BB" versions*/
{
public: 
	lval_dial* dial(int, int) override; 
	Popup_ival_slider* popup_slider(int, int) override; 
	/*...*/
}; 

class LS_maker : public lval_maker		/*make LS versions*/
{
public: 
	lval_dial* dial(int, int) override; 
	Popup_ival_slider* popup_slider(int, int) override; 
	/*...*/
}; 

/*Each function creates an object of the desired interface and implementation tyype. For example:*/
lval_dial* BB_maker::dial(int a, int b)
{
	return new BB_ival_dial(a,b); 
}

lval_dial* LS_maker::dial(int a, int b)
{
	return new LS_ival_dial(a,b); 
}

/*Given an "lval_maker", a user can now create objects without having to know exactly which userinterface system is used. example below*/
void user(lval_maker& im)
{
	unique_ptr<lval_box>pb{im.dial(0,99)}; 	/*create appropriate dail*/
	/*...*/
}

BB_maker BB_impl; 				/*for BB users*/
LS_maker LS_impl; 				/*for LS users*/

void driver()
{
	user(BB_impl); 				/*use BB*/
	user(LS_impl); 				/*use LS*/
}/*Passing arguments to such "virtual constructors" is a bit tricy. 
   You cannot override the base class functions that represent the interface with different arguments in diiferent derived classes.
   This implies that a fair bit of forsight is required to design the factory class's interface.*/

/*Side Note: 
 * 	Shared interfaces: leads to less replication of code using classes and making such code more uniform. This is often called "run-time polymorphism" or "interface inheritance" Personally by now you can tell which one I use unless I'm trying to troll someone
 * 	
 * 	Shared implementation: leads to less code and more uniform implementation code. This is often called "implementation inheritance".*/

