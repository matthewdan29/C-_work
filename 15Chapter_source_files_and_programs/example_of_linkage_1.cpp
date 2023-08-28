/*It is the programmer's task to ensure that every namespace, class, function, etc., is properly declared in every translation unit in which it appears and that all declarations referring to the same entity are consistant. Below consider two file: */

/*file1.cpp*/
int x = 1; 
int f() {/*do something*/}

/*file2.cpp*/
extern int x; 
int f(); 
void g() {x=f()}; 

/*The 'x' and "f()" used by "g()" in "file2.cpp" are the ones defined in "file1.cpp". The keyword "extern" indicates that the declaration of 'x' in "file2.cpp" is a declaration and not a definition. Had 'x' been initialized, "extern" would simply be ingnored because a declartion with an initializer is always a definition. An object must be defined exactly once in a program. It may be declared many times, but the type must agree exactly. example of such below */

/*file1.cpp*/
int x = 1; 
int b = 1; 
extern int c; 

/*file2.cpp*/
int x; 					/*means "int x = 0;"*/
extern double b; 
extern int c; 

/*The 3 erros: 'x' i sdefined twice, 'b' is declared twice with different types, and 'c' is declared twice but not defined. */

/*NOTE:keyword "static" means "not accessible from other source files"*/

/*The keyword "const" implies default internal linkage, so if you want "x2" to have external linkage, you need to precede its definitions with extern*/

int x1 = 1; 			/*extern linkage: accessible from other trnslations units*/
extern const char x2 = 'a'; 	/*extern linkage: accessible from other translation units*/
