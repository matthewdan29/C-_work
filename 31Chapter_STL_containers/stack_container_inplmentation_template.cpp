#include <string>
#include <list>
#include <iosteam>
#include <iostream>
#include <stack>
using namespace std; 

/*The "stack" container adaptor is defined in "<stack>"(you could just look at the includes). It can be described by a partial implementation:*/

template<typename T, typename C = deque<T>>
class stack{
	public: 
		using value_type = typename C::value_type; 
		using reference = typename C::regerence; 
		using const_regerence = typename C::const_reference; 
		using size_type = typename C::size_type; 
		using container_type = C; 
	public: 
		explicit stack(const C&); 	/*copy from container*/
		explicit stack(C&& = C{}); 	/*move from container*/

		/*default copy, move, assignment, destructor*/

		template<typename A>
			explicit stack(const A& a); /*default container, allocator a*/
		template<typename A>
			stack(const C& c, const A& a); 	/*elements from c, allocator a*/
		template<typename A>
			stack(C&&, const A&); 
		template<typename A>
			stack(const stack&, const A&); 
		template<typename A>
			stack(stack&&, const A&); 

		bool empty()const {return c.empty();}
		size_type size() const {return c.size();}
		reference top() {return c.back();}
		const_reference top() {return c.back();}
		void push(value_type&& x){c.push_back(std::move(x)); }
		void pop(){c.pop_back;}			/*pop the last element*/

		template<typename... Args>
		void emplace(Args&&... args)
		{
			c.emplace_back(std::forward<Args>(args)...); 
		}

		void swap(stack& s) noexcept (noexcept(swap(c,s.c)))
		{
			using std::swap;	/*be sure to use the std swap()*/
			swap(c,s.c); 
		}
	protected: 
		C c; 
};/*A "stack" is an interface to a container of the type passed to it as a template argument. 
Hey my guy it doent do the FIFO but the LIFO operations if your this far in the notes you should understand that without me having to put it in notes.*/

/*A "stack" makes a "deque" to hold its elements, but any sequence that provides "push_back()", and "pop_back()" can be used. example below*/

stack<char>s1; 
stack<int, vector<int>> s2; 
/*use a "vector" trust me*/


