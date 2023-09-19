#include <string>
#include <iostream>
#include <list>
#include <vector>
using namespace std; 

/*Containers provide a variety of constructors and assignmet operations. like below*/

void use()
{
	vector<int> vi {1,3,5,7,9};	/*vector initialized by five ints*/
	vector<string>vs(7); 		/*vector initialized by 7 empty string*/

	vector<int> vi2; 
	vi2 = {2,4,6,8}; 		/*assign sequence of for ints to "vi2"*/
	vi2.assign(&vi[1], &vi[4]);	/*assign the sequence 3,5,7 to vi2*/

	vector<string> vs2; 
	vector = {"The Egale", "The Bird and Baby"}; 	/*assign two strings to vs2*/
	vs2.assign("The Bear", "The Bull and Vet"); 	/*run-time error*/
}/*The error in the assignment to vs2 is that a pair of pointers are passed and the two pointers do not point into the same array.*/

/*You can move them as arguments when you don't want aliasing:like below*/

void task(vector<int>&& v); 

vector<int> user(vector<int>& large)
{
	vector<int> res; 
	/*...*/

	task(move(large)); 			/*transfer ownership of data to task()*/
	/*...*/
	return res; 
}

