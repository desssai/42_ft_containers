/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:16:36 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/15 15:23:04 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_ITERATOR_H
# define RED_BLACK_TREE_ITERATOR_H

# include "enable_if.hpp"

namespace ft
{


template <typename T, typename Link>
class red_black_tree_iterator {

public:
	typedef	Link								iterator;
	typedef	T									value_type;
	typedef	T*									pointer;
	typedef	T&									reference;
	typedef	std::prtdiff_t						difference_type;
	typedef	std::bidirectional_iterator_tag		iterator_category;

	red_black_tree_iterator(const iterator& base);
	template <typename _T>
	red_black_tree_iterator(const red_black_tree_iterator<_T, typename ft::enable_if<std::is_same<_T, typename Link::value_type>::value, Link>::type>& other);
	~red_black_tree_iterator();

	template <typename _T>
	red_black_tree_iterator&	operator = (const red_black_tree_iterator<_T, typename ft::enable_if<std::is_same<_T, typename Link::value_type>::value, Link>::type>& other);

	reference					operator * (void) const;
	pointer						operator -> (void) const;

	red_black_tree_iterator&	operator ++ (int);
	red_black_tree_iterator		operator ++ (void);
	red_black_tree_iterator&	operator -- (int);
	red_black_tree_iterator		operator -- (void);

	template <typename _T, typename _Link>
	friend bool operator == (const red_black_tree_iterator<_T, _Link>& lhs, const red_black_tree_iterator<_T, _Link>& rhs);
	template <typename _T, typename _Link>
	friend bool operator != (const red_black_tree_iterator<_T, _Link>& lhs, const red_black_tree_iterator<_T, _Link>& rhs);

protected:
	iterator	_base;

	void	increment(iterator& base);
	void	decrement(iterator& base);
};

template <typename T, typename Link>
red_black_tree_iterator<T, Link>::red_black_tree_iterator(const iterator& base) : _base(base) { }

template <typename T, typename Link>
template <typename _T>
red_black_tree_iterator<T, Link>::red_black_tree_iterator(const red_black_tree_iterator<_T, typename ft::enable_if<std::is_same<_T, typename Link::value_type>::value, Link>::type>& other) : _base(other._base) { }

template <typename T, typename Link>
red_black_tree_iterator<T, Link>::~red_black_tree_iterator() { }

template <typename T, typename Link>
template <typename _T>
red_black_tree_iterator<T, Link>& red_black_tree_iterator<T, Link>::operator = (const red_black_tree_iterator<_T, typename ft::enable_if<std::is_same<_T, typename Link::value_type>::value, Link>::type>& other) {
	_base = other._base;
}

template <typename T, typename Link>
typename red_black_tree_iterator<T, Link>::reference red_black_tree_iterator<T, Link>::operator * (void) const {
	return _base->value;
}

template <typename T, typename Link>
typename red_black_tree_iterator<T, Link>::pointer red_black_tree_iterator<T, Link>::operator -> (void) const {
	return &_base->value;
}

template <typename T, typename Link>
typename red_black_tree_iterator<T, Link>::red_black_tree_iterator& red_black_tree_iterator<T, Link>::operator ++ (int) {
	
	
	return *this;
}

template <typename T, typename Link>
typename red_black_tree_iterator<T, Link>::red_black_tree_iterator red_black_tree_iterator<T, Link>::operator ++ (void) {

}

template <typename T, typename Link>
typename red_black_tree_iterator<T, Link>::red_black_tree_iterator& red_black_tree_iterator<T, Link>::operator -- (int) {

}

template <typename T, typename Link>
typename red_black_tree_iterator<T, Link>::red_black_tree_iterator red_black_tree_iterator<T, Link>::operator -- (void) {

}

template <typename T, typename Link>
void red_black_tree_iterator<T, Link>::increment(iterator& base) {
	if (!base)
		return ;
	else if (base->right) {
		base = base->right.minimum();
	}
	else if (base->left)
}

template <typename T, typename Link>
void red_black_tree_iterator<T, Link>::decrement(iterator& base) {

}

template <typename _T, typename _Link>
bool operator == (const red_black_tree_iterator<_T, _Link>& lhs, const red_black_tree_iterator<_T, _Link>& rhs) {
	return (lhs._base == rhs._base);
}

template <typename _T, typename _Link>
bool operator != (const red_black_tree_iterator<_T, _Link>& lhs, const red_black_tree_iterator<_T, _Link>& rhs) {
	return !(lhs._base == rhs._base);
}

template <typename _TL, typename _TR, typename _Link>
bool operator == (const red_black_tree_iterator<_TL, _Link>& lhs, const red_black_tree_iterator<_TR, _Link>& rhs) {
	return (lhs._base == rhs._base);
}

template <typename _TL, typename _TR, typename _Link>
bool operator != (const red_black_tree_iterator<_TL, _Link>& lhs, const red_black_tree_iterator<_TR, _Link>& rhs) {
	return !(lhs._base == rhs._base);
}


} /* FT NAMESPACE */

#endif /* RED_BLACK_TREE_ITERATOR_H */