#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*Several alternative approaches can be taken to achieve a better version. Presented here one that maps cleanly into the "C++" language.
 * Specify class "lval_box" as a pure interface.*/

class lval_box
{
public: 
	virtual int get_value() = 0; 
	virtual void set_value(int i) = 0; 
	virtual void reset_value(int i) = 0; 
	virtual void prompt() = 0; 
	virtual bool was_changed() const = 0; 
	virtual ~lval_box(){}
}; /*The data is gone and are the simplstic implementations of the member functions
Gone, too, is the constructor, since there is no data for it to initialize. 
Added is a virtual destructor to ensure proper cleanup of the data that will be defined in the derived classes. */

/*Now definition of "lval_slider" could look like below example.*/
class lval_slider : public lval_box, protected BBwidget
{
public: 
	lval_slider(int, int); 
	~lval_slider() override; 

	int get_value() override; 
	void set_value(int i) override; 
	/*...*/
protected: 
	/*...functions overriding BBwidget virtual functions*/
	/*e.g., BBwidget::draw(), BBwidget::mouse 1 hit()..*/
private: 
	/*...data needed for slider...*/
}; 
/*The derived class "lval_slider" inherits from an abstract class(lval_box) that requires it to implement the base class's pure virtual functions.
 * It als inherits from "BBwidget" which provides it with the means of doing so.
 * Since "lval_box" provides the interface for the derived class, it is derived using "public". Since "BBwidget" is only an implementation aid, it is derived using "protected". 
 * This implies that a programmer using "lval_slider" cannot directly use facilities defined by "BBwidget". The interface provided by "lval_slider" is the one inherited from "lval_box", plus what "lval_slider" explicitly declares. */
