constructing hash tables in every lang is hard and confusing without the hash function implemnated this is to help out with the C++ blowing off your foot part. 			unordered_map<K,T,H,E,A> contructors

	unordered_map m {n,hf,eql,a}; 	Construct 'm' with 'n' buckets, 
					the hash function "hf", the equality  						function "eql", and the allocator a; 						explicit

	unordered_map m {n,hf,eql}; 	unordered_map m {n,hf,eql,allocator_typ-					e{}}; 

	unordered_map m {n,hf}; 	unordered_map m {n,hf,key_eql{}}; expli-					cit

	unordered_map m {n}; 		unordered_map m {n,hasher{}}; explicit

	unordered_map m {}; 		unordered_map m {N}; the bucket count						'N' is implementation-defined; explicit


	unordered_map m {b,e,n,hf,eql,a};	Construct 'm' with 'n' buckets						from the elems of [b:e), using hash						function "hf", the equality function						"eql", and the allocator 'a':

	unordered_map m {b,e,n,hf,eql}; unordered_map m {b,e,n,hf,eql,allocator_					type{}}; 
	
	unordered_map m {b,e,n,hf}; 	unordered_map m {b,e,n,hf,key_equal{}}; 
	
	unordered_map m {b,e,n}; 	unordered_map m {b,e,n,hasher{}}; 

	unordered_map m {b,e,N}; 	unordered_map m {b,e,N}; the bucket cou-					t 'N' is implementation-defined


	unordered_map m {{elem},n,hf,eql,a}; 	Construct 'm' from the "elem" of 					an "initializer_list", using 'n' buckets					the hash function "hf", the equality fu-					ction "eql", and the allocator 'a'

	unordered_map m {{elem},n,hf,eql}; unordered_map m {{elem},n,hf,eql,allo					cator}
