/*For each C standard-libary header "<X.H>" there is a correspoinding standard "C++" header "<cX>". 
 * For example, "#include<ctdio>" provides what "#include<stdio.h>" does. 
 * A typical "stdio.h" will look something like this */

#ifdef_cplusplus		/*for C++ compilers only*/
namespace std {			/*the standard library is defined in namespace std. */
extern "C"{			/*stdio function  s have C linkage*/
#endif 				
/*...*/ 
	int printf(const char*, ...); 
	/*...*/
#ifdef_cplusplus 
}
}
/*...*/
using std:: printf; 		/*make printf available in global namespace */
/*...*/
#endif

/*That, is the actual declarations are shared, but linkage and namespace issues must be addressed to allow 'C' and "C++" to share a header. 
 * The macro "_cplusplus"is defined by the "C++" compliler and can be used to distinguish "C++" code from code intended for a 'C' compiler.*/
