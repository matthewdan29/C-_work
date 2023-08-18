Here are some important Algo's in the header file #include Algorithm as told by the creator C++
			Bjarne Stroustrup 



p=find(b,e,x)		'p' is the first 'p' in [b:e) so that *p==x; 
p=find_if(bef)		'p' is the first 'p' in [b:e) so that f(*p)==true; 
n=count(b,e,x)		'n' is the number of elements *q in [b:e) so that *q==x;
n=count_if(b,e,f)	'n' is the number of elements *q in [b:e) so that f(*q,x); 
replace(b,e,v,v2)	Replace elements *q in [b:e) so that *q==v by v2; 
replace_if(b,e,f,v2)	Replace elements *q in [b:e) so that f(*q) by v2; 
p=copy(b,e,out)		Copy [b:e) to [out:p); 
p=copy_if(b,e,out,f)	Copy elements *q from [b:e) so that f(*q) to [out:p); 
p=unique_copy(b,e,out)	Copy [b:e) to [out:p); dont copy adjacent duplicates; 
sort(b,e)		Sort elements of [b:e) using < as the sorting criterion; 
sort(b,e,f)		Sort elements of [b:e) using f as the sorting criterion; 
(p1, p2)=equal_range(b,e,v)	[p1:p2) is the subsequence of the sort sequence [b:e) with the value v; besically a binary search for v 
p=merge(b,e,b2,e2,out)	Merge two sorted sequences [b:e) and [b2:e2) int [out:p)
