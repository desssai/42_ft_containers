/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:12:45 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/15 14:10:38 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_H
# define RED_BLACK_TREE_H

# include <memory>
# include "less.hpp"
# include "reverse_iterator.hpp"
# include "red_black_tree_node.hpp"
# include "red_black_tree_iterator.hpp"

namespace ft
{


template <typename T, typename Compare = ft::less<T>, typename Allocator = std::allocator<ft::node<T>>>
class red_black_tree {

public:
	typedef	T																	value_type;
	typedef	T*																	pointer;
	typedef	T&																	reference;
	typedef typename ft::node<value_type>										node_type;
	typedef typename ft::node<value_type>*										link_type;
	typedef typename ft::red_black_tree_iterator<value_type, link_type>			iterator;
	typedef typename ft::red_black_tree_iterator<const value_type, link_type>	const_iterator;
	typedef typename ft::reverse_iterator<iterator>								reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>						const_reverse_iterator;
	typedef	Compare																compare_type;
	typedef	typename Allocator::template rebind<T>::other						allocator_type;
	typedef	std::ptrdiff_t														difference_type;
	typedef std::size_t															size_type;
	
	red_black_tree(const compare_type& compare = compare_type(), const allocator_type& alloc = allocator_type());
	red_black_tree(const red_black_tree& other);
	~red_black_tree();

	red_black_tree&	operator = (const red_black_tree& other);

	link_type		_root;
	link_type		_bord;
	size_type		_size;
	compare_type	_compare;
	allocator_type	_alloc;
};


template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>::red_black_tree(const compare_type& compare = compare_type(), const allocator_type& alloc = allocator_type()) :  _root(nullptr), _bord(nullptr), _size(0), _compare(compare), _alloc(alloc) { }

template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>::red_black_tree(const red_black_tree& other) : _compare(other._compare), _alloc(other._alloc), _root(nullptr), _bord(nullptr), _size(0) {
	/* insert in loop */
}

template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>::~red_black_tree() {
	/* clear() */
}

template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>& red_black_tree<T, Compare, Allocator>::operator = (const red_black_tree& other) {
	/* clear() */
	_compare = other._compare;
	_alloc = other._alloc;
	/* insert in loop */
}


} /* FT NAMESPACE */

#endif /* RED_BLACK_TREE_H */
