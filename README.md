iit (iterator iterator)
===

iit is a simple header file that provides an iterator that encapsulates an existing iterator
and dereferences to the encapsulated iterator. This encapsulation allows an iterator to be 
retrieved when a reference value would normally be retrieved. This is particularly useful
when using range-based for loops and an iterator is required, rather than the value the iterator
refers to.
