#include <iostream>

/*function object or functor, is used to define objects that can be called like functions. */

template<typename T>
class Less_than
{
	const T val;	/*value to compare against*/

public: 
	Less_than(const T& v):val(v){}
	bool operator()(const T& x) const
	{
		return x < val;		/*call operator is "operator()"*/
	}
}; 

/*you can define named variables of type "Less_than" for some argument type:*/
Less_than<int> lti{42};		/*lti(i) will compare 'i' to 42 using <(i<42)*/
Less_than<string>lts{"Backups"}; 	/*lts(s) will compare 's' to "Backus" using <(s<"Buakus")*/

/*You can call such an object, just as you can call a function.*/
void fct(int n, const string & s)
{
	bool b1 = lti(n);	/*true if "n<42"*/
	bool b2 = lts(s);	/*true if s<"Backus"*/
	/*.... */
}

/*now you can count the occurrences of calues for which a predicate returns "true"*/

template<typename C, typename P>
int count(const C& c, P pred)
{
	int cnt = 0; 
	for (const auto& x : c)
		if (pred(x))
			++cnt; 
	return cnt; 
}

/*A predicate is something that you can invoke to return "true" or "false"*/
void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
	cout << "number of values less than" << x <<":" << count(vec, Less_than<int>{x}) << '\n'; cout << "number of values less than" << s << ":" << count(lst, Less_than<string>{s}) << '\n'; 
}


/*This is a lot so if you are taking the depaul class that teaches "C++" let me know I'll commit whats going on next to the commits */
/*its probly best to use a fake accout to contact me on social media lol I dont make the smartest post*/

/*Important take from this 
 * Function objects used to specify the meaning of key operations of a general algorithm are often referred to as "policy objects"
 *
 * Also, I'm going to save the "f()->(a)(b)" lambda function. for when its explained better in chapter 11. I want to isolate the issue for better explaination basiclly I dont want to send you off with a lot of infomation.*/

/*the notation "[&](int a){return a<x}" is the "lambda expresstion" it generates a function object exactly like "Less_than<int>{x}". The "[&]" is a capture list specifying the local names used (such as x) will be passed by reference.*/
