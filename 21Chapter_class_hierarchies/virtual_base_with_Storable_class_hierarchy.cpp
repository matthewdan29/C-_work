#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*What if the class "Storable" hold data and it was important that it should not be replicated?
 * We might define "Storable" to hold the name of the file to be used for storing the object:*/

class Storable
{
public: 
	Storable(const string& s); 		/*store in file name 's'*/
	virtual void read() = 0; 
	virtual void write() = 0; 		
	virtual ~Storable(); 
protected: 
	string file_name; 
	Storable(const Storable&) = delete; 
	Storable& operator = (const Storable&) = delete; 
}; 

/*Given this apparently minor change to "Storable" you must change the design of "Radio". 
 * To avoid replication by declaring a base "virtual": every "virtual" base of a derived class is represented by the same object. like example below*/

class Transmitter : public virtual Storable
{
public:
	void write() override; 
	/*...*/
		
}; 

class Receiver : public virtual Storable
{
public:
	void write() override; 
	/*...*/
}; 

class Radio : public Transmitter, public Receiver
{
public:
       void write() override; 
	/*...*/       
}; 
/*3 main reason to have a virtual base containing data. 
 * 1) Make the data nonlocal. 
 * 2) Put the data in a base class. 
 * 3) Allocate an object somewhere and give each of the two classes a pointer.*/

