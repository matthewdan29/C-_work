#include <string>
#include <list>
#include <iostream>
#include <vector>
using namespace std; 

/*This is just a to how that "emplace_back()" and be used like "push_back()" to grow a stack like container or stack/quene */
/*assume that "re" and "im" are doubles*/

double re; 
double im; 

vector<complex<double>> vc; 
for(double re, im; cin >> re>>im;)		/*read two doubles*/
	vc.emplace_back(re, im); 		/*add complex<double>{re,im} at the end*/
