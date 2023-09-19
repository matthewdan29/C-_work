#include <string>
#include <list>
#include <iostream>
#include <vector>
using namespace std; 

/*IMPORTANT: unless you have a good reason not to use "vector" class as your container*/
/*Given the importance of "vector" this file takes a second look with more emphasis on how the operations are provided*/
/*The "vector"'s template argument and member types are defined like below.*/

template<typename T, typename Allocator = allocator<T>>
class vector
{
	public:
		using reference = value_type&; 
		using const_reference = const value_type&; 
		using iterator = /*implementation-defined*/; 
		using const_iterator = /*implementation-defined*/; 
		using size_type = /*implementation-defined*/; 
		using value_type = Allocator; 
		using pointer = typename allocator_traits<Allocator>::pointer; 
		using const_pointer = typename allocator_traits<Allocator>::const_pointer; 
		using reverse_iterator = std::reverse_iterator<iterator>; 
		using const_reverse_iterator = std::reverse_iterator<const_iterator>; 
		/*...*/
	       
}; 
