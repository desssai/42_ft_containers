/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:56:45 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/05 17:13:31 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_H
# define REVERSE_ITERATOR_H

# include "iterator_traits.hpp"

namespace ft {

template <typename Iterator>
class reverse_iterator {

private:
	typedef typename ft::iterator_traits<Iterator>		traits_type;

public:
	typedef typename traits_type::iterator_category		iterator_category;
	typedef typename traits_type::difference_type		difference_type;
	typedef Iterator									iterator_type;
	typedef typename traits_type::value_type			value_type;
	typedef typename traits_type::reference				reference;
	typedef typename traits_type::pointer				pointer;

	reverse_iterator();
	explicit reverse_iterator(iterator_type it);
	reverse_iterator(const reverse_iterator& other);
	template <typename Iter>
	reverse_iterator(const reverse_iterator<Iter>& other);
	~reverse_iterator();

	reverse_iterator&	operator = (const reverse_iterator& other);
	template <typename Iter>
	reverse_iterator&	operator = (const reverse_iterator<Iter>& other);

	iterator_type		base(void) const;

	reference				operator *	(void) const;
	reverse_iterator		operator +	(const difference_type& n);
	reverse_iterator&		operator ++	(void);
	reverse_iterator		operator ++	(int);
	reverse_iterator&		operator --	(void);
	reverse_iterator		operator --	(int);
	reverse_iterator&		operator +=	(const difference_type& n);
	reverse_iterator&		operator -=	(const difference_type& n);
	reverse_iterator		operator -	(const difference_type& n) const;
	pointer					operator ->	(void) const;
	reference				operator []	(const difference_type& n) const;

private:
	iterator_type	_base;

};

template <typename Iterator>
reverse_iterator<Iterator>::reverse_iterator() : _base(Iterator()) {}

template <typename Iterator>
reverse_iterator<Iterator>::reverse_iterator(Iterator it) : _base(it) {}

template <typename Iterator>
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator& other) {
	*this = other;
}

template <typename Iterator>
template <typename Iter>
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter>& other) {
	*this = other;
}

template <typename Iterator>
reverse_iterator<Iterator>::~reverse_iterator() {}

/* MEMBER OPERATORS */

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator = (const reverse_iterator& other) {
	if (*this != other)
		_base = other.base();
	return (*this);
}

template <typename Iterator>
template <typename Iter>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator = (const reverse_iterator<Iter>& other) {
	if (*this != other)
		_base = other.base();
	return (*this);
}

template <typename Iterator>
typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base(void) const {
	return _base;
}

template <typename Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator * (void) const {
	return *(_base - 1);
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator + (const difference_type& n) {
	return reverse_iterator<Iterator>(_base - n);
}

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator ++ (void) {
	--_base;
	return (*this);
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator ++ (int) {
	reverse_iterator<Iterator>	copy(*this);

	--_base;
	return (copy);
}

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator += (const difference_type& n) {
	_base -= n;
	return (*this);
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator - (const difference_type& n) const {
	return reverse_iterator<Iterator>(_base + n);
}

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator -- (void) {
	++_base;
	return (*this);
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator -- (int) {
	reverse_iterator<Iterator>	copy(*this);

	++_base;
	return (copy);
}

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator -= (const difference_type& n) {
	_base += n;
	return (*this);
}

template <typename Iterator>
typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator -> (void) const {
	return &(operator*());
}

template <typename Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator [] (const difference_type& n) const {
	return _base[-n-1];
}

/* NON-MEMBER OPERATORS */

template <typename Iterator> 
bool operator == (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename IteratorL, typename IteratorR> 
bool operator == (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename Iterator> 
inline bool operator != (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() != rhs.base());
}

template <typename IteratorL, typename IteratorR> 
inline bool operator != (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() != rhs.base());
}

template <typename Iterator> 
bool operator < (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() > rhs.base());
}

template <typename IteratorL, typename IteratorR> 
bool operator < (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() > rhs.base());
}

template <typename Iterator> 
bool operator <= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <typename IteratorL, typename IteratorR> 
bool operator <= (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <typename Iterator> 
bool operator > (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() < rhs.base());
}

template <typename IteratorL, typename IteratorR> 
bool operator > (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() < rhs.base());
}

template <typename Iterator> 
bool operator >= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename IteratorL, typename IteratorR> 
bool operator >= (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename Iterator, typename Container>
typename reverse_iterator<Iterator>::difference_type operator - (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return rhs.base() - lhs.base();
}

template <typename IteratorL, typename IteratorR>
typename reverse_iterator<IteratorL>::difference_type operator - (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return rhs.base() - lhs.base();
}

template <typename Iterator>
reverse_iterator<Iterator>	operator + (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
	return reverse_iterator<Iterator>(rev_it.base() - n);
}

}; /* FT NAMESPACE */

#endif /* REVERSE_ITERATOR_H */