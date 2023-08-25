/*NOTE: sort functions are very important. Personaly I would use a 'C' sorting function or the redix sorting function in 'C' you can find it in a repo or its faster and one of them are stable. also I explained stabilty and what it means.*/
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstring>
using namespace std; 
//using namespace std::vector; 
/*The "ssort()" routine does not know the type of the objects its sorts, only the number of elements, the size of each element, and the function to call to perform a comparison. */

using CFT = int(const void*, const void*); 

void ssort(void* base, size_t n, size_t sz, CFT cmp)
{
	for(int gap = n/2; 0 < gap; gap/=2)
		for(int i = gap; i != n; i++)
			for(int j = i - gap; 0 <= j; j -= gap)
			{
				char* b = static_cast<char*>(base);	/*necessary cast*/
				char* pj = b+j*sz; 			/*&base[j]*/
				char* pjg = b+(j+gap)*sz; 		/*&base[j+gap]*/
				if (cmp(pjg,pj) < 0)			/*swap base [j] and base[j+gap]:*/
				{
					for (int k = 0; k != sz; k++)
					{
						char temp = pj[k]; 
						pj[k] = pjg[k];
						pjg[k] = temp;
					}
				}
			}
}

/*Such a sort function could be used to sort a table such as this:*/
struct User
{
	const char* name;		/*unchange pointer to able name*/ 
	const char* id; 		/*unchange pointer to a ID#*/
	int dept; 			/*Change able # of department*/
}; /*NOTE: this structure makes it very easy for SQL table qureies*/

vector<User>heads={
	{"Ritchie D.M",		"dmr",		11271,},
	{"Sethi R.", 		"ravi", 	11272,},
	{"Szymanski T.G.", 	"tgs", 		11273,}, 
	{"Schryer N.L.", 	"nls", 		11274,}, 
	{"Schryer N.L.", 	"nls", 		11275,}, 
	{"Kernigham B.W.", 	"bwk", 		11276,},
	};   

void print_id(vector<User>& v)
{
	for(auto& x : v)
		cout << x.name << '\t' << x.id << '\t' << x.dept << '\n'; 
}

/*To be able to sort, we must first define approprate comparison functions. A  Comparison function must return a negative value if its first argument is less than the second, zero if the arguments are equal, and positive number otherwise: */

int cmp1(const void* p, const void* q)
{
	return strcmp(static_cast<const User*>(p)->name,static_cast<const User*>(q)->name); 
}

int cmp2(const void* p, const void* q)		/*Compare dept numbers*/
{
	return static_cast<const User*>(p)->dept - static_cast<const User*>(q)->dept; 
}

/*There is no implicit conversion of argument or return types when pointers to functions are assigned or initialized. This means that you cannot avoid the ugly and error-prone casts by writing: */

int cmp3(const User* p, const User* q)			/*compare ids*/
{
	return strcmp(p->id, q->id); 
}


int main()
{
	cout << "Heads in alphabetical order: \n"; 
	ssort(std::vector<User>heads.begin(), heads.end(), [](const User& x, const User& y){return x.name < y.name;}); 
	print_id(heads); 
	cout << '\n'; 

	cout << "Heads.begin(), head.end():\n";
	ssort(std::vector<User>heads.begin(), heads.end(), [](const User& x, const User& y){return x.dept < y.dept;});
	print_id(heads); 
} 

/*These 2 mains are equal. */

//int main()
//{
//	cout << "Heads in alphabetical order: \n"; 
//	ssort(void* std::vector<User>heads, 6, sizeof(User), cmp1);
        /*ssort(heads,6,sizeof(User),cmp1)*/	
//	print_id(heads); 
//	cout << '\n'; 

//	cout << "Heads in order of department number: \n"; 
//	ssort(void* std::vector<User>heads, 6, sizeof(User), cmp2);
	/*ssort(heads,6,sizeof(User),cmp2);*/
//	print_id(heads); 
//}
