/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:53:05 by cguiot            #+#    #+#             */
/*   Updated: 2022/06/29 18:50:52 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <__config>
#include <iosfwd> // for forward declaration of vector
#include <__bit_reference>
#include <type_traits>
#include <climits>
#include <limits>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <cstring>
#include <__cxx_version>
#include <__split_buffer>
#include <__functional_base>
#include <type_traits>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include <__debug>
# include <vector>

namespace ft
{

template <class T, class Alloc = std::allocator<T> >
class vector
{
    
    public:
    typedef T                                        value_type;
    typedef Alloc                                    allocator_type;
  
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    
	typedef typename ft::iterator_traits<iterator>::difference_type difference_type; //same as ptrdiff

    
    typedef ft::random_access_iterator<value_type>				iterator;
	typedef ft::random_access_iterator<const value_type> 		const_iterator;
    typedef std::reverse_iterator<iterator>          reverse_iterator;    
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;



    
    private :
    pointer	_start;
	pointer	_end;
	pointer	_end_of_storage;
    allocator_type _alloc;

public :    
    /////////////////////////////////  constuctoeur / destructeur    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
    
    //default constructor
    vector(const allocator_type& alloc = allocator_type()) : _start(NULL), _end(NULL), _end_of_storage(NULL), _alloc(alloc) {}

    // Fill Constructor
    vector(size_type n,
    		const value_type& val = value_type(),
    		const allocator_type& alloc = allocator_type()) : _start(NULL), _end(NULL), _end_of_storage(NULL), _alloc(alloc) {assign(n, val);}
    
    // Range Constructor
    template < class InputIterator >
    vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _start(NULL), _end(NULL), _end_of_storage(NULL), _alloc(alloc) { assign(first, last);}
    
    // Copy Constructor
    vector(const vector& x) : _start(NULL), _end(NULL), _end_of_storage(NULL), _alloc(x._alloc) { *this = x }

    //default destructor
    ~vector();
    
    
    
    


    /////////////////////////////////  operator   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
   
    vector& operator=(const vector& x);
    {
            clear();
			if (capacity() > x.size())
			{
				insert(begin(), x.begin(), x.end());
			}
            else
				assign(x.begin(), x.end());
			return *this;
	}



    /////////////////////////////////  assign   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


    //range
    template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
    
    //fill
    void assign(size_type n, const value_type& u);
    {
        if (n = 0)
        return;
       // if (n < capacity())
       //     init_blo
    }
    

    //allocator_type get_allocator() const noexcept;


    reverse_iterator       rbegin()
        {return       reverse_iterator(end());}
   
    const_reverse_iterator rbegin()  const
        {return const_reverse_iterator(end());}
   
    reverse_iterator       rend()
        {return       reverse_iterator(begin());}
   
    const_reverse_iterator rend()    const
        {return const_reverse_iterator(begin());}

   


    iterator               begin() {return (iterator(_start));}
    const_iterator         begin()   const ; {return (const_iterator(_start));}
    
    iterator               end()  {return (iterator(_end));}
    const_iterator         end() const  {return (const_iterator(_end));}











 	size_type size(void) const { return static_cast<size_type>(_end - _start); }
    
    size_type max_size() const ;
    
    size_type capacity(void) const { return static_cast<size_type>(_end_of_storage - _start); }

    bool empty() const ;
    void reserve(size_type n);

    reference       operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference       at(size_type n);
    const_reference at(size_type n) const;





    reference       front()
    {
        return *this->__begin_;
    }
    const_reference front() const
    {
        return *this->__begin_;
    }
    reference       back()
    {
        return *(this->__end_ - 1);
    }
    const_reference back()  const
    {
        return *(this->__end_ - 1);
    }





    //value_type*       data() noexcept;
    //const value_type* data() const noexcept;

  
  
  
  
  
  
    //template <class... Args>
    //    reference emplace_back(Args&&... args); // reference in C++17
    
    
    void push_back(value_type&& x);
    void push_back(const value_type& x);

    
    void pop_back();
    
    //template <class... Args> iterator emplace(const_iterator position, Args&&... args);
    iterator insert(const_iterator position, const value_type& x);
    iterator insert(const_iterator position, value_type&& x);
    iterator insert(const_iterator position, size_type n, const value_type& x);
    template <class InputIterator>
        iterator insert(const_iterator position, InputIterator first, InputIterator last);
    iterator insert(const_iterator position, initializer_list<value_type> il);

    iterator erase(const_iterator position);
    iterator erase(const_iterator first, const_iterator last);

    void clear() ;

    void resize(size_type sz);
    void resize(size_type sz, const value_type& c);

    void swap(vector&)
        (allocator_traits<allocator_type>::propagate_on_container_swap::value ||
                 allocator_traits<allocator_type>::is_always_equal::value);  // C++17

    
    
    
    bool __invariants() const;
};

}
