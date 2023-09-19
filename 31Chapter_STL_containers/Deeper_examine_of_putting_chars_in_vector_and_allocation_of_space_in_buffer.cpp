#include <string>
#include <list>
#include <iostream>
#include <vector>
using namespace std; 

/*There is not an allocation operation each time we add an element, but only every time we exceed capacity of the vector.*/
/*The notion of capacity allows for iterators into a "vector" to be valid unless a reallocation actually heappens. 
 * Consider reading letters into a buffer and keeping track of word boundaries:*/

vector<char>chars; 		/*input "buffer" for characters*/
constexpr int max = 20000; 
chars.reserve(max); 
vector<char*>words; 		/*pointers to start of words*/
vector<char*>words;		/*pointers to start of words*/

bool in_word = false; 
for(char c; cin.get(c))
{
	if(isalpha(c))
	{
		if(!in_word)	/*found begining of word*/
		{
			in_word = true; 
			chars.push_back(0); 		/*end of previous word*/
			words.push_back(&chars.back()); 
		}
		else 
			chars.push_back(c); 
	}
	else 
		in_word = false; 
}
if(in_word)
	chars.push_back(0); 		/*terminate last word*/

if(max<chars.size()>)		/*opps: chars grew beyond capacity; the words are invalid*/
{
	/*...*/
}
chars.shrink_to_fit(); 		/*release any surplus capactiy*/

/*Had Bjarne Stroustrup not used "reserve()" here, the pointers in words would have been invalideated if "chars.push_back()" caused a relocation.
 * By invalidated, he means that any use of those pointers would be undefined behavior. 
 * They may or may not pointer to elements, but almost certainly not to the elements they pointed to before the relocation.*/

