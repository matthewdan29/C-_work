lst.push_front(x)		Add 'x' to "lst" (using copy or move) before the				the first element. 

lst.pop_front()			Remove the first element from "lst"

lst.emplace_front(args)		Add "T{args}" to "lst" before the first element

lst.remove(v)			Remove all elements of "lst" with value 'v'

lst.remove_if(f)		Remove all elements of "lst" for which "f(x) == 				true"

lst.unique()			Remove adjacent duplicate elements of "lst"

lst.unique(f)			Remove adajacent duplicate elements of "lst" us-				ing 

lst.merge(lst2)			Merge the ordered list "lst" and "lst2" using 					'<' as the order; "lst2" is merged into "lst" 					and emptied in the process 

lst.merge(lst2,f)		Merge the ordered list "lst" and "lst2" using 					'f' as the order; "lst2" is merged into 'lst'					and  emptied in the process

lst.sort()			Sort "lst" using '<' as the order 

lst.sort(f)			Sort "lst" using 'f' as the order 

lst.reverse()			Reverse the order of the elements of "lst"; noe-				xcept
