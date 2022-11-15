/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:57:17 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/15 22:51:11 by ncarob           ###   ########.fr       */
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
# include "Additional/red_black_tree.hpp"
#endif

int main(void) {
	ft::red_black_tree<int>					tree;

	tree.insert(nullptr, 10);
	tree.insert(nullptr, 11);

	ft::red_black_tree<int>::iterator		it1 = tree.begin();
	ft::red_black_tree<int>::iterator		it2 = tree.end();
	ft::red_black_tree<int>::iterator		it3 = tree.begin();
	
	for (; it1 != it2; it1++)
		std::cout << *it1 << "hety\n";
	// for (; it3 != it2; it3--)
	// 	std::cout << "hety\n";
	
	return 0;
}