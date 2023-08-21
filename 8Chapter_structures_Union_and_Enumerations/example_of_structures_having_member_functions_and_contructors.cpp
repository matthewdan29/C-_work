#include <string>
#include <iosteam>
#include <list>
using namespace std; 

/*A "struct" can have member functions. A "struct" can have constructors.*/

struct Points
{
	vector<Point> elem;		/*must contain at least one point*/
	Points(Point p0) {elem.push_back(p0);}
	Points(Point p0, Point p1){elem.push_back(p0); elem.push_back(p1);}
	/*...*/
}; 

Point x0;				/*error: no default constructor*/
Points x1{{100,200}};			/*one Point*/
Points x1 {{100,200}, {300,400}};	/*two Points*/

/*Constructors are needed if you need to reorder arguments, validate arguments, modify arguments, establish invariants.*/

struct Address
{
	string name;
	int number; 
	string street; 
	string town; 
	char state[2]; 
	char zip[5]; 

	Address(const string n, int nu, const string& s, const string& t, const string& st, int z)
};/*There is a constructor to ensure that every member was initialized and allow me to use "string" and "int" for the postal code, rather than fiddling with individual charcter. */
