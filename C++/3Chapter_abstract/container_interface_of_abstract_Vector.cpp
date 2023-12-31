#include <iostream>

class Container 
{
	public: 
		virtual double& operator[](int) = 0;	/*pure virtual func*/
		virtual int size() const = 0;	/*const member function*/
		virtual ~Container() {}		/*destructor*/
}
