#include <string>
#include <list>
#include <iostream>
#include <threads>
using namespace std; 

/*This is a collegection if your coming from java think of the colection library*/

/*that is a collecetion of values, rather that an object of a class with a well defined semantics and invariant for its value.*/

tuple<string, int, double> t2("Sild", 123, 3.14); 	/*The type is specified*/

auto t = make_tuple(string("Herring"), 10, 1.23); 	/*they type is deduced*/
							/*t is a tuple<string, int, double>*/

string s = get<0>(t); 		/*get first element of tuple*/
int x = get<1>(t); 
double d = get<2>(t); 

/*The elements of a tuple are numbered,*/
