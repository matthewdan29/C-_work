#include <string>
#include <list>
#include <iostream>
#include <list>
using namespace std; 

/*A simple macro is defined like below*/
#define NAME rest of line
/*where "NAME" is encountered as a token, it is replaced by "rest of line."*/


/*A macro can also be defined to take arguments*/
#define MAC(x,y) argument1: x argument2: y

/*When "MAC" is used, two argument strings must be presented. They will replace 'x' and 'y' when "MAC()" is expanded: example below */
expanded = MAC(foo bar, yuk yuk)
/*will be expanded into*/
expanded = argument1: foo bar argument2: yuk yuk

/*Macro names cannot be overloaded, and the macro preprocessor cannot handle recursive calls*/
#define PRINT(a,b) cout <<(a)<<(b)
#define PRINT(a,b,c) cout <<(a)<<(b)<<(c)		/*trouble?:redefines, does not overload*/

#define FAC(n)(n > 1)?n*FAC(n-1):1			/*trouble: recursive macro*/

/*Here are some plausible macros*/
#define CASE break; case
#define FOREVER for(;;)


/*If you must use a macro, use the scope resolution operator, ::, when referring to global names and enclose occurrences of a macro argument name in parentheses whenever possible. example below*/
#define MIN(a,b) (((a)<(b) ?(a):(b)))		/*Personaly If you see a project by Matthew doing this its because I want to be very very petty to the person that has to read my code to the point I most likly quiting the next week. so any future employers dont look at this file. */

/*example of MIN below in usage */
int x = 1; 
int y = 10; 
int z = MIN(x++, y++)			/*x becomes 3; y becomes 11*/

/*When writing a macro, it is not unusual to need a new name for something. A string can be created by concatenating two strings using the "##" macro operator. */
#define NAME2(a,b) a##b

int NAME2(hack, cah)(); 
/*will produce*/
int hackcah(); 

/*A single '#' before a parameter name in a replacement string mean a string containing the macro argument. */
#define printx(x) cout << #x "=" << x << '\n'; 

int a = 7; 
string str = "asdf"; 

void f()
{
	printx(a); 			/*cout << "a" << "=" << a << '\n'*/
	printx(str); 			/*cout << "str" << "=" << str << '\n'*/
}

/*Writing "#x" "=" rather than "#x << '='" is obscure "clever code" rather than an error. Adjacent string literals are concatednated.*/
/*The directive*/
#undef X
/*ensures that no macro called 'X' is defined - whether or not one was befor the directive. This affords som protection against undersired macros */

/*The argument list "("replacement list")" of a macro can be empty: */
#define EMPTY() std::cout << "empty\n"
EMPTY(); 					/*print"empty\n"*/
EMPTY; 						/*error: macro replacemnet list missing*/
