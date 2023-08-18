#include <iostream>

class Shape
{
	public: 
		virtual Point center() const = 0; /*pure virtual*/
		virtual void move(Point to) = 0; 

		virtual void draw() const = 0; 	/*draw on current "canvas"*/
		virtual void rotate(int angle) = 0; 

		virtual ~Shape(){}	/*destructor*/
}; 
/*This interface is an abstract class: as far as representation is concerned, nothing is common for every "Shape"*/

void rotate_all(vector<Shape*>&, int angle) /*rotate v's elements by angle degrees*/
{
	for (auto p : v)
		p->rotate(angle); 
}

/*To define a particular shape, one must say that it is a "shape" and specify its particular properties*/

class Circle : public Shape 
{
	public: 
		Circle(Point p, int rr); 	/*constructor*/

		Point center() const {return x;}
		void move(Point to){x = to;}

		void draw() const; 
		void rotate(int){}	/*nice simple algorithm*/

	private: 
		Point x;	/*center*/
		int r;		/*radius*/
}; 

class Smiley : public Circle /*use the circle as the base for face*/
{
	public: 
		Smiley(Point p, int r) : Circle{p,r}, mouth{nullptr}{}

		~Smiley()
		{
			delete mouth; 
			for (auto p : eyes)
				delete p;
		}

		void move(Point to); 

		void draw() const; 
		void rotate(int); 

		void add_eye(Shape* s){eyes.push_back(s); }
		void set_mouth(Shape* s); 
		virtual void wink(int i); /*wink eye number 'i'*/

	private: 
		vector<Shape*> eyes; 	/*usually two eyes*/
		Shape* mouth; 
}; 

/*Now you can define "Smiley::draw()" using calls to "Smiley" base and member "draw()"*/

void Smiley::draw()
{
	Circle::draw(); 
	for (auto p: eyes)
		p->draw(); 
	mouth->draw(); 
}











