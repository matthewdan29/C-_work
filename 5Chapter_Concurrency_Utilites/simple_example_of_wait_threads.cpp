#include <string>
#include <iostream>
#include <threads>
#include <list>
using namespace std::chrono;
using namespace std; 

auto t0 = high_resolution_clock::now();
this_thread::sleep_for(milliseconds{20}); 
auto t1 = high_resolution_clock::now();
cout << duration_cast<nanosecnds>(t1-10).count() << "nanoseconds passed\n"; 

/*two threads communicating by passing messages through a "queue".*/

class Message		/*object to be communicated*/
{
	/*...*/
}; 

queue<Message>mqueue;		/*the queue of messages*/
condition_variable mcond;	/*the variable communicating events*/
mutex mmutex;			/*the locking mechanism*/

/*The types "queue", "condition_variable", "mutex" are provided*/

/*The "consumer()" reads and processes "messages"*/

void consumer()
{
	while(true)
	{
		unique_lock<mutex> lck{mmutex};		/*acquire mmutex*/
		while(mcond.wait(lck)) /*waiting*/;	/*release lck and wait;*/
							/*re-acquire lck on wake*/
		auto m = mqueue.front();		/*get the message*/
		mqueue.pop();
		lck.unlock();				/*release lck*/

	}
}

/*Waiting on "condition_variable" releases its lock argument until the wait is over and then reacquires it.*/

/*The corresponding producer looks like below*/

void producer()
{
	while(true)
	{
		Message m; 
		/*fill the message...*/
		unique_lock<mutex> lck {mmutex};	/*protect operations*/
		mqueue.push(m);
		mcond.notify_one();		/*notify*/
						/*release lock (at end of scope)*/
	}
}


/*Using "condition_variable" supports many forms of elegant and efficient sharing but can be rather tricky.*/
