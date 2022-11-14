/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:12:45 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/14 18:27:09 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_H
# define RED_BLACK_TREE_H

# include <iostream>

# include <memory>
# include "pair.hpp"
# include "equal.hpp"
# include "make_pair.hpp"
# include "lexicographical_compare.hpp"
# include "red_black_tree_iterator.hpp"

namespace ft
{


enum node_color {red = false, black = true};
enum node_side {right = false, left = true, none = false};

/* CLASS TEMPLATE FOR A SINGLE NDOE OF A RED BLACK TREE */
template <typename T>
class node {

public:
	/* MEMBER TYPES */

	typedef T				value_type;
	typedef T*				pointer;
	typedef const T*		const_pointer;
	typedef T& 				reference;
	typedef const T& 		const_reference;
	typedef node<T>*		link_type;
	typedef const node<T>*	const_link_type;
	
	/* ASSIGNMENT */
	
	node(const value_type& _value = value_type());
	node(const node& other);
	~node();

	node& operator = (const node& other);

	/* MEMBER METHODS */

	link_type			minimum(void);
	const_link_type		minimum(void) const;
	link_type			maximum(void);
	const_link_type		maximum(void) const;

	/* ATTRIBUTES */

	value_type	value;
	node_color	color;
	link_type	left;
	link_type	right;
	link_type	parent;
};

/* ASSIGNMENT START --> */

template <typename T>
node<T>::node(const value_type& _value) : value(_value), color(red), left(nullptr), right(nullptr), parent(nullptr) { }

template <typename T>
node<T>::node(const node& other) : value(other.value), color(other.color), left(other.left), right(other.right), parent(other.parent) { }

template <typename T>
node<T>::~node() { }

/* <-- ASSIGNMENT END */

/* MEMBER METHODS START --> */

template <typename T>
typename node<T>::link_type node<T>::minimum(void) {
	link_type	copy(this);

	while (copy->left)
		copy = copy->left;
	return copy;
}

template <typename T>
typename node<T>::const_link_type node<T>::minimum(void) const {
	const_link_type	copy(this);

	while (copy->left)
		copy = copy->left;
	return copy;
}

template <typename T>
typename node<T>::link_type node<T>::maximum(void) {
	link_type	copy(this);

	while (copy->right)
		copy = copy->right;
	return copy;
}

template <typename T>
typename node<T>::const_link_type node<T>::maximum(void) const {
	const_link_type	copy(this);

	while (copy->right)
		copy = copy->right;
	return copy;
}

/* <-- MEMBER METHODS END */

/* RED BLACK TREE CLASS TEMPLATE FOR FUTURE USE IN MAP & SET CONTAINERS*/
template<typename T, typename Compare, typename Allocator = std::allocator<ft::node<T> > >
class red_black_tree {


public:
	/* MEMBER TYPES */
	typedef T																		value_type;
	typedef Allocator::template	rebind<ft::node<value_type> >::other				allocator_type;
	typedef typename allocator_type::reference										reference;
	typedef typename allocator_type::const_reference								const_reference;
	typedef typename allocator_type::pointer										pointer;
	typedef typename allocator_type::const_pointer									const_pointer;
	typedef typename ft::node<value_type>*											link_type;
	typedef typename ft::node<const value_type>*									const_link_type;
	typedef typename ft::red_black_tree_iterator<value_type, red_black_tree>		iterator;
	typedef typename ft::red_black_tree_iterator<const value_type, red_black_tree>	const_iterator;
	typedef size_t																	size_type;
	typedef ptrdiff_t																difference_type;
	typedef Compare																	compare_type;

public:

	/* ASSIGNMENT */
	red_black_tree(const compare_type& compare = compare_type(), const allocator_type& alloc = allocator_type());
	red_black_tree(const red_black_tree& other);
	~red_black_tree();

	red_black_tree& operator = (const red_black_tree& other);

	/* ITERATORS */

	iterator 					begin(void);
	iterator 					end(void);
	const_iterator				begin(void) const;
	const_iterator				end(void) const;

	/* MEMBER METHODS */

	ft::pair<iterator, bool>	insert(link_type position, const value_type& value);
	void						clear(void);

	/* ATTRIBUTES */

