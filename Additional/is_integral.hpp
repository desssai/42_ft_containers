/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:57:28 by ncarob            #+#    #+#             */
/*   Updated: 2022/10/27 00:01:30 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_H
# define IS_INTEGRAL_H

# include "integral_constant.hpp"

namespace ft
{


template <typename T>	class is_integral : public false_type {};

template <> 			class is_integral<bool> : public true_type {};

template <> 			class is_integral<int> : public true_type {};
template <> 			class is_integral<unsigned int> : public true_type {};

template <> 			class is_integral<long int> : public true_type {};
template <> 			class is_integral<unsigned long int> : public true_type {};

template <> 			class is_integral<short int> : public true_type {};
template <> 			class is_integral<unsigned short int> : public true_type {};

template <> 			class is_integral<long long int> : public true_type {};
template <> 			class is_integral<unsigned long long int> : public true_type {};

template <> 			class is_integral<char> : public true_type {};
template <> 			class is_integral<wchar_t> : public true_type {};
template <> 			class is_integral<signed char> : public true_type {};
template <> 			class is_integral<unsigned char> : public true_type {};


}; /* FT NAMESPACE */

#endif /* IS_INTEGRAL_H */