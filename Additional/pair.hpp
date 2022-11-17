/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:16:51 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/17 22:51:16 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
# define PAIR_H

namespace ft
{


template <typename T1, typename T2>
class pair {

public:
	typedef T1 first_type;
	typedef T2 second_type;

	pair();
	pair(const first_type& _first, const second_type& _second);
	template <typename U1, typename U2>
	pair(const pair<U1, U2>& other);
	~pair();

	pair& operator = (const pair& other);

	first_type	first;
	second_type	second;

};

/* ASSIGNMENT */

template <typename T1, typename T2>
pair<T1, T2>::pair() : first(first_type()), second(second_type()) { }

template <typename T1, typename T2>
pair<T1, T2>::pair(const first_type& _first, const second_type& _second) : first(_first), second(_second) { }

template <typename T1, typename T2>
template <typename U1, typename U2>
pair<T1, T2>::pair(const pair<U1, U2>& other) : first(other.first), second(other.second) { }

template <typename T1, typename T2>
pair<T1, T2>::~pair() { }

template <typename T1, typename T2>
pair<T1, T2>& pair<T1, T2>::operator = (const pair& other) {
	if (*this != other) {
		first = other.first;
		second = other.second;
	}
	return *this;
}

/* NON-MEMBER COMPARISON OPERATOR OVERLOADING */

template <typename T1, typename T2>
bool operator == (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <typename T1, typename T2>
bool operator != (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	return !(lhs == rhs);
}

template <typename T1, typename T2>
bool operator < (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	return (lhs.first < rhs.first && lhs.second < rhs.second);
}

template <typename T1, typename T2>
bool operator <= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	return !(rhs < lhs);
}

template <typename T1, typename T2>
bool operator > (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	return (rhs < lhs);
}

template <typename T1, typename T2>
bool operator >= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	return !(lhs < rhs);
}

} /* FT NAMESPACE */

#endif /* PAIR_H */