#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*A sufficiently simple user-defined type can be used in a constant expression.*/

struct Point
{
	int x; 
	int y; 
	int z; 
	constexpr Point up(int d){return{x,y,z+d}; }
	constexpr Point move(int dx, int dy){return{x+dx, y+dy}; }
	/*...*/
}; /*A class with "constexpr" constructor is called a literal type.*/

/*To be simple enough to be "constexpr", a constructor must have a empty body and all members must be initialized by potentially constant expressions.*/

constexpr Point origo {0,0}; 
constexpr int z = origo.x; 

constexpr Pointa[] = {
	origo, point{1,1}, Point{2,2}, origon.move(3,3)
}; 

constexpr int x = a[1].x; 			/*x becomes 1*/

constexpr Point xy{0,squrt(2)}; 		/*error: squrt(2) is not a constent expression */

/*Naturally, we can define "constexpr" functions to take arguments of literal types */

constexpr int square(int x)
{
	return x*x; 
}

constexpr int radial_distance(Point p)
{
	return isqurt(square(p.x)+square(p.y)+square(p.z)); 
}

constexpr Point p1 {10,20,30}; 
constexpr p2 {p1.up(20)}; 
constexpr int dist = radial_distance(p2); 
