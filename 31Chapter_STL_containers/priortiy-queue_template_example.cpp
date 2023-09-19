#include <string>
#include <list>
#include <iostream>
#include <queue>
using namespace std; 

/*I'm going to go as far as to say IF YOUR READING THIS ITS TO LATE joking but i'm pretty sure you know what a priority_queue abstract class*/

template<typename T, typename C = vector<T>, typename Cmp = less<typename C::value_type>>
class priority_queue
{
	protected: 
		C c; 
		Cmp comp; 
	public: 
		priority_queue(const Cmp& x, const C&); 
		explicit priority_queue(const Cmp& x = Cmp{}, C&& = C{}); 
		template<typename In>
			priority_queue(In b, In e, const Cmp& x, const C& c); 
		/*...*/
}; 

/*By default, The "priority_queu" simply compares elements using the '<' operator, and the "top()" returns the largest elements*/

struct Message 
{
	int priority; 
	bool operator<(const Message& x)const {return priority < x.priority;}
	/*...*/
}; 

void server(priority_queue<Message>& q, mutex& m)
{
	while(!q.empty())
	{
		lock_guard<mutex> lck(m); 	/*hold lock while extracting message*/
		if(q.empty())return; 		/*somebody else got the message*/
		mess = q.top(); 
		q.pop(); 

	}
	/*serve highest priority request*/
}

/*moral of the story when creating your large application use a C++ vector or in your driver create a data structure out from C it will be faster. Albeit, if you have not mastered data structures in C DO NOT SHOT YOUR SELF IN THE FOOT in your driver. You might be best off using something from the C++ library but giving that don't even try to make your own salting function.*/
