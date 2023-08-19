#include <string>
#include <iostream>
#include <list>
#include <threads>
using namespace std; 

/*If you ask "promise" by calling "get_future()", a "package_task" will give you the "future()" corresponding to its "promise()". You can set up two tasks to each add half of the elements of a "vector<double>" using the standard-library "accumulate()".*/

double accum(double* beg, double* end, double init)
	/*compute the sum of [beg:end) starting with the initial value init*/
{
	return accumulate(beg, end, init); 
}

double comp2(vector<double>& v)
{
	using Task_type = double(double* , double*, double);	/*type of task*/

	packaged_task<Task_type> pt0 {accum};		/*package the task*/
	packaged_task<Task_type> pt1 {accum}; 

	future<double> f0 {pt0.get_future()};	/*get hold of pt0's future*/
	future<double> f1 {pt1.get_future()};	/*get hold of pt1's future*/

	double* first = &v[0];
	thread t1 {move(pt0), first, first+v.size()/2,0};	/*start a thread for pt0*/
	thread t2 {move(pt1), first+v.size()/2, first+v.size(),0};	/*start a thread for pt1*/

	/*...*/

	return f0.get()+f1.get();
}

/*The "packaged_task" template takes the type of the task as its template argument and the task as its constructor argument.*/
/*The "move()" operations are needed because a "pacaged_task" cannot be copied.*/
