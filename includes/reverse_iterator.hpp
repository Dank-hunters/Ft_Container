#pragma once
#include "Iterator_traits.hpp"

namespace ft
{
template<typename _Iterator>
    class reverse_iterator
    {
    private:
    _Iterator                                              current;
        public:
   
    typedef _Iterator                                      iterator_type;
    typedef iterator_traits<_Iterator>                     __traits_type;
    typedef typename __traits_type::difference_type        difference_type;
    typedef typename __traits_type::pointer                pointer;
    typedef typename __traits_type::reference              reference;
    typedef typename  __traits_type::iterator_category     iterator_category;

    reverse_iterator() : current() { }
    
    reverse_iterator(iterator_type __x) : current(__x) { }

        template<typename _Iter>
    reverse_iterator(const reverse_iterator<_Iter>& __x): current(__x.base()) { }
     
   
 iterator_type  base() const
        {
            return current; 
        }
    
    reference operator*() const 
        { 
            _Iterator __tmp = current;
            return *--__tmp;
        }
    
    pointer operator->() const
        {
            return &(operator*());
        }

    reverse_iterator& operator++()
        {
            --current;
            return *this;
        }
    reverse_iterator operator++(int)
        {
            reverse_iterator __tmp = *this;
            --current;
            return __tmp;
        }
    reverse_iterator& operator--()
        {
            ++current;
            return *this;
        }
    
    reverse_iterator operator--(int)
        {
            reverse_iterator __tmp = *this;
            ++current;
            return __tmp;
        }
    
    reverse_iterator operator+(difference_type __n) const 
        {
            return reverse_iterator(current - __n);
        }
    
    
    reverse_iterator& operator+=(difference_type __n)
        {
            current -= __n;
            return *this;
        }
    
    reverse_iterator operator-(difference_type __n) const 
        {
            return reverse_iterator(current + __n);
        }
    
    
    reverse_iterator& operator-=(difference_type __n)
        {
            current += __n;
            return *this;
        }
    
    reference operator[](difference_type __n) const 
        {
            return *(*this + __n);
        }
    
};
template<typename _Iterator>
    bool operator==(const reverse_iterator<_Iterator>& __x,
               const reverse_iterator<_Iterator>& __y)
    { return __x.base() == __y.base(); }

  template<typename _Iterator>
    bool operator<(const reverse_iterator<_Iterator>& __x,
              const reverse_iterator<_Iterator>& __y)
    { return __y.base() < __x.base(); }

  template<typename _Iterator>
    bool operator!=(const reverse_iterator<_Iterator>& __x,
               const reverse_iterator<_Iterator>& __y)
    { return !(__x == __y); }

  template<typename _Iterator>
    bool operator>(const reverse_iterator<_Iterator>& __x,
              const reverse_iterator<_Iterator>& __y)
    { return __y < __x; }

  template<typename _Iterator>
    bool operator<=(const reverse_iterator<_Iterator>& __x,
               const reverse_iterator<_Iterator>& __y)
    { return !(__y < __x); }

  template<typename _Iterator>
    bool operator>=(const reverse_iterator<_Iterator>& __x,
               const reverse_iterator<_Iterator>& __y)
    { return !(__x < __y); }
};
