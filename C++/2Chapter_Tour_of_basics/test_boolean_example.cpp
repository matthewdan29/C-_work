#include <iostream>

/*Simple function that prompts the user and returns a Boolean indicating the response*/

/* Understand there is no main() so this function will not run. */

bool accept()
{
	cout<<"Do you want to proceed(y or n)?\n"; 	/*write to termanal to give a answer. */
	
	char answer = 0; 
	cin >>answer; 			/*prompt to answer*/
	if(answer=='y') return true; 
	return false; 
}
