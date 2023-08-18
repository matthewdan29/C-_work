#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include <vector>
using namespace std; 

/*ostream_iterator<string> oo {cout};*/	/*writ strings to cout*/
/*istream_iterator<string> ii {cin};*/ 
/*istream_iterator<string> ii {cin};*/ 

/*This program write a simple program to read a file, sort the words read, eliminate duplicates, and write the result to another file. */

int main()
{
	string from, to;		
	cin>>from>>to;			/*get source and target file names*/
	
	ifstream is {from}; 		/*input stream for file "from"*/
	istream_iterator<string> ii {is};	/*input iterator for stream*/
	istream_iterator<string> eos {};	/*input sentinel*/

	ofstream os {to}; 		/*output stream for file "to"*/
	ostream_iterator<string> oo {os,"\n"};	/*output iterator for stream*/
	vector<string> b {ii, eos};	/*'b' is a vector initialized from input [ii:eos)*/

	unique_copy(b.begin(), b.end(), oo);	/*copy buffer to output, discard replicated values*/

	return !is.eof() || !os;		/*return error state*/
}

/*An "ifstream" is an "istream" that can be attached to a file, and an "ofstream" is an "ostream" that can be attached to a file. The "ostream_iterator" second argument is used to delimit output values. */
