#include <string>
#include <list>
#include <iostream>
#include <Cstring>
using namespace std; 

/*One use of macros is almost impossible to avoid. The directive*/
#ifdef IDENTIFIER

/*does nothing if "IDENTIFIER" is defined, but if it is not, the directive causes all input to be ignored until a #endf directive is seen: example below*/
int f(int a #ifdef arg_two, int b #endif); 

/*unless a macro called "arg_two" has been "#defined", this produces*/
int f(int a); 
/*most uses of "#ifdef" are less bizarre, and when used with restraint, "#ifdef" and its complement "#ifndef" do little harm*/

/*"#pragma"*/
#pragma foo bar 666 foo bar 
/*if possible, "#pragma" are best avoided */
