/*The example below declares the 'C' and "C++" standard-library function "strcpy()" and specifies that it should be linked according to the 'C' linkage conversion. */
extern "C" char* strcpy(char*, const char*); 

/*The "extern 'C'" directive is particularly useful because of the colse relationship between 'C' and "C++" names a linkage convertion and not a language. Often, extern "C" is used to link Fortran and assemler routines that happen to conform to the convertions of a 'C' implementation. */

/*Adding "extern 'C'" top a lot of declarations can be a nuiesance. There is a mechanism to specify linkage to a group of declarations.*/
extern "C"{
	char* strpy(char*, const char*); 
	int strcmp(const char*, const char*); 
	int strlen(const char*); 
	/*...*/
}

/*The linkage block can be used to enclose a complete 'C' header to make a header suitble for "C++" use: example below*/
extern "C"{
	#include <string.h>
}

/*This technique is commonly used to produce a "C++" header from a 'C' header. Alternativly, contional compilation can be used to create a common 'C' and "C++" header:*/
#ifdef_cplusplus
extern "C"{
#endif
	char* strcpy(char*, const char*); 
	int strcmp(const char*, const char*); 
	int strlen(const char*); 
	/*...*/
#ifdef_cplusplus
}
#endif

/*Any declaration can appear within linkage block:*/
extern "C"				/*any declaration here, for example*/
{
	int g1; 			/*definition*/
	extern int g2; 			/*declaration, not definition*/
}
