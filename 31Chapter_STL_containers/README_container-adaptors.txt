Container adaptors are containers providing specialized interfaces to other contaniners. 
The default for a "priority_queue"'s priority function, "Cmp", is "std::less<T>"
The default for the container type, 'C', is "std::deque<T>" for "queue" and "std::vector<T>" for "stack" and "priority_queue". 

				Container Adaptors

	priority_queue<T,C,Cmp>			Priority queue of 'T's "Cmp" is 						the priority function type
	
	queue<T,C>				Queue of 'T's with "push()" and 						"pop()"

	stack<T,C>				Stack of 'T's with "push()" and 						"pop()"
