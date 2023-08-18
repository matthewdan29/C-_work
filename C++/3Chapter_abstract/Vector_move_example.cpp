#include <iosteam>

Vector::Vector(Vector&& a)
	:elem{a.elem},		/*grab the elements from a */
	sz{a.sz}
{
	a.elem = nullptr;	/*now a has no elements*/
	a.sz = 0;
}
