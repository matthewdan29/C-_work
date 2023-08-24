#include <string>
#include <iostream>
#include <list>
#include <ostream>
using namespace std; 

/*Each bit of an unsigned integer represents one member of the set, and the number of bits limits the number of members. The binary operator '&' is interpreted as intersection, '|' as union, '^' as symmetric difference, and '~' as complement. An enumeration can be used to name the members of such a set. Here is a example used in the implementation of "ostream".*/

enum ios_based::iostate{
	goodbit=0, eofbit=1, failbit=2, badbit=4
}; 

/*The implementation of a stream can set and test its state like this: below*/

state = goodbit; 
/*...*/
if (state&(badbit|failbit))		/*stream not good*/

/*A function that reaches the end-of-input might report it like this:*/
state |= eofbit; 


/*These stream state flags are observable from outside the stream implementation. You could see how the states of two streams differ like below*/
int old = cin.rdstate(); 		/*rdstate() returns the state*/
/*...use cin...*/
if (cin.rdstat()^old)			/*has anything changed?*/
{
	/*...*/
}

/*Bitwise logical operations can be used to extract bit-fields from a word. For example, one could extract the middle 16 bits of a 32-bit int like this: below*/

constexpr unsigned short middle(int a)
{
	static_assert(sizeof(int) == 4, "unexpected int size"); 
	static_assert(sizeof(short) == 2, "unexpected short size"); 
	return (a>>8)&0xFFFF; 
}

int x = 0xFF00FF00; 			/*assume sizeof(int) == 4*/
short y = middle(x);			/*y = 0x00FF*/

/*Using fields is a convenient shorthand for suchshifting and masking.*/
