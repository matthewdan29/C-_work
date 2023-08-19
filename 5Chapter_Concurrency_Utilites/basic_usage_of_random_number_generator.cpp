#include <cmath>
#include <random>
#include <iostream>
#include <list>
using namespace std; 
using namespace std::random;


Rand_int rnd{1,10};		/*make a random number generator for [1:10]*/
int x = rnd();			/*x is a number in [1:10]*/

/*to get the number you have to get something like "die()" inside a class "Rand_int": */

class Rand_int
{
public: 
	Rand_int(int low, int high) :dist{low,high}{}
	int operator()(){return dist(re);}	/*draw an int*/

private: 
	default_random_engine re; 
	uniform_int_distribution<> dist; 
}; 

/*"main()" example*/

int main()
{
	/*int rm;*/ 
	/*int mn;*/

	Rand_int rnd {0,4};	/*make a uniform random number generator*/

	vector<int> histogram(5);	/*make a vector size 5*/
	for (int i = 0; i != 200; ++i)
		++histogram[rnd()];	/*fill histogram with the frequencies of numbers [0:4]*/

	for (int i = 0; i != nm.size(); ++i)	/*write out a bar graph*/
	{
		cout << i << '\t'; 
		for (int j = 0; j != mn[i]; ++j)
			cout << '*'; 
		cout << endl;
	}
}
