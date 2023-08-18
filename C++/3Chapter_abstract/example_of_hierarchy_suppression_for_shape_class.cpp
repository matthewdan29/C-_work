#include <iostream>

/*you dont know what the sub class that that your superclass fully is doing do best to suppress some functions. */
/*please remember most of these are just examples for best practice in creating you own classes.*/
class Shape
{
public: 
	Shape(const Shape&) = delete;		/*no copy operations*/
	Shape& operator=(const Shape&) = delete; 

	Shape(Shape&&) = delete;		/*no move operations*/
	Shape& operator=(Shape&&) = delete; 

	~Shape(); 
	/*rest of class functions*/	/*...*/
}; 

/*commit it out if your going to use the above code*/

/*Now the compiler will catch the attempt to copy or move 
 * If you need to copy an object in a class hierarchy, create a clone function.*/

/*example of lamdba functions in use for this type (you can ignore its for personal use)*/

template<class C, class Oper>
void for_all(C& c, Oper op)	/*assume that C is a contaioner of pointers*/
{
	for (auto& x : c)
		op(*x);		/*pass op() a reference to each element pointed to*/
}

/*You can now write a version of "user()" without writing a set of _all functions*/

void user()
{
	vector<unique_ptr<Shape>> v; 
	while (cin)
		v.push_back(read_shape(cin)); 
	for_all(v, [](Shape& s){s.draw();});	/*draw_all()*/
	for_all(v, [](Shape& s){s.rotate(45);}) /*rotate_all(45)*/
}

/*This pass a reference to "Shape" to a lambda so that the lambda doesn't have to care exactly how the objects are stored in the container. In particular, those "for_all()" calls would still work if i changed 'v' to a "vector<Shape*>".*/
