/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:51:22 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/14 20:24:02 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_H
# define EQUAL_H

namespace ft
{


template <typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return false;
		++first1;
		++first2;
	}
	return (true);
}

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
	while (first1 != last1)
	{
		if (!pred(*first1, *first2))
			return false;
		++first1;
		++first2;
	}
	return (true);
}


} /* FT NAMESPACE */

#endif /* EQUAL_H */