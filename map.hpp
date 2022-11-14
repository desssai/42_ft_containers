/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:33:47 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/14 12:37:17 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <memory>
# include "Additional/less.hpp"
# include "Additional/is_integral.hpp"
# include "Additional/red_black_tree.hpp"
# include "Additional/reverse_iterator.hpp"

namespace ft
{


template <typename Key, typename T, typename Compare = ft::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T> > >
class map {

public:
	/* MEMBER TYPES */

	typedef Key																	key_type;
	typedef T																	mapped_type;
	typedef typename ft::pair<const key_type, mapped_type>						value_type;
	typedef Compare																key_compare;
	// typedef /*  */																value_compare;
	typedef Allocator															allocator_type;

protected:	
	
	typedef typename ft::red_black_tree<value_type, key_compare, allocator_type>	_rb_tree_base;

public:

	typedef typename _rb_tree_base::reference					reference;
	typedef typename _rb_tree_base::const_reference				const_reference;
	typedef typename _rb_tree_base::pointer						pointer;
	typedef typename _rb_tree_base::const_pointer				const_pointer;
	typedef typename _rb_tree_base::iterator					iterator;
	typedef typename _rb_tree_base::const_iterator				const_iterator;
	typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;
	typedef typename _rb_tree_base::difference_type				difference_type;
	typedef	typename _rb_tree_base::size_type					size_type;

	/* ASSIGNMEMNT */
	
	explicit map(const key_compare& compare = key_compare(), const allocator_type& alloc = allocator_type());
	template <typename InputIterator>
	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	map(const map& other);
	~map();

	map& operator = (const map& other);

	/* ITERATORS */
	
	iterator 					begin(void);
	iterator 					end(void);
	const_iterator				begin(void) const;
	const_iterator				end(void) const;
	reverse_iterator			rbegin(void);
	reverse_iterator			rend(void);
	const_reverse_iterator		rbegin(void) const;
	const_reverse_iterator		rend(void) const;

	/* CAPACITY */

	bool		empty(void) const;
	size_type	size(void) const;
	size_type	max_size(void) const;

	/* ELEMENT ACCESS */

	mapped_type&			at(const key_type& key);
	const mapped_type&		at(const key_type& key) const;
	mapped_type&			operator [] (const key_type& key);
	
	/* MODIFIERS */
	
	template <class Iterator> 
	void					insert(Iterator first, Iterator last);
	pair<iterator, bool>	insert(const value_type& val);
	iterator				insert(iterator position, const value_type& val);
	void					clear(void);

	/*
		ERASE 
		SWAP
	*/

	/* OBSERVERS */
	
	key_compare		key_comp(void) const;
	// value_compare		value_comp(void) const;

	/* OPERATIONS */
	
	iterator		find(const key_type& k);
	const_iterator	find(const key_type& k) const;
	size_type		count(const key_type& k) const;
	/*
		EQUAL_RANGE
	*/
	iterator 		lower_bound(const key_type& k);
	const_iterator	lower_bound(const key_type& k) const;
	iterator 		upper_bound(const key_type& k);
	const_iterator	upper_bound(const key_type& k) const;

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
	/* ATTRIBUTES */

