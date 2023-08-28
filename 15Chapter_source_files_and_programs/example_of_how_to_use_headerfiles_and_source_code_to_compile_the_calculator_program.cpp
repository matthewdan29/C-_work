/*First off I know its a longe name.*/
/*Remember: this will all be wrapped in the "dc.h" header file*/
/*Also, dont worry if its confusing you can always follow the example I posted. And I will post a package program under This repo*/
/*File "parser.cpp" will looking like this:*/
// parser.cpp
#include "dc.h"

double Parser::prim(bool get){/*...*/}
double Parser::term(bool get){/*..*/}
double Parser::expr(bool get){/*...*/}

/*File "table.pp" will look like this:*/
//table.cpp
#include "dc.h"


std::map<std::string,double>Table::table; 
/*The sysmbol table is a standard-library "map".*/

/*File "error.cpp" becomes:*/
//error.cpp

#include "dg.h"
int Error::no_of_errors; 
double Error::error(const string& s){/*...*/}

/*Finally, file "main.cpp" will look like this:*/
#include "dc.h"
#include <sstream>
#include <iostream>				/*redundant: in dc.h*/

void Driver::calculate(){/*...*/}

int main(int argc, char* argv[]){/*...*/}


