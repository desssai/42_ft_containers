/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:57:17 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/16 23:22:11 by ncarob           ###   ########.fr       */
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
	ft::map<int, int>		tree;

	// tree.insert(nullptr, ft::pair<int, int>(10, 1);
	// tree.insert(nullptr, ft::pair<int, int>(11, 1);
	// tree.insert(nullptr, ft::pair<int, int>(12894, 1);
	// tree.insert(nullptr, ft::pair<int, int>(-12, 112412);
	// tree.insert(nullptr, ft::pair<int, int>(124121235, 1);
	// tree.insert(nullptr, ft::pair<int, int>(1203, 1);
	// tree.insert(nullptr, ft::pair<int, int>(3, 1);
	// tree.insert(nullptr, ft::pair<int, int>(2, 1);
	// tree.insert(nullptr, ft::pair<int, int>(1, 1);

	ft::map<int, int>::iterator		it1 = tree.begin();
	ft::map<int, int>::iterator		it2 = tree.end();
	// ft::map<int, int>::iterator		it3 = tree.begin();
	// ft::red_black_tree<int>::iterator		it4 = &tree._null;
	
	for (; it1 != it2; ++it1)
		std::cout << (*it1).first << "\n";
	// for (; it3 != it2; it3--)
	// 	std::cout << "hety\n";
	
	return 0;
}