	red_black_tree<value_type, Compare, Allocator>		_rb_tree;

};

/* ASSIGNMENT START --> */

template <typename Key, typename T, typename Compare, typename Allocator>
map<Key, T, Compare, Allocator>::map(const key_compare& compare, const allocator_type& alloc) : _rb_tree(compare, alloc) { }

template <typename Key, typename T, typename Compare, typename Allocator>
template <typename InputIterator>
map<Key, T, Compare, Allocator>::map(InputIterator first, InputIterator last, const key_compare& compare, const allocator_type& alloc) : _rb_tree(compare, alloc) {
	for (; first != last; ++first)
		_rb_tree.insert(nullptr, *first);
}

template <typename Key, typename T, typename Compare, typename Allocator>
map<Key, T, Compare, Allocator>::map(const map& other) : _rb_tree(other._rb_tree) { }

template <typename Key, typename T, typename Compare, typename Allocator>
map<Key, T, Compare, Allocator>::~map() { }

template <typename Key, typename T, typename Compare, typename Allocator>
map<Key, T, Compare, Allocator>& map<Key, T, Compare, Allocator>::operator = (const map& other) {
	_rb_tree = other._rb_tree;
}

/* <-- ASSIGNMENT END */

/* ITERATORS START --> */

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::begin(void) {
	return iterator(_rb_tree._begin);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::end(void) {
	return iterator(_rb_tree._end + 1);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::begin(void) const {
	return const_iterator(_rb_tree._begin);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::end(void) const {
	return const_iterator(_rb_tree._end + 1);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::reverse_iterator map<Key, T, Compare, Allocator>::rbegin(void) {
	return reverse_iterator(_rb_tree._end + 1);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::reverse_iterator map<Key, T, Compare, Allocator>::rend(void) {
	return reverse_iterator(_rb_tree._begin);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::const_reverse_iterator map<Key, T, Compare, Allocator>::rbegin(void) const {
	return const_reverse_iterator(_rb_tree._end + 1);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::const_reverse_iterator map<Key, T, Compare, Allocator>::rend(void) const {
	return const_reverse_iterator(_rb_tree._begin);
}

/* <-- ITERATORS END */

/* CAPACITY START --> */

template <typename Key, typename T, typename Compare, typename Allocator>
bool map<Key, T, Compare, Allocator>::empty(void) const {
	return (_rb_tree._size ? false : true);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::size(void) const {
	return _rb_tree._size;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::max_size(void) const {
	return _rb_tree._alloc.max_size(); /* WTF TO DO? */
}

/* <-- CAPACITY END */

/* ELEMENT ACCESS START --> */

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::mapped_type& map<Key, T, Compare, Allocator>::at(const key_type& key) {
	iterator it = lower_bound(key);

	if (it == end() || key_comp()(key, (*it).first))
		throw std::out_of_range("map::at");
	return (*it).second;
}

template <typename Key, typename T, typename Compare, typename Allocator>
const typename map<Key, T, Compare, Allocator>::mapped_type& map<Key, T, Compare, Allocator>::at(const key_type& key) const {
	const_iterator it = lower_bound(key);

	if (it == end() || key_comp()(key, (*it).first))
		throw std::out_of_range("map::at");
	return (*it).second;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::mapped_type& map<Key, T, Compare, Allocator>::operator [] (const key_type& key) {
	iterator it = lower_bound(key);

	if (it == end() || key_comp()(key, (*it).first))
		insert(nullptr, ft::pair<key_type, mapped_type>(key, mapped_type()));
	return (*it).second;
}

/* <-- ELEMENT ACCESS END */

/* MODIFIERS START --> */

template <typename Key, typename T, typename Compare, typename Allocator>
template <typename InputIterator>
void map<Key, T, Compare, Allocator>::insert(InputIterator first, InputIterator last) {
	for (; first != last; ++first)
		_rb_tree.insert(nullptr, *first);
}

template <typename Key, typename T, typename Compare, typename Allocator>
ft::pair<typename map<Key, T, Compare, Allocator>::iterator, bool> map<Key, T, Compare, Allocator>::insert(const value_type& val) {
	return _rb_tree.insert(nullptr, val);
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::insert(iterator position, const value_type& val) {
	return _rb_tree.insert(position, val).first;
}

template <typename Key, typename T, typename Compare, typename Allocator>
void map<Key, T, Compare, Allocator>::clear(void) {
	_rb_tree.clear();
}

/* <-- MODIFIERS END */

/* OBSERVERS START --> */

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::key_compare map<Key, T, Compare, Allocator>::key_comp(void) const {
	return key_compare();
}

/* <-- OBSERVERS END */

/* OPERATIONS STRART --> */

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::find(const key_type& k) {
	iterator it1 = begin();
	iterator it2 = end();

	while (it1 != it2) {
		if ((*it1).first == k)
			return it1;
		++it1;
	}
	return it2;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::find(const key_type& k) const {
	const_iterator it1 = begin();
	const_iterator it2 = end();

	while (it1 != it2) {
		if ((*it1).first == k)
			return it1;
		++it1;
	}
	return it2;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::count(const key_type& k) const {
	iterator it = find(k);
	
	return *it ? 1 : 0;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::lower_bound(const key_type& k) {
	iterator it1 = begin();
	iterator it2 = end();
	while (it1 != it2) {	
		if (!_kcomp(it1->value.first, k))
			return it1;
		++it1;
	}
	return it2;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::lower_bound(const key_type& k) const {
	const_iterator it1 = begin();
	const_iterator it2 = end();
	while (it1 != it2) {	
		if (!_kcomp(it1->value.first, k))
			return it1;
		++it1;
	}
	return it2;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::upper_bound(const key_type& k) {
	iterator it1 = begin();
	iterator it2 = end();
	while (it1 != it2) {	
		if (_kcomp(k, it1->value.first))
			return it1;
		++it1;
	}
	return it2;
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::upper_bound(const key_type& k) const {
	const_iterator it1 = begin();
	const_iterator it2 = end();
	while (it1 != it2) {	
		if (_kcomp(k, it1->value.first))
			return it1;
		++it1;
	}
	return it2;
}

/* <-- OPERATIONS END */

/* ALLOCATOR START --> */

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::allocator_type map<Key, T, Compare, Allocator>::get_allocator(void) const {
	return allocator_type();
}

/* <-- ALLOCATOR END */

/* PROTECTED MEMBER METHODS START --> */

/* <-- PROTECTED MEMBER METHODS END */
 

/* NON-MEMBER START --> */


/* <-- NON-MEMBER END */

} /* FT NAMESPACE */

#endif /* MAP_H */