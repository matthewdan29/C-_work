#include <array>
#include <string>
#include <list>
using namespace std; 

/*You can have arrays of "struct" and "struct" containing arrays*/

struct Point
{
	int x; 
	int y; 
};

Point points[3]{{1,2},{3,4},{5,6}}; 
int x2 = points[2].x; 


struct Array
{
	Point elem[3]; 
}; 

Array points2 {{1,2},{3,4},{5,6}}; 
int y2 = points2.elem[2].y; 

/*Placeing a built-in array in a "struct" allows us to treat that array as an object. We can copy the "struct" containing it in initialization and assignment.*/

Array shift(Array a, Point p)
{
	for (int i = 0; i != 3; ++i)
	{
		a.elem[i].x += p.x; 
		a.elem[i].y += p.y; 
	}
	return a; 
}

Array ax = shift(points2,{10,20}); 

/*The standard library provides "std::array" as a more complete and elegant development of the idea of a fixed-size array as a "struct"*/

template<typename T, size_t N>
struct array			
{
	T elem[N]; 

	T* begin() noexcept {return elem; }
	const T* begin() const noexcept {return elem;}
	T* end() noexcept {return elem+N;}

	constexpr size_t size() noexcept; 

	T& operator[](size_t n){return elem[n];}
	const T& operator[](size_type n) const {return elem[n];}

	T* data() noexcept {return elem; }
	const T* data() const noexcept {return elem; }

	/*...*/
}; /*This "array" is a template to allow arbitrary number of elements of arbitrary types */


/*Using "array," you can now write*/

struct Point
{
	int x; 
	int y; 
}; 

using Array = array<Point, 3>;			/*array of 3 points*/

Array points {{1,2}, {3,4}, {5,6}}; 
int x2 = points[2].x; 
int y2 = points[2].y; 

Array shift(Array a, Point p)
{
	for (int i = 0; i != a.size(); ++i)
	{
		a[i].x += p.x; 
		a[i].y += p.y; 
	}
	return a; 
}

Array ax = shift(points, {10,20}); 


