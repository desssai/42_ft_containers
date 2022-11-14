/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:29:48 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/09 22:26:18 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "vector.hpp"

namespace ft
{

template <typename T, typename Container = ft::vector<T> >
class stack {

public:
	/* MEMBER TYPES */

	typedef typename Container::value_type			value_type;
	typedef typename Container::reference			reference;
	typedef typename Container::const_reference		const_reference;
	typedef typename Container::size_type			size_type;
	typedef Container								container_type;

	/* ASSIGNMENT */

	explicit stack(const Container& _c = Container());
	~stack();

	stack&				operator = (const stack& other);

	/* ELEMENT ACCESS */
	
	reference			top(void);
	const_reference		top(void) const;

	/* CAPACITY */

	bool				empty(void) const;
	size_type			size(void) const;

	/* MODIFIERS */

	void				push(const value_type& val);
	void				pop(void);

	/* NON-MEMBER OPERATORS */

	template <typename Y, typename YContainer>
	friend bool operator == (const stack<Y, YContainer>& lhs, const stack<Y, YContainer>& rhs);
	template <typename Y, typename YContainer>
	friend bool operator != (const stack<Y, YContainer>& lhs, const stack<Y, YContainer>& rhs);
	template <typename Y, typename YContainer>
	friend bool operator <  (const stack<Y, YContainer>& lhs, const stack<Y, YContainer>& rhs);
	template <typename Y, typename YContainer>
	friend bool operator <= (const stack<Y, YContainer>& lhs, const stack<Y, YContainer>& rhs);
	template <typename Y, typename YContainer>
	friend bool operator >  (const stack<Y, YContainer>& lhs, const stack<Y, YContainer>& rhs);
	template <typename Y, typename YContainer>
	friend bool operator >= (const stack<Y, YContainer>& lhs, const stack<Y, YContainer>& rhs);

protected:
	/* ATTRIBUTES */

	Container	c;
};

/* ASSIGNMENT START --> */

template <typename T, typename Container>
stack<T, Container>::stack(const Container& _c) : c(_c) { }

template <typename T, typename Container>
stack<T, Container>::~stack() { }

template <typename T, typename Container>
stack<T, Container>& stack<T, Container>::operator = (const stack& other) {
	if (c != other.c)
		c = other.c;
	return *this;
}

/* <-- ASSIGNMENT END */

/* ELEMENT ACCESS START --> */

template <typename T, typename Container>
typename stack<T, Container>::reference stack<T, Container>::top(void) {
	return c.back();
}

template <typename T, typename Container>
typename stack<T, Container>::const_reference stack<T, Container>::top(void) const {
	return c.back();
}

/* <-- ELEMENT ACCESS END */

/* CAPACITY START --> */

template <typename T, typename Container>
bool	stack<T, Container>::empty(void) const {
	return c.empty();
}

template <typename T, typename Container>
typename stack<T, Container>::size_type	stack<T, Container>::size(void) const {
	return c.size();
}

/* <-- CAPACITY END */

/* MODIFIERS START --> */

template <typename T, typename Container>
void	stack<T, Container>::push(const value_type& val) {
	c.push_back(val);
}

template <typename T, typename Container>
void	stack<T, Container>::pop(void) {
	c.pop_back();
}

/* <-- MODIFIERS END */

/* NON-MEMBER COMPARISON OPERATORS START --> */

template <class Y, class YContainer>
bool operator == (const stack<Y, YContainer>& lhs, const stack<Y, YContainer>& rhs) {
	return (lhs.c == rhs.c);
}

template <class Y, class YContainer>
bool operator != (const stack<Y, YContainer>& lhs, const stack<Y, YContainer>& rhs) {
	return (lhs.c != rhs.c);
}

template <class Y, class YContainer>
bool operator <  (const stack<Y, YContainer>& lhs, const stack<Y, YContainer>& rhs) {
	return (lhs.c < rhs.c);
}

template <class Y, class YContainer>
bool operator <= (const stack<Y, YContainer>& lhs, const stack<Y, YContainer>& rhs) {
	return (lhs.c <= rhs.c);
}

template <class Y, class YContainer>
bool operator >  (const stack<Y, YContainer>& lhs, const stack<Y, YContainer>& rhs) {
	return (lhs.c > rhs.c);
}

template <class Y, class YContainer>
bool operator >= (const stack<Y, YContainer>& lhs, const stack<Y, YContainer>& rhs) {
	return (lhs.c >= rhs.c);
}

/* <-- NON-MEMBER COMPARISON OPERATORS END */


} /* FT NAMESPACE */

#endif /* STACK_H */