	link_type			_root;
	link_type			_begin;
	link_type			_end;
	size_type			_size;
	size_type			_shortest;
	size_type			_longest;
	compare_type		_compare;
	allocator_type		_alloc;

protected:
	link_type	new_node(const value_type& val, const link_type parent, const node_color& color, const node_side& side);
};

/* ASSIGNMENT START --> */

template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>::red_black_tree(const compare_type& compare, const allocator_type& alloc)
	: _root(nullptr), _begin(nullptr), _end(nullptr), _size(0), _shortest(0), _longest(0), _compare(compare), _alloc(alloc) { }

template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>::red_black_tree(const red_black_tree& other)
	: _root(nullptr), _begin(nullptr), _end(nullptr), _size(0), _longest(0), _shortest(0), _compare(other._compare), _alloc(other._alloc) {
	/* DO STUFF WITH DEEP COPIES */
}

template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>::~red_black_tree() {
	// clear();
}

template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>& red_black_tree<T, Compare, Allocator>::operator = (const red_black_tree& other) {
	if (*this != other) {
		_size = other._size;
		_longest = other._longest;
		_shortest = other._shortest;
		_compare = other._compare;
		_alloc = other._alloc;
		/* DO STUFF WITH DEEP COPIES */
	}
	return *this;
}

/* <-- ASSIGNMENT END */

/* ITERATORS START --> */

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::begin(void) {
	return iterator(_begin);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::end(void) {
	return iterator(_end + 1);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::begin(void) const {
	return const_iterator(_begin);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::end(void) const {
	return const_iterator(_end + 1);
}

/* <-- ITERATORS END */

/* MEMBER METHODS START --> */

template <typename T, typename Compare, typename Allocator>
ft::pair<typename ft::red_black_tree<T, Compare, Allocator>::iterator, bool> red_black_tree<T, Compare, Allocator>::insert(link_type position, const value_type& value) {
	typename ft::pair<ft::red_black_tree_iterator<value_type, red_black_tree>, bool>	ret;

	if (!*position && !_root) {
		_root = new_node(value, nullptr, black, none);
		ret.first = _root;
	}
	else {
		link_type _new = _root;
		link_type _prev;

		while (_new) {
			_prev = _new;
			if (_compare(value.first, _new->value.first))
				_new = _new->left;
			else if (_compare(_new->value.first, value.first))
				_new = _new->right;
			else {
				ret.second = false;
				ret.first = _new;
				return ret;
			}
		}
		if (_compare(value.first, _prev->value.first))
				new_node(value, _prev, black, left);
		else
				new_node(value, _prev, black, right);
	}
	_begin = _root->minimum();
	_end = _root->maximum();
	++_size;
	return ret;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::clear(void) {
	iterator	it1 = begin();
	iterator	it2 = end();

	iterator	copy;
	while (it1 != it2) {
		copy = it1++;
		_alloc.destroy(copy.base());
		_alloc.deallocate(copy.base(), 1);
	}
	_root = nullptr;
	_begin = nullptr;
	_end = nullptr;
	_size = 0;
	_shortest = 0;
	_longest = 0;
}

/* <-- MEMBER METHODS END */





/* PROTECTED MEMBER METHODS START --> */

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::link_type red_black_tree<T, Compare, Allocator>::new_node(const value_type& val, const link_type parent, const node_color& color, const node_side& side) {	
	link_type	new_node = _alloc.allocate(1);

	_alloc.construct(new_node, val);
	new_node->color = color;
	if (parent) {
		new_node->parent = parent;
		if (side == left)
			parent->left = new_node;
		else if (side == right)
			parent->right = new_node;
	}
	return new_node;
}

/* <-- PROTECTED MEMBER METHODS END */

/* NON-MEMBER COMPARISON OPERATORS START --> */

template <typename T, typename Compare, typename Allocator>
bool operator == (const red_black_tree<T, Compare, Allocator>& lhs, const red_black_tree<T, Compare, Allocator>& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin(), typename red_black_tree<T, Compare, Allocator>::compare_type());
}

template <typename T, typename Compare, typename Allocator>
bool operator != (const red_black_tree<T, Compare, Allocator>& lhs, const red_black_tree<T, Compare, Allocator>& rhs) {
	return !(lhs == rhs);
}

template <typename T, typename Compare, typename Allocator>
bool operator < (const red_black_tree<T, Compare, Allocator>& lhs, const red_black_tree<T, Compare, Allocator>& rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), typename red_black_tree<T, Compare, Allocator>::compare_type());
}

template <typename T, typename Compare, typename Allocator>
bool operator <= (const red_black_tree<T, Compare, Allocator>& lhs, const red_black_tree<T, Compare, Allocator>& rhs) {
	return !(rhs < lhs);
}

template <typename T, typename Compare, typename Allocator>
bool operator > (const red_black_tree<T, Compare, Allocator>& lhs, const red_black_tree<T, Compare, Allocator>& rhs) {
	return (rhs < lhs);
}

template <typename T, typename Compare, typename Allocator>
bool operator >= (const red_black_tree<T, Compare, Allocator>& lhs, const red_black_tree<T, Compare, Allocator>& rhs) {
	return !(lhs < rhs);
}

/* <-- NON-MEMBER COMPARISON OPERATORS END */

} /* FT NAMESPACE */

#endif /* RED_BLACK_TREE_H */