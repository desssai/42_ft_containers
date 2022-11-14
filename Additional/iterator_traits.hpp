/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:46:39 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/12 18:51:04 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_H
# define ITERATOR_TRAITS_H

namespace ft
{


template <typename Iterator>
class iterator_traits {

public:
	typedef typename Iterator::iterator_category	iterator_category;
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::pointer				pointer;
};

template <typename T>
class iterator_traits<T*> {

public:
	typedef std::random_access_iterator_tag	iterator_category;
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef T&								reference;
	typedef T*								pointer;
};

template <typename T>
class iterator_traits<const T*> {

public:
	typedef std::random_access_iterator_tag	iterator_category;
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef const T&						reference;
	typedef const T*						pointer;
};


} /* FT NAMESPACE */

#endif /* ITERATOR_TRAITS_H */