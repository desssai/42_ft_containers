/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:33:47 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/08 19:39:28 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <memory>
# include "Additional/less.hpp"
# include "Additional/pair.hpp"
# include "Additional/make_pair.hpp"
# include "Additional/reverse_iterator.hpp"

namespace ft
{


template <typename Key, typename T, typename Compare = ft::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T> > >
class map {

public:
	/* MEMBER TYPES */
	typedef Key														key_type;
	typedef T														mapped_type;
	typedef typename ft::pair<const key_type, mapped_type>			value_type;
	typedef Compare													key_compare;
	// typedef /*  */													value_compare;
	typedef Allocator												allocator_type;
	typedef typename allocator_type::reference						reference;
	typedef typename allocator_type::const_reference				const_reference;
	typedef typename allocator_type::pointer						pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	// typedef /*  */													iterator;
	// typedef /*  */													const_iterator;
	// typedef typename ft::reverse_iterator<iterator>					reverse_iterator
	// typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator
	typedef std::ptrdiff_t											difference_type;
	typedef	std::size_t												size_type;

	/* ASSIGNMEMNT */
	map();
	~map();

	/* ITERATORS */
	
	/*
		iterator 					begin(void);
		iterator 					end(void);
		const_iterator				begin(void) const;
		const_iterator				end(void) const;
		reverse_iterator			rbegin(void);
		reverse_iterator			rend(void);
		const_reverse_iterator		rbegin(void) const; 
		const_reverse_iterator		rend(void) const; 
	*/

	/* CAPACITY */

	bool		empty(void) const;
	size_type	size(void) const;
	size_type	max_size(void) const;

	/* ELEMENT ACCESS */

	/*
		mapped_type&		at(const key_type& key);
		const mapped_type&	at(const key_type& key) const;
		mapped_type&		operator [] (const key_type& key);
	*/
	
	/* MODIFIERS */
	
	/*
		INSERT
		ERASE 
		SWAP
		CLEAR
	*/

	/* OBSERVERS */
	
	key_compare		key_comp(void) const;
	// value_compare		value_comp(void) const;

	/* OPERATIONS */
	
	/*
		COUNT
		FIND
		EQUAL_RANGE
		LOWER_BOUND
		UPPER_BOUND
	*/

	/* ALLOCATOR */
	
	allocator_type	get_allocator(void) const;

	/* NON-MEMBER FUNCTIONS */

	/*
		operator ==
		operator !=
		operator <
		operator <=
		operator >
		operator >=
		swap
	*/

protected:
	allocator_type	_alloc;
	size_type		_size;

};

/* CAPACITY START --> */

template <typename Key, typename T, typename Compare, typename Allocator>
bool map<Key, T, Compare, Allocator>::empty(void) const {
	return (_size ? true : false);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::size(void) const {
	return _size;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::max_size(void) const {
	return _alloc.max_size() > __LONG_LONG_MAX__ ? __LONG_LONG_MAX__ : _alloc.max_size();
}

/* <-- CAPACITY END */

/* ALLOCATOR START --> */

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::allocator_type map<Key, T, Compare, Allocator>::get_allocator(void) const {
	return allocator_type();
}

/* <-- ALLOCATOR END */

/* NON-MEMBER START --> */


/* <-- NON-MEMBER END */

} /* FT NAMESPACE */

#endif /* MAP_H */