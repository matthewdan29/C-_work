#include <random>
#include <string>
#include <list>
#include <iostream>

/*Examples of distributions are "uniform_int_distribution" "normal_distribution" and "exponential_distribution"; each for some specified range.*/

using my_engine = default_random_engine;		/*type of engine*/
using my_distribution = uniform_int_distribution<>;	/*type of distribution*/

my_engine re {};				/*the default engine*/
my_distribution one_to_six{1,6};		/*distribution that maps to the ints 1...6*/
auto die = bind(one_to_six,re); 		/*make a denerator*/

int x = die();				/*roll the die: x becomes a value in [1:6]*/
