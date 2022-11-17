/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:16:36 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/16 19:22:12 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_ITERATOR_H
# define RED_BLACK_TREE_ITERATOR_H

# include "enable_if.hpp"

namespace ft
{


/* 
**	For some reason we can create iterator from const_iterator.???
*/

template <typename T, typename Node>
class red_black_tree_iterator {

public:
	typedef	Node*								iterator;
	typedef	T									value_type;
	typedef	T*									pointer;
	typedef	T&									reference;
	typedef	std::ptrdiff_t						difference_type;
	typedef	std::bidirectional_iterator_tag		iterator_category;

	red_black_tree_iterator(const iterator& base = iterator(), const iterator& border = iterator());
	template <typename _T>
	red_black_tree_iterator(const red_black_tree_iterator<_T, typename ft::enable_if<std::is_same<_T, typename Node::value_type>::value, Node>::type>& other);
	~red_black_tree_iterator();

	template <typename _T>
	red_black_tree_iterator&	operator = (const red_black_tree_iterator<_T, typename ft::enable_if<std::is_same<_T, typename Node::value_type>::value, Node>::type>& other);

	reference					operator * (void) const;
	pointer						operator -> (void) const;

	red_black_tree_iterator&	operator ++ (int);
	red_black_tree_iterator		operator ++ (void);
	red_black_tree_iterator&	operator -- (int);
	red_black_tree_iterator		operator -- (void);

	template <typename _T, typename _Node>
	friend bool operator == (const red_black_tree_iterator<_T, _Node>& lhs, const red_black_tree_iterator<_T, _Node>& rhs);
	template <typename _T, typename _Node>
	friend bool operator != (const red_black_tree_iterator<_T, _Node>& lhs, const red_black_tree_iterator<_T, _Node>& rhs);

	iterator	_base;
	iterator	_null;

protected:
	void	increment(void);
	void	decrement(void);
};

template <typename T, typename Node>
red_black_tree_iterator<T, Node>::red_black_tree_iterator(const iterator& base, const iterator& border) : _base(base), _null(border) { }

template <typename T, typename Node>
template <typename _T>
red_black_tree_iterator<T, Node>::red_black_tree_iterator(const red_black_tree_iterator<_T, typename ft::enable_if<std::is_same<_T, typename Node::value_type>::value, Node>::type>& other) : _base(other._base), _null(other._null) { }

template <typename T, typename Node>
red_black_tree_iterator<T, Node>::~red_black_tree_iterator() { }

template <typename T, typename Node>
template <typename _T>
red_black_tree_iterator<T, Node>& red_black_tree_iterator<T, Node>::operator = (const red_black_tree_iterator<_T, typename ft::enable_if<std::is_same<_T, typename Node::value_type>::value, Node>::type>& other) {
	_base = other._base;
	_null = other._null;
}

template <typename T, typename Node>
typename red_black_tree_iterator<T, Node>::reference red_black_tree_iterator<T, Node>::operator * (void) const {
	return _base->value;
}

template <typename T, typename Node>
typename red_black_tree_iterator<T, Node>::pointer red_black_tree_iterator<T, Node>::operator -> (void) const {
	return &_base->value;
}

template <typename T, typename Node>
red_black_tree_iterator<T, Node>& red_black_tree_iterator<T, Node>::operator ++ (int) {
	increment();	
	return *this;
}

template <typename T, typename Node>
red_black_tree_iterator<T, Node> red_black_tree_iterator<T, Node>::operator ++ (void) {
	iterator	copy(_base);

	increment();
	return copy;
}

template <typename T, typename Node>
red_black_tree_iterator<T, Node>& red_black_tree_iterator<T, Node>::operator -- (int) {
	decrement();
	return *this;
}

template <typename T, typename Node>
red_black_tree_iterator<T, Node> red_black_tree_iterator<T, Node>::operator -- (void) {
	iterator	copy(_base);

	decrement();
	return copy;
}

template <typename T, typename Node>
void red_black_tree_iterator<T, Node>::increment(void) {
	if (_base == _null)
		_base = _base->left;
	else if (_base->right == _null)
		_base = _null;
	else if (_base->right) {
		_base = _base->right;
		while (_base->left && _base->left != _null)
			_base = _base->left;
	}
	else if (_base->parent) {
		iterator	copy(_base->parent);
		
		while (copy && copy->left != _base) {
			_base = copy;
			copy = copy->parent;
		}
		_base = copy;
	}
}

template <typename T, typename Node>
void red_black_tree_iterator<T, Node>::decrement(void) {
	if (_base == _null)
		_base = _base->right;
	else if (_base->left == _null)
		_base = _null;
	else if (_base->left) {
		_base = _base->left;
		while (_base->right)
			_base = _base->right;
	}
	else if (_base->parent) {
		iterator	copy(_base->parent);
		
		while (copy && copy->left == _base) {
			_base = copy;
			copy = copy->parent;
		}
		_base = copy;
	}
}

template <typename _T, typename _Node>
bool operator == (const red_black_tree_iterator<_T, _Node>& lhs, const red_black_tree_iterator<_T, _Node>& rhs) {
	return (lhs._base == rhs._base);
}

template <typename _T, typename _Node>
bool operator != (const red_black_tree_iterator<_T, _Node>& lhs, const red_black_tree_iterator<_T, _Node>& rhs) {
	return !(lhs._base == rhs._base);
}

template <typename _TL, typename _TR, typename _Node>
bool operator == (const red_black_tree_iterator<_TL, _Node>& lhs, const red_black_tree_iterator<_TR, _Node>& rhs) {
	return (lhs._base == rhs._base);
}

template <typename _TL, typename _TR, typename _Node>
bool operator != (const red_black_tree_iterator<_TL, _Node>& lhs, const red_black_tree_iterator<_TR, _Node>& rhs) {
	return !(lhs._base == rhs._base);
}


} /* FT NAMESPACE */

#endif /* RED_BLACK_TREE_ITERATOR_H */