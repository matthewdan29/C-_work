#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <list>
using namespace std; 

/*Below are examples of "remove()" and "unique()" operations for the standard library "list" class which is a doubley linked list*/

void use ()
{
	list<int> lst {2,3,2,3,5}; 
	lst.remove(3); 				/*lst is now "{2,2,5}"*/
	lst.unique(); 				/*lst is now "{2,5}"*/
	cout << lst.size() << '\n'; 		/*writes 2 */
}

/*The "merge()" algorithm is stable; that is, equivalent elements keep thier relative order.*/
/*A "splice()" operation does not copy elements values and does not invalidate iterators to elements. like the example below*/

list<int> lst1 {1,2,3}; 
list<int> lst2 {5,6,7}; 

auto p = lst1.begin(); 
++p; 					/*'p' points to 2*/

auto q = lst2.begin(); 
++q; 					/*'q' points to 6*/

lst1.splice(p,lst2); 			/*lst1 is now "{1,5,6,7,2,3}"; lst2 is now "{}"*/ /*NOTE: 'p' still points to 2 and 'q' still points to 6*/
