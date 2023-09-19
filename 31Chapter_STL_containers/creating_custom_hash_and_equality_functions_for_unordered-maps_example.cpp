#include <string>
#include <iostream>
#include <map>
#include <iostream>
using namespace std; 

/*This file will show you examples of how to define you own custom hash function
 * I you want to know how important this is ask any company thats been hack how important it is to salt records in encrption (dont thats a troll). 
 * Here is presented several versions, starting with the most explicit and ending with the simplest. 
 * 	Consider a simple "Record" type struct*/

struct Record 
{
	string name; 
	int val; 
}; 

/*You can define "Record" hash and equality operations like below.*/

struct Nocase_hash
{
	int d = 1;	/*shift code 'd' number of bit in each iteration*/

	size_t operator()(const Record& r) const 
	{
		size_t h = 0; 
		for(auto x : r.name)
		{
			h <<= d; 
			h ^= toupper(x); 
		}

		return h; 
	}
};

struct Nocase_equal 
{
	bool operator()(const Record& r, const Record& r2) const
	{
		if(r.name.size()!=r2.name.size()) return false; 
		for(int i = 0; i < r.name.size(); ++i)
			if(toupper(r.name[i])!=toupper(r2.name[i]))
				return false; 
		return true; 
	}
}; 

/*You now have to option to define and used an "unordered_set" of "Records": like below.*/

unordered_set<Record,Nocase_hash,Nocase_equal> m 
{
	{{"andy",7},{"al",9},{"bill",-3},{"barbara",12}},
	Nocase_hash{2},
	Nocase_equal{}
}; 

for (auto r : m)
	cout << "{" << r.name << ',' << r.val << "}\n"; 

/*As in most common, you wanted to use the default values for the hash and equality functions, you could do that by simply not mentioning them as constructor arguments. 
 * By default the "unordered_set" uses the default versions:*/

unordered_set<Record,Nocase_hash,Nocase_equal> m 
{
	{"andy",7}, {"al",9}, {"bill",-3}, {"barbara",12}
	/*use Nocase_hash() and Nocase_equal{}*/
}; 

/*The easiest way of writing a hash function is to use the standard-library hash functions provided as specializeation of "hash" example below.*/

size_t hf(const Record& r)
{
	return hash<string>()(r.name)^hash<int>()(r.val); 
}; /*the "XOR" function is very powerful */

bool eq (const Record& r, const Record& r2)
{
	return r.name==r2.name && r.val==r2.val; 
}; 

/*Combining hash values using exclusive OR (^) preserves thier distrubutions over the set of values of type "size_t"*/


/*Givern this hash function and equality function, you can define an "unordered_set"*/

unordered_set<Record,decltype(&hf),decltype(&eq)> m 
{
	{{"andy,7"},{"al",9},{"bill",-3},{"barbara",12}},
	hf, 
	eq
}; 

for(auto r : m)
	cout << "{" << r.name << ',' << r.val << "}\n"; 
}
/*The use of "decltype" to avoid having to explicitly repeat the types of "hf" and "eq"*/

/*If you dont have an interilizer list handy, you can give an initial size instead: */

unordered_set<Record,decltype(&hf),decltype(&eq)> m {10,hf,eq}; 
/*This also makes it a bit easier to focus on hash and equality operations.*/

/*You want to avoid separating the definitioin of "hf" and "eq" from their point of use, you could try lambdas:*/



unordered_set<Record,					/*value type*/
	function<size_t(const Record&)>, 		/*hash type*/
	function<bool(const Record&, const Record&)>	/*equal type*/
	> m {10,
	[](const Record& r){return hash<string>{}(r.name)^hash<int>{}(r.val);},
	[](const Record& r, const Record& r2){return r.name==r2.name && r.val==r2.val;} 
}; 
/*The point about using lamnbdas instead of functions is that they can be defined locally in a function, next to thier use. (Im a fan of explict for now)*/

/*Here, function may incur overhead that you would prefer to avoid if the "unordered_set" was heavily used. You can consider that version messy and prefer to name the lambdas: */

auto hf = [](const Record& r){return hash<string>()(r.name)^hash<int>()(r.val);}; 

auto eq = [](const Record& r, const Record& r2){return r.name==r2.name && r.val==r2.val; }; 

unordered_set<Record,decltype(hf),decltype(eq)> m {10,hf,eq}; 

/*You may also prefer the method to define the meaning of hash and equality (my option of choice) once for all(case by case for me) "unordered" containers of "Record" by specializing the standard-library "hash" and "equal_to" templates used by "unordered_map":*/

namespace std
{
	template<>
	struct hash<Record>{
		size_t operator()(const Record &r) const
		{
			return hash<string>{}(r.name)^hash<int>{}(r.val); 
		}
	};
	template<>
	struct equal_to<Record>{
		bool operator()(const Record& r, const Record& r2) const
		{
			return r.name==r2.name && r.val==r2.val; 
		}
	}; 
}

unordered_set<Record> m1; 
unordered_set<Record> m2; 

/*The default "hash" and hasshes obtained from it by using excludive-or are often pretty good. UNLESS YOU UNDERSTAND AND CAN IMPLAMENT HASH TABLES AND KNOW THE oLOGn OF THE RUN TIME DO NOT GO ON AND BEING A CLASS S NINJA*/
