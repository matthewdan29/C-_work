#include <iostream>

/*Resource handles, such as "Vector" and "thread", an alternative to using pointers in many cases*/

std::vector<thread>my_threads; 

Vector init(int n)
{
	thread t 
	{
		heartbeat	/*run heartbeat concurrently (on thread)*/
	}; 

	my_threads.push_back(move(t));	/*move t into my_threads*/

	/*...*/

	Vector vec(n); 
	for (int i = 0; i < vec.size(); ++i)
		vac[i] = 777; 
	return vec; 		/*move "rec" out of "init()"*/
}

auto v = init(); 	/*start heartbeat and initialize 'v'*/
