#include <string>
#include <list>
#include <iostream>
using namespace std; 
/*When each class has only one direct base class, the class hierarchy will be a tree, and a class can only occur once in the tree.*/
/*consider a class providing facilities for storing state in a file and restoring it later:*/

struct Storable			/*persistent storage*/
{
	virtual string get_file() = 0; 
	virtual void read() = 0; 
	virtual void write() = 0; 

	virtual ~Storable(){}
}; 

/*Your going to want to use this class like a house blue print. Its usefule and used in serval places in a class hierarchy. For example. below*/

class Transmitter : public Storable
{
public:
	void write() override;
	/*...*/
}; 

class Receiver : public Storable
{
public:
	void write() override; 
	/*...*/
}; 

class Radio : public Transmitter, public Receiver
{
public: 
	string get_file() override; 
	void read() override; 
	void write() override; 
	/*...*/
}; 

/*A virtual function of a replicated base class can be overridden by a function in a derived class. An overriding function calls its base class versions and does the work speific to the derived class: example below*/

void Radio::write()
{
	Transmitter::write(); 
	Receiver::write(); 
	/*... write radio-specific information...*/
}
