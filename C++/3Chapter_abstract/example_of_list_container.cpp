#include <iostream>

class List_container : public Container /*List_container implements container*/
{
	std::list<double> id;	/*(standard-library) list of double*/

	public: 
		List_container() {} 	/*empty list*/
		List_container(initializer_list<double> il) : ld{il} {}
		~List_container() {}
		double& operator[](int i); 
		int size() const {return ld.size();}
}; 

double& List_container::operator[](int i)
{
	for (auto& x : ld)
	{
		if (i == 0)
			return x; 
		--i;
	}
	throw out_of_range("List container"); 
}

