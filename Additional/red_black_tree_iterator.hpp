/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:16:36 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/14 21:43:19 by ncarob           ###   ########.fr       */
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

template <typename T, typename Node>
class red_black_tree_iterator {

public:
	/* MEMBER TYPES */

	typedef std::bidirectional_iterator_tag		iterator_category;
	typedef std::ptrdiff_t						difference_type;
	typedef T									value_type;
	typedef T&									reference;
	typedef T*									pointer;
	typedef Node*								iterator_type;


	/* ASSIGNMENT */

	red_black_tree_iterator(void);
	red_black_tree_iterator(const iterator_type& base);
	template <typename _T>
	red_black_tree_iterator(const red_black_tree_iterator<_T, typename ft::enable_if<std::is_same<_T, typename Node::value_type>::value, Node>::type>& other);

	~red_black_tree_iterator();

	template <typename _T>
	red_black_tree_iterator&	operator =	(const red_black_tree_iterator<_T, typename ft::enable_if<std::is_same<_T, typename Node::value_type>::value, Node>::type>& other);

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

template <typename T, typename Node>
red_black_tree_iterator<T, Node>::red_black_tree_iterator(void) : _base(iterator_type()) { }

template <typename T, typename Node>
red_black_tree_iterator<T, Node>::red_black_tree_iterator(const iterator_type& base) : _base(base) { }

template <typename T, typename Node>
template <typename _T>
red_black_tree_iterator<T, Node>::red_black_tree_iterator(const red_black_tree_iterator<_T, typename ft::enable_if<std::is_same<_T, typename Node::value_type>::value, Node>::type>& other) : _base(other.base()) { }

template <typename T, typename Node>
red_black_tree_iterator<T, Node>::~red_black_tree_iterator() { }

template <typename T, typename Node>
template <typename _T>
red_black_tree_iterator<T, Node>& red_black_tree_iterator<T, Node>::operator = (const red_black_tree_iterator<_T, typename ft::enable_if<std::is_same<_T, typename Node::value_type>::value, Node>::type>& other) {
	_base = other.base();
	return *this;
}

/* <-- ASSIGNEMNT END */

/* MEMBER METHODS START --> */

template <typename T, typename Node>
typename red_black_tree_iterator<T, Node>::reference red_black_tree_iterator<T, Node>::operator * (void) const {
	return _base->value;
}

template <typename T, typename Node>
typename red_black_tree_iterator<T, Node>::pointer red_black_tree_iterator<T, Node>::operator -> (void) const {
	return &_base->value;
}

template <typename T, typename Node>
red_black_tree_iterator<T, Node> red_black_tree_iterator<T, Node>::operator -- (int) {
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

template <typename T, typename Node>
red_black_tree_iterator<T, Node>& red_black_tree_iterator<T, Node>::operator -- (void) {
	if (_base->left) {
		_base = _base->left;
		while (_base->right)
			_base = _base->right;
	}
	else
		_base = _base->parent;
	return *this;
}

template <typename T, typename Node>
red_black_tree_iterator<T, Node> red_black_tree_iterator<T, Node>::operator ++ (int) {
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

template <typename T, typename Node>
red_black_tree_iterator<T, Node>& red_black_tree_iterator<T, Node>::operator ++ (void) {
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

template <typename T, typename Node>
const typename red_black_tree_iterator<T, Node>::iterator_type& red_black_tree_iterator<T, Node>::base(void) const {
	return _base;
}

/* <-- MEMBER METHODS END */

/* NON-MEMBER OPERATORS START --> */

template <typename T, typename Node> 
bool operator == (const red_black_tree_iterator<T, Node>& lhs, const red_black_tree_iterator<T, Node>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename _TL, typename _TR, typename Node> 
bool operator == (const red_black_tree_iterator<_TL, Node>& lhs, const red_black_tree_iterator<_TR, Node>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename T, typename Node> 
inline bool operator != (const red_black_tree_iterator<T, Node>& lhs, const red_black_tree_iterator<T, Node>& rhs) {
	return (!(lhs.base() == rhs.base()));
}

template <typename _TL, typename _TR, typename Node> 
inline bool operator != (const red_black_tree_iterator<_TL, Node>& lhs, const red_black_tree_iterator<_TR, Node>& rhs) {
	return (!(lhs.base() == rhs.base()));
}

template <typename T, typename Node> 
bool operator < (const red_black_tree_iterator<T, Node>& lhs, const red_black_tree_iterator<T, Node>& rhs) {
	return (lhs.base() < rhs.base());
}

template <typename _TL, typename _TR, typename Node> 
bool operator < (const red_black_tree_iterator<_TL, Node>& lhs, const red_black_tree_iterator<_TR, Node>& rhs) {
	return (lhs.base() < rhs.base());
}

template <typename T, typename Node> 
bool operator <= (const red_black_tree_iterator<T, Node>& lhs, const red_black_tree_iterator<T, Node>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename _TL, typename _TR, typename Node> 
bool operator <= (const red_black_tree_iterator<_TL, Node>& lhs, const red_black_tree_iterator<_TR, Node>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename T, typename Node> 
bool operator > (const red_black_tree_iterator<T, Node>& lhs, const red_black_tree_iterator<T, Node>& rhs) {
	return (lhs.base() > rhs.base());
}

template <typename _TL, typename _TR, typename Node> 
bool operator > (const red_black_tree_iterator<_TL, Node>& lhs, const red_black_tree_iterator<_TR, Node>& rhs) {
	return (lhs.base() > rhs.base());
}

template <typename T, typename Node> 
bool operator >= (const red_black_tree_iterator<T, Node>& lhs, const red_black_tree_iterator<T, Node>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <typename _TL, typename _TR, typename Node> 
bool operator >= (const red_black_tree_iterator<_TL, Node>& lhs, const red_black_tree_iterator<_TR, Node>& rhs) {
	return (lhs.base() >= rhs.base());
}

/* <-- NON-MEMBER OPERATORS END */


} /* FT NAMESPACE */

#endif /* RED_BLACK_TREE_ITERATOR_H */