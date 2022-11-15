/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:57:35 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/15 19:22:51 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_H
# define VECTOR_ITERATOR_H

# include "enable_if.hpp"
# include "iterator_traits.hpp"

namespace ft
{


template <typename Iterator, typename Container>
class vector_iterator {

protected:
	typedef typename ft::iterator_traits<Iterator>		traits_type;

public:
	typedef typename traits_type::iterator_category		iterator_category;
	typedef typename traits_type::difference_type		difference_type;
	typedef Iterator									iterator_type;
	typedef typename traits_type::value_type			value_type;
	typedef typename traits_type::reference				reference;
	typedef typename traits_type::pointer				pointer;

	vector_iterator(void);
	vector_iterator(const iterator_type& base);
	template <typename Iter>
	vector_iterator(const vector_iterator<Iter, typename ft::enable_if<std::is_same<Iter, typename Container::pointer>::value, Container>::type>& other);

	~vector_iterator();

	template <typename Iter>
	vector_iterator&	operator =	(const vector_iterator<Iter, typename ft::enable_if<std::is_same<Iter, typename Container::pointer>::value, Container>::type>& other);

	vector_iterator&	operator ++	(void);
	vector_iterator		operator ++	(int);
	
	vector_iterator&	operator --	(void);
	vector_iterator		operator --	(int);

	reference			operator *	(void) const;
	pointer				operator ->	(void) const;

	vector_iterator		operator +	(const difference_type& diff) const;
	vector_iterator		operator -	(const difference_type& diff) const;

	vector_iterator&	operator +=	(const difference_type& diff);
	vector_iterator&	operator -=	(const difference_type& diff);

	reference			operator [] (const difference_type& diff) const;
	
	const Iterator&		base(void) const;

protected:
	iterator_type _base;
};

template <typename Iterator, typename Container>
vector_iterator<Iterator, Container>::vector_iterator(void) : _base(Iterator()) {
	return ;
}

template <typename Iterator, typename Container>
vector_iterator<Iterator, Container>::vector_iterator(const Iterator& base) : _base(base) {
	return ;
}

template <typename Iterator, typename Container>
template <typename Iter>
vector_iterator<Iterator, Container>::vector_iterator(const vector_iterator<Iter, typename ft::enable_if<std::is_same<Iter, typename Container::pointer>::value, Container>::type>& other) : _base(other.base()) {
	return ;
}

template <typename Iterator, typename Container>
vector_iterator<Iterator, Container>::~vector_iterator() {
	return ;
}

template <typename Iterator, typename Container>
template <typename Iter>
vector_iterator<Iterator, Container>& vector_iterator<Iterator, Container>::operator = (const vector_iterator<Iter, typename ft::enable_if<std::is_same<Iter, typename Container::pointer>::value, Container>::type>& other) {
	if (*this != other)
		_base = other.base();
	return *this;
}

template <typename Iterator, typename Container>
typename vector_iterator<Iterator, Container>::reference vector_iterator<Iterator, Container>::operator * (void) const {
	return *_base;
}

template <typename Iterator, typename Container>
typename vector_iterator<Iterator, Container>::pointer vector_iterator<Iterator, Container>::operator -> (void) const {
	return _base;
}

template <typename Iterator, typename Container>
vector_iterator<Iterator, Container> vector_iterator<Iterator, Container>::operator -- (int) {
	return vector_iterator<Iterator, Container>(_base--);
}

template <typename Iterator, typename Container>
vector_iterator<Iterator, Container>& vector_iterator<Iterator, Container>::operator -- (void) {
	--_base;
	return *this;
}

template <typename Iterator, typename Container>
vector_iterator<Iterator, Container>& vector_iterator<Iterator, Container>::operator ++ (void) {
	++_base;
	return *this;
}

template <typename Iterator, typename Container>
vector_iterator<Iterator, Container> vector_iterator<Iterator, Container>::operator ++ (int) {
	return vector_iterator<Iterator, Container>(_base++);
}

template <typename Iterator, typename Container>
vector_iterator<Iterator, Container> vector_iterator<Iterator, Container>::operator + (const difference_type& diff) const {
	return vector_iterator<Iterator, Container>(_base + diff);
}

template <typename Iterator, typename Container>
vector_iterator<Iterator, Container> vector_iterator<Iterator, Container>::operator - (const difference_type& diff) const {
	return vector_iterator<Iterator, Container>(_base - diff);
}

template <typename Iterator, typename Container>
vector_iterator<Iterator, Container>& vector_iterator<Iterator, Container>::operator += (const difference_type& diff) {
	_base += diff;
	return *this;
}

template <typename Iterator, typename Container>
vector_iterator<Iterator, Container>& vector_iterator<Iterator, Container>::operator -= (const difference_type& diff) {
	_base -= diff;
	return *this;
}

template <typename Iterator, typename Container>
typename vector_iterator<Iterator, Container>::reference vector_iterator<Iterator, Container>::operator [] (const difference_type& diff) const {
	return *(_base + diff);
}

template <typename Iterator, typename Container>
const Iterator& vector_iterator<Iterator, Container>::base(void) const {
	return _base;
}

/* NON-MEMBER OPERATORS */

template <typename Iterator, typename Container> 
bool operator == (const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator == (const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename Iterator, typename Container> 
inline bool operator != (const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) {
	return (lhs.base() != rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
inline bool operator != (const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() != rhs.base());
}

template <typename Iterator, typename Container> 
bool operator < (const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) {
	return (lhs.base() < rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator < (const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() < rhs.base());
}

template <typename Iterator, typename Container> 
bool operator <= (const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator <= (const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename Iterator, typename Container> 
bool operator > (const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) {
	return (lhs.base() > rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator > (const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() > rhs.base());
}

template <typename Iterator, typename Container> 
bool operator >= (const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator >= (const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <typename Iterator, typename Container>
typename vector_iterator<Iterator, Container>::difference_type operator - (const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) {
	return lhs.base() - rhs.base();
}

template <typename IteratorL, typename IteratorR, typename Container>
typename vector_iterator<IteratorL, Container>::difference_type operator - (const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs) {
	return lhs.base() - rhs.base();
}

template <typename Iterator, typename Container>
vector_iterator<Iterator, Container>	operator + (typename vector_iterator<Iterator, Container>::difference_type n, const vector_iterator<Iterator, Container>& rev_it) {
	return vector_iterator<Iterator, Container>(rev_it.base() + n);
}


} /* FT NAMESPACE */

#endif /* VECTOR_ITERATOR_H */