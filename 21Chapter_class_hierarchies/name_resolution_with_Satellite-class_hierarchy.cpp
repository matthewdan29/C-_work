#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*Problem what if your abstract class is made up of 2 or more classes that might have the same nomenclature of a functions with different properties?*/

class Satellite
{
public: 
	virtual Debug_info get_debug(): 
		/*...*/
}; 

class Displayed
{
public: 
	virtual Debug_info get_debug(); 
	/*...*/
}; 

/*When the abstract class "Comm_sat()" uses "Satellite()" and "Displayed()" the virtual class "Debug_info get_debug()" needs to be disambiguated. example below*/

void f(Comm_sat& cs)		/*it not returning anything so think modifying the class "cs" which is of type object "Comm_sat" (at this point you got to start thing like a computer)*/
{
	di = cs.Satllite::get_debug(); 			/*OK*/
	di = cs.Displayed::get_debug(); 		/*OK*/
}

/*Personally I'm a fan of explicit but best practice is by defining a new function in the derived class:*/

class Comm_sat : public Satellite, public Displayed
{
public:
	Debug_info get_debug()		/*override Comm_sat::get_debug() and Displayed::get_debug()*/
	{
		Debug_info di1 = Satellite:get_debug(); 
		Debug_info di2 = Displayed::get_debug(); 
		return merge_info(di1, di2); 
	}
  /*...*/	
}; /*A function declared in a derived class overrides all functions of the same name and type in its base classes. 
     That is exactly the right thing to do because it is generally a bad idea to use the came name for operations with different smatics in a single class. 
The ideal for "virtual" is for a call to have the same effect independently of which interface was used to find the functions. */
