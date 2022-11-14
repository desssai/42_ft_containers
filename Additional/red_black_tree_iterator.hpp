/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:16:36 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/14 13:15:39 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_ITERATOR_H
# define RED_BLACK_TREE_ITERATOR_H

# include "enable_if.hpp"
# include "is_integral.hpp"
# include "red_black_tree.hpp"
# include "iterator_traits.hpp"

namespace ft
{


template <typename T>
class node;

template <typename Iterator, typename Container>
class red_black_tree_iterator {

public:
	/* MEMBER TYPES */

	typedef std::bidirectional_iterator_tag		iterator_category;
	typedef std::ptrdiff_t						difference_type;
	typedef Iterator							value_type;
	typedef Iterator&							reference;
	typedef Iterator*							pointer;
	typedef typename ft::node<Iterator>*		iterator_type;


	/* ASSIGNMENT */

	red_black_tree_iterator(void);
	red_black_tree_iterator(const iterator_type& base);
	template <typename Iter>
	red_black_tree_iterator(const red_black_tree_iterator<Iter, typename ft::enable_if<std::is_same<Iter, typename Container::pointer>::value, Container>::type>& other);

	~red_black_tree_iterator();

	template <typename Iter>
	red_black_tree_iterator&	operator =	(const red_black_tree_iterator<Iter, typename ft::enable_if<std::is_same<Iter, typename Container::pointer>::value, Container>::type>& other);

	/* MEMBER METHODS */

	const iterator_type&		base(void) const;
	red_black_tree_iterator&	operator ++	(void);
	red_black_tree_iterator		operator ++	(int);	
	red_black_tree_iterator&	operator --	(void);
	red_black_tree_iterator		operator --	(int);
	reference					operator *	(void) const;
	pointer						operator ->	(void) const;


protected:
	/* ATTRIBUTES */

	iterator_type _base;
};

/* ASSIGNMENT START --> */

template <typename Iterator, typename Container>
red_black_tree_iterator<Iterator, Container>::red_black_tree_iterator(void) : _base(iterator_type()) { }

template <typename Iterator, typename Container>
red_black_tree_iterator<Iterator, Container>::red_black_tree_iterator(const iterator_type& base) : _base(base) { }

template <typename Iterator, typename Container>
template <typename Iter>
red_black_tree_iterator<Iterator, Container>::red_black_tree_iterator(const red_black_tree_iterator<Iter, typename ft::enable_if<std::is_same<Iter, typename Container::pointer>::value, Container>::type>& other) : _base(other.base()->value) { }

template <typename Iterator, typename Container>
red_black_tree_iterator<Iterator, Container>::~red_black_tree_iterator() { }

template <typename Iterator, typename Container>
template <typename Iter>
red_black_tree_iterator<Iterator, Container>& red_black_tree_iterator<Iterator, Container>::operator = (const red_black_tree_iterator<Iter, typename ft::enable_if<std::is_same<Iter, typename Container::pointer>::value, Container>::type>& other) {
	_base = other.base();
	return *this;
}

/* <-- ASSIGNEMNT END */

/* MEMBER METHODS START --> */

template <typename Iterator, typename Container>
typename red_black_tree_iterator<Iterator, Container>::reference red_black_tree_iterator<Iterator, Container>::operator * (void) const {
	return _base->value;
}

template <typename Iterator, typename Container>
typename red_black_tree_iterator<Iterator, Container>::pointer red_black_tree_iterator<Iterator, Container>::operator -> (void) const {
	return &_base->value;
}

template <typename Iterator, typename Container>
red_black_tree_iterator<Iterator, Container> red_black_tree_iterator<Iterator, Container>::operator -- (int) {
	red_black_tree_iterator copy(*this);
	if (_base->left) {
		_base = _base->left;
		while (_base->right)
			_base = _base->right;
	}
	else
		_base = _base->parent;
	return copy;
}

template <typename Iterator, typename Container>
red_black_tree_iterator<Iterator, Container>& red_black_tree_iterator<Iterator, Container>::operator -- (void) {
	if (_base->left) {
		_base = _base->left;
		while (_base->right)
			_base = _base->right;
	}
	else
		_base = _base->parent;
	return *this;
}

template <typename Iterator, typename Container>
red_black_tree_iterator<Iterator, Container> red_black_tree_iterator<Iterator, Container>::operator ++ (int) {
	red_black_tree_iterator copy(*this);
	if (_base->right) {
		_base = _base->right;
		while (_base->left)
			_base = _base->left;
	}
	else {
		iterator_type tmp = _base;
		_base = _base->parent;
		while (_base->left != tmp)
		{
			tmp = _base;
			_base = _base->parent;
		}
	}
	return copy;
}

template <typename Iterator, typename Container>
red_black_tree_iterator<Iterator, Container>& red_black_tree_iterator<Iterator, Container>::operator ++ (void) {
	if (_base->right) {
		_base = _base->right;
		while (_base->left)
			_base = _base->left;
	}
	else if (_base->left) {
		iterator_type tmp = _base;
		_base = _base->parent;
		while (_base->left != tmp)
		{
			tmp = _base;
			_base = _base->parent;
		}
	}
	return *this;
}

template <typename Iterator, typename Container>
const typename red_black_tree_iterator<Iterator, Container>::iterator_type& red_black_tree_iterator<Iterator, Container>::base(void) const {
	return _base;
}

/* <-- MEMBER METHODS END */

/* NON-MEMBER OPERATORS START --> */

template <typename Iterator, typename Container> 
bool operator == (const red_black_tree_iterator<Iterator, Container>& lhs, const red_black_tree_iterator<Iterator, Container>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator == (const red_black_tree_iterator<IteratorL, Container>& lhs, const red_black_tree_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename Iterator, typename Container> 
inline bool operator != (const red_black_tree_iterator<Iterator, Container>& lhs, const red_black_tree_iterator<Iterator, Container>& rhs) {
	return (lhs.base() != rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
inline bool operator != (const red_black_tree_iterator<IteratorL, Container>& lhs, const red_black_tree_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() != rhs.base());
}

template <typename Iterator, typename Container> 
bool operator < (const red_black_tree_iterator<Iterator, Container>& lhs, const red_black_tree_iterator<Iterator, Container>& rhs) {
	return (lhs.base() < rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator < (const red_black_tree_iterator<IteratorL, Container>& lhs, const red_black_tree_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() < rhs.base());
}

template <typename Iterator, typename Container> 
bool operator <= (const red_black_tree_iterator<Iterator, Container>& lhs, const red_black_tree_iterator<Iterator, Container>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator <= (const red_black_tree_iterator<IteratorL, Container>& lhs, const red_black_tree_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename Iterator, typename Container> 
bool operator > (const red_black_tree_iterator<Iterator, Container>& lhs, const red_black_tree_iterator<Iterator, Container>& rhs) {
	return (lhs.base() > rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator > (const red_black_tree_iterator<IteratorL, Container>& lhs, const red_black_tree_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() > rhs.base());
}

template <typename Iterator, typename Container> 
bool operator >= (const red_black_tree_iterator<Iterator, Container>& lhs, const red_black_tree_iterator<Iterator, Container>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator >= (const red_black_tree_iterator<IteratorL, Container>& lhs, const red_black_tree_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() >= rhs.base());
}

/* <-- NON-MEMBER OPERATORS END */


} /* FT NAMESPACE */

#endif /* RED_BLACK_TREE_ITERATOR_H */