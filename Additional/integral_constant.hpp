/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_constant.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:55:46 by ncarob            #+#    #+#             */
/*   Updated: 2022/10/26 23:56:49 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGRAL_CONSTANT_H
# define INTEGRAL_CONSTANT_H

namespace ft
{


template <typename T, T v>
class integral_constant {

public:
	static const T	value = v;

	typedef	T value_type;
	typedef integral_constant type;

	operator value_type() const { return value; }
};


typedef integral_constant<bool, true>	true_type;
typedef integral_constant<bool, false>	false_type;


}; /* FT NAMESPACE */

# endif /* INTEGRAL_CONSTANT_H */