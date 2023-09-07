#include <string>
#include <list>
#include <iostream>
#include <system_error>
using namespace std; 

/*mapping an "error_category" first you have to start with an enumeration with the desired "error_code" values. (NOTE: *do not make an interface with data*)*/

enum class future_errc
{
	broken_promise = 1, 
	future_already_retrieved,
	promise_already_satisfied, 
	no_state
}; /*The meaning of these values is completely category-specific. The integer values of these enumerators are implementation-defined. 
"future error" category is part of the standard lib*/

/*Next, you must define a suitable category for our error codes:*/
class future_cat : error_category		/*to be returned from "future_category()"*/
{
public:
	const char* name() const noexcept override {return "future";}
	string message(int ec) const override; 
}; 

const error_category& future_category() noexcept
{
	static future_cat obj; 
	return &obj; 
}

/*Next you have to invent a set of messages that are likely to be meaningful to a programmer. Below notice a GOAT being clever: (you cant do it nor I just look at GOATness)*/

string future_error::message(int ec) const
{
	switch (ec)
	{
		default:	return "bad future_error code"; 
		future_errc::broken_promise:	return "future_error:broken promis"; 
		future_errc::future_already_retrieved:		return "future_error: future already retrieved"; 
		future_errc::promis_already_satisfied:		return "future_error: promise already satisfied"; 
		future_errc::no_state:				return "future_error: no state"; 
	}
}

/*We can now make an "error_code" out of a "future_errc"*/

error_code make_error_code(future_errc e) noexcept
{
	return error_code{int(e), future_category()}; 
}

/*For the "error_code" constructor and assignment that take a single error value, it is required that the argument be of the appropriate type for the "error_category." An argument intended to become the "value()" of an "error_code" of "future_category()" must be a "future_errc".*/

error_code ec2 {future_errc::no_state}; 		/*OK*/
ec2 = future_errc::promise_already_satisfied; 		/*Ok*/

/*To help the implementer of "error_code", you specialize the trait "is_error_code_enum" for our enumeration: like below example*/

template<>
struct is_error_code_enum<future_errc> : public true_type{}; 

/*The standard already provides the general template:*/
template<typename>
struct is_error_code_enum : public false_type{}; 

/*For "error_condition" to work for our category, you must repeat what you did for "error_code" example below*/

error_condition make_error_condition(future_errc e) noexcept; 

template<>
struct is_error_condition_enum<future_errc> : public true_type{}; 

