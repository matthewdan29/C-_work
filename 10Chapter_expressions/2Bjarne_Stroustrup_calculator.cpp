#include <string>		/*strings*/
#include <iostream>		/*streams*/
#include <map>			/*map*/ 
#include <cctype>		/*isalpha()*/
#include <sstream>
using namespace std; 
/*second try*/
double prim(bool); 
double expr(bool); 
double term(bool); 
double error(string); 
map<string,double> table;
int main();
void calculate(); 
/*Token_stream ts{cin}; */
enum class Kind:char{
	name, number, end, 
	plus='+', minus='-', mul='*', div='/', print=';', assign='=', lp='(', rp=')' 
}; 

struct Token{
	Kind kind; 
	string string_value; 
	double number_value; 
}; 

class Token_stream
{
public:
	Token_stream(istream& s):ip{&s}, owns{false}{}
	Token_stream(istream* p):ip{p}, owns{true}{}

	~Token_stream(){close(); }

	Token get(); 				/*read and return next token*/
	/*Token* current();*/ 
	Token& current(); 			/*most recently read token*/ 

	void set_input(istream& s){close(); ip = &s; owns=false; }
	void set_input(istream* p){close(); ip = p; owns = true; }

private: 
	void close(){if(owns)delete ip;}

	istream* ip; 				/*pointer to an input stream*/
	bool owns; 		/*does the Token_stream own the istream*/
	Token ct{Kind::end}; 			/*current token*/	
}; Token_stream ts{cin}; 

double expr(bool get)				/*add and subtract*/
{
	double left = term(get); 
	/*ts.get();*/ 
	for (;;)
	{	 
		switch ( ts.current().kind)
		{
			case Kind::plus: 
				left += term(true); 
				break; 
			case Kind::minus: 
				left -= term(true); 
				break; 
			default: 
				return left; 
		}
	}
}

double term(bool get)
{
	double left = prim(get); 

	for (;;){
		switch (ts.current().kind){
			case Kind::mul:
				left *= prim(true); 
				break; 
			case Kind::div:
				if (auto d = prim(true)){
					left /= d; 
					break; 
				}
		return error("divide by 0"); 
	default:
		return left;
		}
	}
}


double prim(bool get)	
{
	if(get) ts.get(); 

	switch(ts.current().kind)
	{
		case Kind::number:
			{
				double v = ts.current().number_value; 
				ts.get(); 
				return v;
			}
		case Kind::name:
			{
				double& v = table[ts.current().string_value]; 
				if(ts.get().kind == Kind::assign) v = expr(true);
				return v;
			}
		case Kind::minus:
			return -prim(true); 
		case Kind::lp:
			{
				auto e = expr(true); 
				if(ts.current().kind != Kind::rp) return error("')' expected"); 
				ts.get(); 
				return e; 
			}
		default: 
			return error("primary expected"); 
	}
}

Token Token_stream::get()
{
	char ch = 0; 
	*ip >> ch; 

	switch (ch)
	{
		case 0: 
			return ct={Kind::end}; 
		case ';':
		case '*':
		case '/': 
		case '+': 
		case '-': 
		case '(':
		case ')': 
		case '=': 			/*Below*/
		/*here*/	return ct = {static_cast<Kind>(ch)}; /*here*/ 		/*return ct == {static_cast<Kind>(ch)}; */
						/*above*/
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.': 

		ip->putback(ch);		/*put the first digit back into the input stream*/
		*ip >> ct.number_value;		/*read number into ct*/
		ct.kind = Kind::number; 
		return ct; 
	default:
		if(isalpha(ch))
		{
			ip->putback(ch); 
			*ip >> ct.string_value; 
			ct.kind=Kind::name;
			return ct; 
		}
		error("bad token"); 
		return ct={Kind::print}; 
	}
}

int no_of_errors; 

double error(const string& s)
{
	no_of_errors++; 
	cerr << "error: " << s << '\n'; 
	return 1; 
}

/*Token_stream ts {cin};*/

void calculate()
{
	for(;;)
	{
		ts.get(); 
		if(ts.current().kind == Kind::end)break; 
		if(ts.current().kind == Kind::print) continue; 
		cout << expr(false) << '\n'; 
	}
}

int main()
{
	table["pi"] = 3.1415926535897932385; 
	table["e"] = 2.71828182845904523554; 

	calculate();
	
	return no_of_errors; 
}

/*int main(int argc, char* argv[])*/
/*{*/
	/*switch(argc)*/
	/*{*/
		/*case 1:*/ 
			/*break;*/ 
		/*case 2:*/ 
			/*ts.set_input(new istringstream{argv[1]}); */
			/*break;*/ 
		/*default:*/ 
			/*error("too many arguments"); */
			/*return 1; */
	/*}*/

	/*table["pi"] = 3.14;*/ 
	/*table["e"] = 2.7182818284590452354;*/ 

	/*calculate();*/ 
	
	/*return no_of_errors;*/ 
/*}*/
