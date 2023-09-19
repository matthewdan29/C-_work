#include <string>
#include <iostream>
#include <list>
#include <queue>
using namespace std; 

/*Look at the "stack" file most i will not repeat but REMEMBER: FIFO*/

/*many message based servers for systems are treated like such*/

void server(queue<Message>& q, mutex& m)
{
	while(!q.empty())
	{
		Message mess; 
		{
			lock_guard<mutex>lck(m); 	/*lock while extracting message*/
			if(q.empty()) return; 		/*somebody else got the message*/
			mess = q.front(); 
			q.pop(); 
		}
		/*server request*/
	}
}
