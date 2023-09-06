#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*we might have designed "Satellite" and "Displayed" as our interface classes, providing a "mapping layer" for our higher-level classes to use:*/

class Satllite : public SimObj
{
	/*map "SimObj" facilites to something easier to use for "Satellite" simulation*/
public: 
	virtual Debug_info get_debug(); 	/*call "SimObj::DBinf()" and extract information*/
	/*...*/
}; 

class Displayed : public Widget
{
	/*map "Widget" facilities to something easier to use to display satellite simulation results*/
public: 
	virtual Debug_info get_debug(); 		/*read Widget data compos Debug_info*/
	/*...*/
}; 
