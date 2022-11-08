/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:16:06 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/08 13:46:27 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_H
# define MAKE_PAIR_H

# include "pair.hpp"

namespace ft
{


template <typename T1, typename T2>
pair<T1, T2>	make_pair(T1 _first, T2 _second) {
	return pair<T1, T2>(_first, _second);
}


} /* FT NAMESPACE */

#endif /* MAKE_PAIR_H */