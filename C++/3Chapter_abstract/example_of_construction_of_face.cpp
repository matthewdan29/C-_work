#include <iostream>

/*This function that reads data describing shapes from an input stream and sconstructs the appropriate "shape" objects: */

enum class Kind 
{
	circle, triangle, smiley
}; 

shape* read_shape(istream& is) /*read shape descriptions from input stream is*/
{	/*...read shape header from is and find its Kind k...*/
	switch(k)
	{
		case Kind::circle: 
			/*read circle data {Point, init} into p and r*/
			return new Circle{p,r}; 
		case Kind::triangle: 
			/*read triangle data {point, point, point} into p1, p2, p3*/
			return new Triangle{p1, p2, p3}; 
		case Kind::smiley: 
			/*read smiley data {point, int, shape, shape, shape} into p, r, e1, e2, and m*/
			Smiley* ps = new Smiley{p,r}; 
			ps->add_eye(e1); 
			ps->add_eye(e2); 
			ps->set_mouth(m); 
			return ps; 
	}
}

/*A program may use that shape reader like this:*/
void user()
{
	std::vector<Shape*> v; 
	while(cin)
		v.push_back(read_shape(cin)); 
	draw_all(v);		/*Call draw() for each element*/
	rotate_all(v, 45); 	/*call rotate(45) for each element*/
	for (auto p : v)
		delete p;	/*remember to delete elements */
}

/*lets be read this is very simple compare to Data Structures and Algo in C*/
