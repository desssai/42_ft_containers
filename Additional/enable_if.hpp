/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:33:16 by ncarob            #+#    #+#             */
/*   Updated: 2022/10/26 23:58:31 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
# define ENABLE_IF

namespace ft
{


template <bool Cond = true, typename T = void>
class enable_if {

public:
	typedef T	type;

};


} /* FT NAMESPACE */

#endif /* ENABLE_IF */