	h=c.hash_function()			'h' is 'c''s hash function 

	eq=c.key_eq()				"eq" is 'c''s equality test 

	d=c.load_factor()			'd' is the  number of elements							divided by the number of buckets						"double(c.size())/c.bucket_count						()" noexcept;

	d=c.max_load_factor()			'd' is the maximum load factor c						; noexcept 

	c.max_load_factor(d)			Set 'c''s maximum load factor,							'c' load factor gets close to 							its maximum load factor, 'c' 							will resize the hash table							(increase the number of buckets)	

	c.rehash(n)				Make 'c';s bucket count >= n

	c.reserve(n)				Make room for n entries: 
						c.rehash(ceil(n/c.max_load_fact							or()))
