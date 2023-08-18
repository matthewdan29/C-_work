#include <iostream>

Vector::Vector(std::initializer_list<double>lst)   /*initialize with a list*/
	:elem{new double[lst.size()]}, sz{lst.size()}

{
	copy(lst.begin(), lst.end(), elem); 	/*copy from lst into elem*/
}
