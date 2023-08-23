#include <string>		/*strings*/
#include <iostream>		/*strings*/
#include <list>
#include <vector>
#include <map>			/*map*/
#include <cctype>		/*isalpha()*/
using namespace std; 

/*NOTE: this isn't broken up because that is how he desired the learning process is going. although he notes the sintext of naming a function that in a different file before being used. If you look at the first C repo posted you well see it a lot because most of the main()'s was called before the functions.*/
map<string,double> table; 
double expr(bool); 
double term(bool);

enum class Kind : char
{
	name, number, end, 
	plus='+', minus='-', mul='*', div='/', print=';', assign='=', lp='(', rp=')'
}; 

struct Token
{
	Kind kind; 
	string string_value; 
	double number_value; 
}; Token ts; 

double expr(bool get)			/*add and subtract*/
{
	double left = term(get); 

	for (;;)			/*forever*/
	{
		switch (ts.current().kind)
		{
			case Kind::plus: 
				left += term(true); 	/*incase of add*/
				break; 
			case Kind::minus: 
				left -= term(true); 	/*incase of subtract*/
				break; 
			default: 
				return left; 		
		}
	}
}


double term(bool get)	/*multiply and divide*/
{
	double left = prim(get); 

	for (;;)
	{
		switch (ts.current().kind)
		{
			case Kind::mul: 
				left *= prim(true); 
				break; 
			case Kind::div: 
				if (auto d = prim(true))
				{
					left /= d; 
					break; 
				}
				return error("divide by 0"); 
			default: 
				return left; 
		}
	}
}

double prim(bool get)			/*handle primaries*/
{
	if (get) ts.get();		/*read next token*/

	switch (ts.current().kind)
	{
		case Kind::number: 	/*floating-point constant*/
			{
				double v = ts.current().number_value; 
				ts.get(); 
				return v; 
			}
		
		case Kind::name: 
			{
				double& v = table[ts.current().string_value]; 	/*find the corresponding*/
				if (ts.get().kind == Kind::assign) 
					v = expr(true); 			/*'=' seen: assignment*/
				return v; 
			}
		case Kind::minus: 			/*unary minus*/
			return -prim(true); 
		case Kind::lp: 
			{
				auto e = expr(true); 
				if (ts.current().kind != Kind::rp)
					return error("')' expected"); 
				ts.get(); 				/*eat ')'*/
				return e; 
			}
		
		default: 
			return error("primary expected"); 
	}
}

class Token_stream
{
public: 
	Token_stream(istream& s) : ip{&s}, owns{false}{}	/*not passed by reference*/
	Token_stream(istream* p) : ip{p}, owns{true}{}		/*Yes, passed as a pointer*/

	~Token_stream() {close(); }

	Token get(); 			/*read and return next token*/
	Token& current(); 		/*most recently read token*/

	void set_input(istream& s) {close(); ip = &s; owns=false; }
	void set_input(istream* p) {close(); ip = p; owns = true; }

private: 
	void close() {if (owns) delete ip; }
	
	istream* ip; 				/*pointer to an input stream*/
	bool owns; 				/*does the Token_stream own the stream?*/
	Token ct {Kind::end};			/*current token*/
}; Token_stream ts; 

Token Token_stream::get()
{
	char ch = 0; 
	char ch; 
	*ip >> ch; 
	/*.....*/
	/*do*/ 
	/*{*/					/*skip whitespace except '\n'*/
		/*if (!ip->get(ch))*/
			/*return ct = {Kind::end};*/ 
	/*}	while(ch != '\n' && isspace((ch))); */

	switch (ch)
	{
		/*case';':*/

		/*case '\n': */
			/*return ct={Kind::print};*/
		       /*...*/	
		case 0: 
			return ct = {Kind::end};	/*assign and return*/

		case ';': 		/*end of expression; print*/
		
		case '*': 

		case '/': 

		case '+': 

		case '-': 

		case '(': 

		case ')': 

		case '=': 
			
			return ct == {static_cast<Kind>(ch)}; 

		case '0': case '1': case '2': case '3': case '4': case '5': case'6': case '7': case '8': case '9': case '.': 
			ip->putback(ch);		/*put the first digit (or .) back into the input stream*/
			*ip >> ct.number_value; 	/*read number into ct*/
			ct.kind=Kind::number; 
			return ct; 
		default: 
			if(isalpha(ch))
			{
				string_value = ch; 
				while (ip->get(ch) && isalnum(ch))
					string_value += ch; /*append ch to end of string_value*/
				ip->putback(ch); 
				return ct = {Kind::name}; 
				/*ip->putback(ch);*/ 	/*put the first character back into the input stream*/
				/**ip >> ct.string_value;*/ 	/*read string into ct*/
				/*ct.kind=Kind::name;*/ 
				/*return ct;*/ 
			}
			error("bad token"); 
			return ct = {Kind::print}; 
	}
}

int no_of_errors; 

double error(const string& s)
{
	no_of_errors++; 
	cerr << "error: " << s << '\n'; 
	return 1; 
}

Token_stream ts {cin}; 				/*use input from cin*/

void calculate()
{
	for(;;)
	{
		ts.get(); 
		if (ts.current().kind::end)
			break; 
		if (ts.current().kind == Kind::print)
			continue; 
		cout << expr(false) << '\n'; 
	}
}

int main()
{
	table["pi"] = 3.1415926535897932385; 		/*insert predefined names*/
	table["e"] = 2.7182818284590452354; 		
	
	calculate(); 

	return no_of_errors; 
n}
