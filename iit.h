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

template <typename T>
class itr : public T
{
  T _obj;
 public:
    itr(T&& obj) : _obj(std::move(obj)) {}
    bool operator!=(const itr& other) const { return _obj != other._obj; }
    T operator*() const { return _obj; }
    const itr& operator++() { ++_obj; return *this; }
};

template <typename T>
class val
{
  T _obj;
 public:
 val(T&& obj) : _obj(std::move(obj)) {}

  auto begin() const -> itr<decltype(std::begin(this->_obj))> { return std::begin(_obj); }
  auto end() const -> itr<decltype(std::end(this->_obj))> { return std::end(_obj); }
};

template <typename T>
class ref
{
  T& _obj;
public:
 ref(T& obj) : _obj(obj) {}
  
  auto begin() const -> itr<decltype(std::begin(this->_obj))> { return std::begin(_obj); }
  auto end() const -> itr<decltype(std::end(this->_obj))> { return std::end(_obj); }
};

template <typename T>
auto iit(T&& t) -> typename std::conditional<std::is_lvalue_reference<decltype(t)>::value,
                                 ref<T>,
                                 val<T>>::type
{
    return std::forward<T>(t);
}

