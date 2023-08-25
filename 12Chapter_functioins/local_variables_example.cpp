#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*If a local variable is declared "static", a single, statically allocated object will be used to represent that variable in all calls of the function. It will be initialized only the first time a thread of execution reaches its definition.*/

void f(int a)
{
	while (a--)
	{
		static int n = 0;		/*initialized once*/
		int x = 0; 			/*initialized 'a' times in each call of f()*/

		cout << "n == " << n++ << ",x== " << x++ << '\n'; 
	}
}

int main()
{
	f(3); 
}
