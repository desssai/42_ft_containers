/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:40:12 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/08 18:42:48 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_H
# define LESS_H

namespace ft
{


template <typename T>
class less {
	typedef T		first_argument_type;
	typedef T		second_argument_type;
	typedef bool	result_type;

	bool operator () (const T& lhs, const T& rhs) const { return (lhs < rhs); }
};


} /* FT NAMESPACE */

#endif /* LESS_H */