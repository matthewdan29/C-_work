#include <iostream>

/*member functions can be defined like*/

template<typename T>
Vector<T>::Vector(int s)
{
	if (s < 0)
		throw Negative_size{}; 
	elem = new T[s]; 
	sz = s; 
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
	if (i < 0 || size() <= i)
		throw out_of_rang{"Vector::operator[]"}; 
	return elem[i]; 
}

/*you can define "Vectors" like this now*/
Vector<char> vc(200);	/*vector of 200 characters*/
Vector<string> vs(17);	/*vector of 17 strings*/
Vector<list<int>> vli(45);	/*vector of 45 lists of integers*/

/*now you can use "Vectors" like this*/
void write(const Vector<string>& vs)	/*vector of some strings*/
{
	for (int i = 0; i != vs.size(); ++i)
		cout << vs[i] << '\n';
}

/*to support the range-for loop for example "Vector" you got do define "begin()" and "end()" functions*/

template<typename T>
T* begin(Vector<T>& x)
{
	return &x[0];		/*pointer to first element*/
}

template<typename T>
T* end(Vector<T>& x)
{
	return x.begin() + x.siz();	/*pointer to one-past-last element*/
}

/*now you can iterate*/
void f2(const Vector<string>& vs)	/*Vector of some strings*/
{
	for (auto& s : vs)
		cout << s << '\n'; 
}
