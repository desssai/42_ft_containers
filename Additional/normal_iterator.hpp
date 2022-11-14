/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:57:35 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/14 19:01:30 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_ITERATOR_H
# define NORMAL_ITERATOR_H

# include "enable_if.hpp"
# include "is_integral.hpp"
# include "iterator_traits.hpp"

namespace ft
{


template <typename Iterator, typename Container>
class normal_iterator {

protected:
	typedef typename ft::iterator_traits<Iterator>		traits_type;

public:
	typedef typename traits_type::iterator_category		iterator_category;
	typedef typename traits_type::difference_type		difference_type;
	typedef Iterator									iterator_type;
	typedef typename traits_type::value_type			value_type;
	typedef typename traits_type::reference				reference;
	typedef typename traits_type::pointer				pointer;

	normal_iterator(void);
	normal_iterator(const iterator_type& base);
	template <typename Iter>
	normal_iterator(const normal_iterator<Iter, typename ft::enable_if<std::is_same<Iter, typename Container::pointer>::value, Container>::type>& other);

	~normal_iterator();

	template <typename Iter>
	normal_iterator&	operator =	(const normal_iterator<Iter, typename ft::enable_if<std::is_same<Iter, typename Container::pointer>::value, Container>::type>& other);

	normal_iterator&	operator ++	(void);
	normal_iterator		operator ++	(int);
	
	normal_iterator&	operator --	(void);
	normal_iterator		operator --	(int);

	reference			operator *	(void) const;
	pointer				operator ->	(void) const;

	normal_iterator		operator +	(const difference_type& diff) const;
	normal_iterator		operator -	(const difference_type& diff) const;

	normal_iterator&	operator +=	(const difference_type& diff);
	normal_iterator&	operator -=	(const difference_type& diff);

	reference			operator [] (const difference_type& diff) const;
	
	const Iterator&		base(void) const;

protected:
	iterator_type _base;
};

template <typename Iterator, typename Container>
normal_iterator<Iterator, Container>::normal_iterator(void) : _base(Iterator()) {
	return ;
}

template <typename Iterator, typename Container>
normal_iterator<Iterator, Container>::normal_iterator(const Iterator& base) : _base(base) {
	return ;
}

template <typename Iterator, typename Container>
template <typename Iter>
normal_iterator<Iterator, Container>::normal_iterator(const normal_iterator<Iter, typename ft::enable_if<std::is_same<Iter, typename Container::pointer>::value, Container>::type>& other) : _base(other.base()) {
	return ;
}

template <typename Iterator, typename Container>
normal_iterator<Iterator, Container>::~normal_iterator() {
	return ;
}

template <typename Iterator, typename Container>
template <typename Iter>
normal_iterator<Iterator, Container>& normal_iterator<Iterator, Container>::operator = (const normal_iterator<Iter, typename ft::enable_if<std::is_same<Iter, typename Container::pointer>::value, Container>::type>& other) {
	if (*this != other)
		_base = other.base();
	return *this;
}

template <typename Iterator, typename Container>
typename normal_iterator<Iterator, Container>::reference normal_iterator<Iterator, Container>::operator * (void) const {
	return *_base;
}

template <typename Iterator, typename Container>
typename normal_iterator<Iterator, Container>::pointer normal_iterator<Iterator, Container>::operator -> (void) const {
	return _base;
}

template <typename Iterator, typename Container>
normal_iterator<Iterator, Container> normal_iterator<Iterator, Container>::operator -- (int) {
	return normal_iterator<Iterator, Container>(_base--);
}

template <typename Iterator, typename Container>
normal_iterator<Iterator, Container>& normal_iterator<Iterator, Container>::operator -- (void) {
	--_base;
	return *this;
}

template <typename Iterator, typename Container>
normal_iterator<Iterator, Container>& normal_iterator<Iterator, Container>::operator ++ (void) {
	++_base;
	return *this;
}

template <typename Iterator, typename Container>
normal_iterator<Iterator, Container> normal_iterator<Iterator, Container>::operator ++ (int) {
	return normal_iterator<Iterator, Container>(_base++);
}

template <typename Iterator, typename Container>
normal_iterator<Iterator, Container> normal_iterator<Iterator, Container>::operator + (const difference_type& diff) const {
	return normal_iterator<Iterator, Container>(_base + diff);
}

template <typename Iterator, typename Container>
normal_iterator<Iterator, Container> normal_iterator<Iterator, Container>::operator - (const difference_type& diff) const {
	return normal_iterator<Iterator, Container>(_base - diff);
}

template <typename Iterator, typename Container>
normal_iterator<Iterator, Container>& normal_iterator<Iterator, Container>::operator += (const difference_type& diff) {
	_base += diff;
	return *this;
}

template <typename Iterator, typename Container>
normal_iterator<Iterator, Container>& normal_iterator<Iterator, Container>::operator -= (const difference_type& diff) {
	_base -= diff;
	return *this;
}

template <typename Iterator, typename Container>
typename normal_iterator<Iterator, Container>::reference normal_iterator<Iterator, Container>::operator [] (const difference_type& diff) const {
	return *(_base + diff);
}

template <typename Iterator, typename Container>
const Iterator& normal_iterator<Iterator, Container>::base(void) const {
	return _base;
}

/* NON-MEMBER OPERATORS */

template <typename Iterator, typename Container> 
bool operator == (const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator == (const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename Iterator, typename Container> 
inline bool operator != (const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs) {
	return (lhs.base() != rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
inline bool operator != (const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() != rhs.base());
}

template <typename Iterator, typename Container> 
bool operator < (const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs) {
	return (lhs.base() < rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator < (const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() < rhs.base());
}

template <typename Iterator, typename Container> 
bool operator <= (const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator <= (const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename Iterator, typename Container> 
bool operator > (const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs) {
	return (lhs.base() > rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator > (const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() > rhs.base());
}

template <typename Iterator, typename Container> 
bool operator >= (const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <typename IteratorL, typename IteratorR, typename Container> 
bool operator >= (const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <typename Iterator, typename Container>
typename normal_iterator<Iterator, Container>::difference_type operator - (const normal_iterator<Iterator, Container>& lhs, const normal_iterator<Iterator, Container>& rhs) {
	return lhs.base() - rhs.base();
}

template <typename IteratorL, typename IteratorR, typename Container>
typename normal_iterator<IteratorL, Container>::difference_type operator - (const normal_iterator<IteratorL, Container>& lhs, const normal_iterator<IteratorR, Container>& rhs) {
	return lhs.base() - rhs.base();
}

template <typename Iterator, typename Container>
normal_iterator<Iterator, Container>	operator + (typename normal_iterator<Iterator, Container>::difference_type n, const normal_iterator<Iterator, Container>& rev_it) {
	return normal_iterator<Iterator, Container>(rev_it.base() + n);
}


} /* FT NAMESPACE */

#endif /* NORMAL_ITERATOR_H */