#include <string>
#include <iostream>
#include <list>
#include <threads>
using namespace std; 

/*To launch tasks to potentially run asynchronously, you must use "async()"*/

double comp4(vector<double>& v)
	/*spawn many tasks if 'v' is large enough*/
{
	if (v.size() < 10000)
		return accum(v.begin(), v.end(), 0.0); 

	auto v0 = &v[0]; 
	auto sz = v.size(); 
		/*deviding up 10000 and setting a thread to each zone*/
	auto f0 = async(accum, v0, v0+sz/4, 0.0);	/*first quarter*/
	auto f1 = async(accum, v0+sz/4, v0+sz/2, 0.0);	/*second quarter*/
	auto f2 = async(accum, v0+sz/2, v0+sz*3/4, 0.0);/*third quarter*/
	auto f3 = async(accum, v0+sz*3/4, v0+sz, 0.0);	/*fourth quarter*/

	return f0.get()+f1.get()+f2.get()+f3.get();	/*collect and combine the results*/
}

/*"async()" separates the call part of a function call from the get the result part, and separates both from the actual execution of the task. */

/*dont use "async()" for task that share resources like Databases updateing and quering. */
