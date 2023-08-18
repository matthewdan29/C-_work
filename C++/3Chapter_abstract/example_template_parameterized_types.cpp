#include <iostream>

/*You can generalize the sample vector-of-doubles type to a vector-of-anything 
 * by making it a "template" and replacing the specific type double */

template<typename T>
class Vector
{
private: 
	T* elem;	/*elem points to an array of sz elements of type 't'*/
	int sz; 
public: 
	Vector(int s);	/*constructor: establish invariant, acquire resources*/
	~Vector()
	{
		delete[] elem; 		/*destructor: release resources*/
	}

	/*copy and move operations */

	T& operator[](int i); 
	const T& operator[](int i) const; 
	int size() const 
	{
		return sz; 
	}
}
