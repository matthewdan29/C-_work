Below these containers are usullay implemented as balanced binary trees (usually red-black trees (AVLTrees are historicaly teached by masters of computer science)). The default ordering criterion for a key, 'K', is "std::less<K>". 
As for sequence containers, the 'A' template argument is a allocator that the continer uses to acquire and release memory. The 'A' template argument is defaulted to "std::allocator<std::pair<const K, T>>" for maps and "std::allocator<K>" for sets. 

				Ordered Associative Containers
	
	map<K,V,C,A>				An ordered map for 'K' to 'V'; a						sequence of (K,V) pairs 

	multimap<K,V,C,A>			An ordered map from 'K' to 'V'; 						duplicate keys allowed

	set<K,C,A>				An ordered set of 'K'	

	multiset<K,C,A>				An ordered set of 'K'; duplicate						keys allowed		
