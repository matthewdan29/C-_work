#include <string>
#include <list>
#include <iosteam>
using namespace std; 

/*The class "Comm_sat" is the definition of the simulated communication satellites:*/

class Comm_sat : public Satellite, public Displayed
{
	public: 
		/*...*/
}; 

/*In addition to whatever operations are defined specifically for a "Comm_sat", and "Displayed" can be applied. like the example below*/

void f(Comm_sat& s)
{
	s.draw(); 			/*Displayed::draw()*/
	Pos p = s.center(); 		/*Satellite::center()*/
	s.transmit(); 			/*Comm_sat::transmit()*/
}

/*A "Comm_sat" can be passed to a function that expects a "Satellite" and to a function that expects "Displayed." like example below*/
void highlight(Displayed*); 
Pos center_of_gravity(const Satellite); 

void g(Comm_sat* p)
{
	highlight(p); 			/*pass a pointer to the Displayed part of the "Comm_sat"*/
	Pos x = center_of_gravity(p); 	/*pass a pointer to the "Satellite" part of the "Comm_sat"*/
}

/*The implmentation of this clearly involves some compiler technique to ensure that functions expecting a "Satellite" see a different part of a "Comm_sat" than do functions expecting a "Displayed."
 * 
 * Virutal functions work as usual. example below: */

class Satellite
{
public: 
	virtual Pos center() const = 0; 		/*center of gravity*/
	/*...*/
}; 

class Displayed 
{
public: 
	virtual void draw() = 0; 
	/*...*/
}; 

class Comm_sat : public Satellite, public Displayed
{
public: 
	Pos center() const override; 		/*override Satellite::center()*/
	void draw() override; 			/*override Displayed::draw()*/
	/*...*/
}; /*This ensures that "Comm_sat::center()" and "Displayed::draw()" will be called for a "Comm_sat" treated as a "Comm_sat" and a "Displayed", respectively.*/
