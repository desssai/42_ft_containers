/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:57:17 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/14 12:43:30 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#if 0
# include <stack>
# include <vector>
# include <map>
namespace ft = std ;
#else 
# include "vector.hpp"
# include "stack.hpp"
# include "map.hpp"
#endif

int main(void) {
	ft::map<int, int>	m1;

	m1.insert(m1.begin(), ft::pair<int, int>(10, 10));
	// m1.insert(m1.begin(), ft::pair<int, int>(3, 3));
	// m1.insert(m1.begin(), ft::pair<int, int>(2, 2));
	// m1.insert(m1.begin(), ft::pair<int, int>(1, 1));
	// m1.insert(m1.begin(), ft::pair<int, int>(30, 30));
	// m1.insert(m1.begin(), ft::pair<int, int>(20, 20));
	// m1.insert(m1.begin(), ft::pair<int, int>(0, 0));

	// ft::map<int, int>::iterator	it2 = m1.begin();
	
	// ft::map<int, int>::const_iterator	it3(it2);

	for (int i = 0; i < 2; ++i)
		for (ft::map<int, int>::iterator	it2 = m1.begin(); it2 != m1.end(); ++it2)
			std::cout << it2->first << std::endl;
	
	std::cout << m1.size() << std::endl;

	// std::cout << m1.max_size() << " " << m1.size() << " " << m1.empty() << '\n';

	return 0;
}