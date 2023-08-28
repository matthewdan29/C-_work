/*"include" header files constaing interface information in source files containg executable code and/or data definitions is one imperficet but simple method of acheiing consistency for delcarations in different translations units. 
 * The "include" mechanism is a text manipulation facility for gathering source program fragments togeather into a single unit(file) for compilation. consider below */

#include "to_be_included"
/*The "#include"-directive replaces the line in which the "#include" appears with the contents of the file "to_be_included." The content of "to_be_included" should be "C++" source text because the compiler will proceed to read it. */

/*To include standard-library header, use '<' and '>', around the name instead of quotes. */

#include <iostream>				/*from standard include directory*/
#include "myheader.h"				/*from current directory*/
			/*far as i know the same goes for C*/


