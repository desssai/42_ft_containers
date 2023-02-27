/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:48:57 by ncarob            #+#    #+#             */
/*   Updated: 2023/02/27 18:14:17 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "deque.hpp"

namespace ft
{


template <typename T, typename Container = ft::deque<T> >
class queue {

public:
	typedef T			value_type;
	typedef T&			reference;
	typedef const T&	const_reference;
	typedef Container	container_type;
	typedef size_t		size_type;

	explicit queue (const container_type& c = container_type());
	queue(const queue& other);
	~queue();

	queue&				operator = (const queue& other);

	bool				empty() const;
	size_type			size() const;
	reference			front();
	const_reference		front() const;
	reference			back();
	const_reference		back() const;
	void				push(const value_type& val);
	void				pop(void);

	template <typename Y, typename YContainer>
	friend bool operator == (const queue<Y, YContainer>& lhs, const queue<Y, YContainer>& rhs);
	template <typename Y, typename YContainer>
	friend bool operator != (const queue<Y, YContainer>& lhs, const queue<Y, YContainer>& rhs);
	template <typename Y, typename YContainer>
	friend bool operator <  (const queue<Y, YContainer>& lhs, const queue<Y, YContainer>& rhs);
	template <typename Y, typename YContainer>
	friend bool operator <= (const queue<Y, YContainer>& lhs, const queue<Y, YContainer>& rhs);
	template <typename Y, typename YContainer>
	friend bool operator >  (const queue<Y, YContainer>& lhs, const queue<Y, YContainer>& rhs);
	template <typename Y, typename YContainer>
	friend bool operator >= (const queue<Y, YContainer>& lhs, const queue<Y, YContainer>& rhs);

private:
	container_type	_c;
};


template <class T, class Container>
queue<T, Container>::queue (const container_type& c) : _c(c) { }

template <class T, class Container>
queue<T, Container>::queue(const queue& other) : _c(other._c) { }

template <class T, class Container>
queue<T, Container>::~queue() { }

template <class T, class Container>
queue<T, Container>& queue<T, Container>::operator = (const queue& other) {
	if (*this != other)
		_c = other._c;
	return *this;
}


template <class T, class Container>
bool queue<T, Container>::empty() const {
	return _c.empty();
}

template <class T, class Container>
typename queue<T, Container>::size_type queue<T, Container>::size() const {
	return _c.size();
}

template <class T, class Container>
typename queue<T, Container>::reference queue<T, Container>::front() {
	return _c.front();
}

template <class T, class Container>
typename queue<T, Container>::const_reference queue<T, Container>::front() const {
	return _c.front();
}

template <class T, class Container>
typename queue<T, Container>::reference queue<T, Container>::back() {
	return _c.back();
}

template <class T, class Container>
typename queue<T, Container>::const_reference queue<T, Container>::back() const {
	return _c.back();
}

template <class T, class Container>
void queue<T, Container>::push(const value_type& val) {
	return _c.push_back(val);
}

template <class T, class Container>
void queue<T, Container>::pop(void) {
	return _c.pop_front();
}


template <class Y, class YContainer>
bool operator == (const queue<Y, YContainer>& lhs, const queue<Y, YContainer>& rhs) {
	return lhs._c == rhs._c;
}

template <class Y, class YContainer>
bool operator != (const queue<Y, YContainer>& lhs, const queue<Y, YContainer>& rhs) {
	return lhs._c != rhs._c;
}

template <class Y, class YContainer>
bool operator < (const queue<Y, YContainer>& lhs, const queue<Y, YContainer>& rhs) {
	return lhs._c < rhs._c;
}

template <class Y, class YContainer>
bool operator <= (const queue<Y, YContainer>& lhs, const queue<Y, YContainer>& rhs) {
	return lhs._c <= rhs._c;
}

template <class Y, class YContainer>
bool operator > (const queue<Y, YContainer>& lhs, const queue<Y, YContainer>& rhs) {
	return lhs._c > rhs._c;
}

template <class Y, class YContainer>
bool operator >= (const queue<Y, YContainer>& lhs, const queue<Y, YContainer>& rhs) {
	return lhs._c >= rhs._c;
}


} /* FT NAMESPACE */

#endif 