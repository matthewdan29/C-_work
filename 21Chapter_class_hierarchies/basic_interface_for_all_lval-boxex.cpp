/*Problem: Provide a way for a program ("an application") to get an integer value from a user.*/
/*The idea is to have a "lval_box" that know what range of input values it will accept from a given user*/
/*This will be the base class inwhich all other "lval_box" like classes will get their attrubutes.*/
/*Explaination: Class "lval_box" defines the basic interface to all "lval_boxes" and specifies a default implementation that more specific kinds of "lval_boxes" can override with their own versions. 
 * In addition, you declare the data needed to implement the basic notion:*/
#include <string>
#include <list>
#include <iostream>
using namespace std; 

class lval_box
{
protected: 
	int val; 
	int low; 
	int high; 
	bool changed {false}; 		/*change by user using "set_value()"*/
public: 
	lval_box(int ll, int hh) :val{ll}, low{ll}, high{hh}{}

	virtual int get_value(){changed = false; return val;}	/*for application*/
	virtual void set_value(int i){changed = true; val = i;}	/*for user*/
	virtual void reset_value(int i){changed = false; val = i;}	/*for application*/
	virtual void prompt(){}
	virtual bool was_changed() const {return changed;}

	virtual ~lval_box(){}; 
}; /*The default implementation of the functions is pretty sloppy and is provided here primarily to illustrate the intended semantics. 
A realistic class would, for example, provide som range checking.*/
