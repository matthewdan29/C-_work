Below is examples of containers implemented as hash tables with linked overflow.
The default has function type, 'H', for a type 'K' is "std::hash<K>". 
The default for the equality function type, 'E', for a type 'K' is "std::equal_to<K>"; (std? wrap it up people); the equality function is used to decide whether two objects with the same hash code are equal. 
The associative container are linked structures(trees) with nodes of thier value_type. 
The sequence of a set, map or mutimap is ordered by its key value(K). 
An unordered conatiner need not have a ordering relation for its elements and uses a hash function instead. 
The sequence of an unordered container does not have to gauranteed order. 
 A "multimap" differs from a "map" in that a key value may occur many times 

				Unordered Associative Containers
	<'H' is the hash function type; 'E' is the equality test; 'A' is the allocator type>

		unordered_map<K,V,H,E,A>	An unordered map from 'K' to 'V'

		unordered_multimap<K,V,H,E,A>	An unordered map from 'K' to 'V'						duplicate keys allowed

		unordered_set<K,H,E,A>		An unordered set of 'K'

		unordered_multiset<K,H,E,A>	An unordered set of 'K' duplica-						te keys allowed 
