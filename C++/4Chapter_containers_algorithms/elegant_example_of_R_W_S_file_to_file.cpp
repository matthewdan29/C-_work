#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <set>
using namespace std; 

/*keeping strings in "set<string>" the abstract keeps it in order and does not keep duplicates*/
/*set<string> b {ii, eos};*/		/*colect strings from input*/
/*copy(b.begin(), b.end(), oo);	*/	/*copy buffer to output*/

int main()
{
	string from, to;
	cin >> from >> to;		/*get source and target file names*/

	ifstream is {from};		/*input stream for file "from"*/
	ofstream os {to};		/*output stream for life "to"*/

	set<string> b {istream_iterator<string>{is}, istream_iterator<string>{}};	/*read input*/
	copy(b.begin(), b.end(), ostream_iterator<string>{os, "\n"});			/*copy to output*/
	return !is.eof() || !os;						/*return error state*/
}

/*This is just about readability IDK if the set functions speed up or cause any change to the work load. */








/*Data struct and algo is very important. dont focus on langues or frameworks but the math and concepts that goven computer science. Also, you got to remember I have no degree and was only a intern for 4 weeks. I could be wrong about everything and not know it. */
