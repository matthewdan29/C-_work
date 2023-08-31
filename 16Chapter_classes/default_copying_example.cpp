#include <list>
#include <string>
#include <iostream>
using namespace std; 

/*This has already been talked about in "DIR" before so this is a small example*/
/*REMEMBER: use pointer to move or copy big structs or classes that have lots of data to save resources. say if your using a struct to manipulate files or sockets or both for computers to talk to each other*/

Date d1 = my_birthday; 			/*initialization by copy*/
Date d2 {my_birthday}; 			/*initialization by copy*/
