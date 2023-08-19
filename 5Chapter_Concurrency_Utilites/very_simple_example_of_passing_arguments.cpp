#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*A less obscure technique is to pass the input data by "const" reference and to pass the location of a place to deposit the result as a separate argument:*/

void f(const vector<double>& v, double* res);	/*take input from 'v' place result in *res */

class F
{
public: 
	F(const vector<double>& vv, double* p) : v{vv}, res{p}{}
	void operator()();		/*place result in *res*/

private: 
	const vector<double>& v;	/*source of input*/
	double* res;			/*target for output*/
}; 

int main()
{
	vector<double>some_vec; 
	vector<double>vec2; 
	/*...*/

	double rest1;
	double res2;		

	thread t1 {f, some_vec, &res1}	/*f(some_vec, &res1) executes in a separate thread*/
	thread t2 {F{vec2, &res2}};	/*F{vec2,&res2}() executes a separate thread*/

	t1.join();
	t2.join(); 

	cout << res1 << '' << res2 << '\n'; 
}


