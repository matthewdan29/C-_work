#include <string>
#include <iostream>
#include <list>
#include <array>
using namespace std;

/*arrays of objects can also be created using "new".*/
char* save_string(const char* p)
{
	char* s = new char[strlen(p)+1]; 
	strcpy(s,p); 					/*copy from 'p' to 's'*/
	return s; 
}

int main(int argc, char* argv[])
{
	if (argc < 2)
		exit(1); 
	char* p = save_string(argv[1]); 
	/*...*/
	delete[] p; 
}/*The "plain" operator "delete" is used to delete individual objects; "delete[]" is used to delete arrays.*/

/*The standard-library "string" can be used to simplify the "save_string()"*/
string save_string(const char* p)
{
	return string{p}; 
}

int main(int argc, char* argv[])
{
	if (argc < 2)
		exit(1); 
	string s = save_string(argv[1]); 
	/*...*/
}/*Particular, the "new[]" and "delete[]" vanished. */

/*"vector" is a proper object and can therefore be allocated and deallocated using plain "new" and "delete". */
void f(int n)
{
	vector<int>* p = new vector<int>(n); 		/*individual object*/
	int* q = new int[n]; 				/*array*/
	/*...*/
	delete p; 
	delete[] q; 
}/*The "delete[]" operator may be applied only to a pointer to an array returned by "new" of an array or to the null pointer. */
