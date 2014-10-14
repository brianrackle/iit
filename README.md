iit (iterator iterator)
===

iit is a simple header file that provides an iterator that encapsulates an existing iterator
and dereferences to the encapsulated iterator. This encapsulation allows an iterator to be 
retrieved when a reference value would normally be retrieved. This is particularly useful
when using range-based for loops and an iterator is required, rather than the value the iterator
refers to.

Usage:

    	std::vector<int> v{ 1, 2, 3, 4 };
    
    	for (auto t : iit(v))
    	    if(t == v.begin())
    	      std::cout << *t << std::endl;

With iit, the range-based for loop takes 22 characters. 

In comparison:
    
    	for (auto t = v.begin(); t != v.end(); ++t)
    	  if(t == v.begin())
    	    std::cout << *t << std::endl;

Without iit, 44 characters are needed for the same functionality.
