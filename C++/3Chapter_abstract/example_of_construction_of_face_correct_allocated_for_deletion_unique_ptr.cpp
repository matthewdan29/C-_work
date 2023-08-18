/*The first example had problems with situations: 
 * 	A user might fail to "delete" the pointer returned by "read_shape()"
 * 	The owner of a container of "Shape" pointer might not "delete" the objects pointed to. */

/*In that sense, functioins returning a pointer to an object allocated on the free store are dangerous. */

/*One solution to both problems is to return a standard-library "unique_ptr" rather than a "naked pointer" and store "unique_ptr" in the container: */

unique_ptr<Shape> read_shape(istream& is) /*read shape descriptions from input stream*/
{	/*read shape header from is and find its Kind k*/
	switch(k)
	{
		case Kind::circle: 
			/*read circle data {Point, int} into p and r*/
			return unique_ptr<Shape>{new Circle{p,r}}; 
			/*...*/
	}
}

void user()
{
	vector<unique_ptr<Shape>> v; 
	while (cin)
		v.push_back(read_shape(cin)); 
	draw_all(v); 		/*call draw() for each element*/
	rotate_all(v,45); 	/*call rotate(45) for each element*/
}/*all Shapes implicitly destroyed*/
