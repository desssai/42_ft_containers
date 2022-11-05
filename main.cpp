/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:57:17 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/05 16:56:44 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#if 0
# include <stack>
# include <vector>
namespace ft = std ;
#else 
# include "vector.hpp"
# include "stack.hpp"
#endif

int main (void) {
	
	{
        ft::stack<long> v1;
        ft::stack<long> v2;

        if (v1 == v2) {
            std::cout << "EQUAL: " << (v1 == v2) << std::endl;
        }
    }
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        for (size_t i = 0; i < 5; ++i)
			v1.push(i);

        if (v1 == v2) {
            std::cout << "EQUAL: " << (v1 == v2) << std::endl;
        }
    }
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        for (size_t i = 0; i < 8; ++i)
			v1.push(i);
        for (size_t i = 0; i < 9; ++i)
			v2.push(i);

        if (v1 == v2) {
            std::cout << "EQUAL: " << (v1 == v2) << std::endl;
        }
    }
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        // for (size_t i = 0; i < 9; ++i)
		// 	v1.push(i);
        for (size_t i = 0; i < 8; ++i)
			v2.push(i);

        // if (v1 == v2) {
        	// std::cout << "EQUAL: " << (v1 == v2) << std::endl;
        // }
    }
    {
        ft::stack<long> v1;
        ft::stack<long> v2;

        for (size_t i = 1; i < 64; ++i)
			v1.push(i);
        for (size_t i = 1; i < 64; ++i)
			v2.push(i);

        if (v1 == v2) {
            std::cout << "EQUAL: " << (v1 == v2) << std::endl;
        }
    }
	{
		ft::stack<int>	v1;

		for (size_t i = 1; i < 64; ++i)
			v1.push(i);

		ft::stack<int>	v2 = v1;
		if (v1 == v2)
            std::cout << "EQUAL: " << (v1 == v2) << std::endl;

	}
	// std::cout << "EQUAL: " << (v1 == v2) << std::endl;
	
	// ft::vector<int>	vec;
	// // ft::vector<long>	vec2(10, 66);

	// // for (size_t i = 0; i < 11; ++i)
	// // 	vec.resize(i, i);

	// // ft::vector<long>::iterator	it1 = vec.begin();
	// // ft::vector<long>::iterator	it2 = vec.end();

	// // std::cout << it1 << std::endl;

	// // vec.insert(it1 + 3, -11);
	// // it1 = vec.begin();
	// // it2 = vec.end();
	// // vec.insert(it2 - 1, -12);
	// // it1 = vec.begin();
	// // it2 = vec.end();
	// // vec.insert(it1, 0);

    // for (size_t i = 0; i < vec.max_size() / 2; ++i) {
	// 	vec.insert(vec.end(), rand());
    // }

	// // vec.insert(vec.end(), 0, 0);
	// // vec.insert(vec.begin(), 5, 1);

	// std::cout << vec.size() << std::endl;
	// std::cout << vec.capacity() << std::endl;

	// // ft::vector<long>::iterator it3 = vec.begin();
	// // ft::vector<long>::iterator it4 = vec.end();

	// // while (it3 != it4)
	// // 	std::cout << *it3++ << " ";
	// // std::cout << std::endl;

	// // ft::iterator_traits<ft::VectorIterator<long> >::iterator_category();

	// // ft::vector<long>::reverse_iterator	rit1 = vec.rbegin();
	// // ft::vector<long>::reverse_iterator	rit2 = vec.rend();

	// // while (rit1 != rit2) {
	// // 	std::cout << (*rit1++) << " ";
	// // 	std::cout << *rit1.base() << std::endl;
	// // }
}
