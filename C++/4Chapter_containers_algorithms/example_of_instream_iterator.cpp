#include <string>
#include <iostream>
#include <list>

/*Input iterators are used in pairs representing a sequence, so you must provide an "istream_iterator" to indicate the end of input. "istream_iterator" is the default instream iterator.*/

istream_iterator<string> eos {}; 

/*Note: "istream_iterators" and "ostream_iterators" are not used directly. Instead, they are provided as arguments to algorithms.*/
