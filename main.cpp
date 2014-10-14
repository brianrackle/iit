//The MIT License(MIT)
//
//Copyright(c) 2014 Brian Rackle
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files(the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions :
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.
//
// Project home: https://github.com/brianrackle/iit
//

#include <cstdlib>
#include <vector>
#include <iostream>
#include <type_traits>
#include "iit.h"

int main()
{
	std::vector<int> v{ 1, 2, 3, 4 };

	for (auto t : iit(v))
	  {
	    if(t == v.begin())	  
	      std::cout << *t << std::endl;
	    if(t == v.end()) //never get's called
	      {
		using t_type = decltype(t);
		t_type::value_type vt = *t;
		t_type::difference_type dt = std::distance(std::begin(v), std::end(v));
		t_type::pointer pt = &*t; 
		t_type::reference rt = *t;
	      }
	  }

	for (auto t = v.begin(); t != v.end(); ++t)
	  if(t == v.begin())
	    std::cout << *t << std::endl;

	for (auto t : iit(std::vector<int>{ 1, 2, 3, 4 }))
	  std::cout << *t << std::endl;
	
	return EXIT_SUCCESS;
}
