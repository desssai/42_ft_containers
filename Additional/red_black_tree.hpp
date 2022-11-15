/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:12:45 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/15 22:49:03 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_H
# define RED_BLACK_TREE_H

# include <memory>
# include "less.hpp"
# include "pair.hpp"
# include "make_pair.hpp"
# include "reverse_iterator.hpp"
# include "red_black_tree_node.hpp"
# include "red_black_tree_iterator.hpp"

namespace ft
{


template <typename T, typename Compare = ft::less<T>, typename Allocator = std::allocator<ft::node<T> > >
class red_black_tree {

public:
	typedef	T																	value_type;
	typedef	T*																	pointer;
	typedef	T&																	reference;
	typedef typename ft::node<value_type>										node_type;
	typedef typename ft::node<value_type>*										link_type;
	typedef typename ft::red_black_tree_iterator<value_type, node_type>			iterator;
	typedef typename ft::red_black_tree_iterator<const value_type, node_type>	const_iterator;
	typedef typename ft::reverse_iterator<iterator>								reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>						const_reverse_iterator;
	typedef	Compare																compare_type;
	typedef	typename Allocator::template rebind<node_type>::other				allocator_type;
	typedef	std::ptrdiff_t														difference_type;
	typedef std::size_t															size_type;
	
	red_black_tree(const compare_type& compare = compare_type(), const allocator_type& alloc = allocator_type());
	red_black_tree(const red_black_tree& other);
	~red_black_tree();

	red_black_tree&				operator = (const red_black_tree& other);

	/* ITERATORS */

	iterator					begin();
	iterator					end();
	const_iterator				begin() const;
	const_iterator				end() const;
	reverse_iterator			rbegin();
	reverse_iterator			rend();
	const_reverse_iterator		rbegin() const;
	const_reverse_iterator		rend() const;


	/* MODIFIERS */

	ft::pair<iterator, bool>	insert(link_type position, const value_type& value);
	void						clear(void);

	link_type		_root;
	node_type		_bord;
	size_type		_size;
	compare_type	_compare;
	allocator_type	_alloc;

private:
	link_type					create_node(const value_type& value, link_type parent, node_color color);
	void						link_borders(node_type& _bord, link_type _begin, link_type _end);

};


template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>::red_black_tree(const compare_type& compare, const allocator_type& alloc) :  _root(nullptr), _bord(value_type()), _size(0), _compare(compare), _alloc(alloc) { }

template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>::red_black_tree(const red_black_tree& other) : _compare(other._compare), _alloc(other._alloc), _root(nullptr), _bord(value_type()), _size(0) {
	/* insert in loop */
	/* TO-DO */
}

template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>::~red_black_tree() {
	clear();
}

template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>& red_black_tree<T, Compare, Allocator>::operator = (const red_black_tree& other) {
	clear();
	_compare = other._compare;
	_alloc = other._alloc;
	/* insert in loop */
	/* TO-DO */
}

/* ITERATORS START --> */

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::begin() {
	return iterator(_bord.left, &_bord);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::end() {
	return iterator(&_bord, &_bord);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::begin() const {
	return const_iterator(_bord.left, &_bord);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::end() const {
	return const_iterator(&_bord, &_bord);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::reverse_iterator red_black_tree<T, Compare, Allocator>::rbegin() {
	return reverse_iterator(end());
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::reverse_iterator red_black_tree<T, Compare, Allocator>::rend() {
	return reverse_iterator(begin());
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_reverse_iterator red_black_tree<T, Compare, Allocator>::rbegin() const {
	return const_reverse_iterator(end());
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_reverse_iterator red_black_tree<T, Compare, Allocator>::rend() const {
	return const_reverse_iterator(begin());
}

/* <-- ITERATORS END */

template <typename T, typename Compare, typename Allocator>
ft::pair<typename red_black_tree<T, Compare, Allocator>::iterator, bool> red_black_tree<T, Compare, Allocator>::insert(link_type position, const value_type& value) {
	ft::pair<iterator, bool>	ret;

	if (!_size) {
		_root = create_node(value, nullptr, black);
		link_borders(_bord, _root, _root);
	}
	else {
		link_type	curr = (position ? position : _root);
		link_type	parent = curr;
		bool		is_left = false;

		while (curr && curr != &_bord) {
			if (_compare(value, curr->value)) {
				curr = curr->left;
				is_left = true;
			}
			else if (_compare(curr->value, value)) {
				curr = curr->right;
				is_left = false;
			}
			else {
				ret.first = curr;
				return ret;
			}
		}
		curr = create_node(value, parent, red);
		if (is_left) {
			if (parent->left == &_bord)
				_bord.left = curr;
			parent->left = curr;
		}
		else {
			if (parent->right == &_bord)
				_bord.right = curr;
			parent->right = curr;
		}
		ret.first = curr;
		std::cout << "|HERE|\n";
	}
	ret.second = true;
	++_size;
	/* REBALANCE */
	return ret;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::clear(void) {
	if (_size) {
		_alloc.destroy(_root);
		_alloc.deallocate(_root, 1);
	}
	/* TO-DO */
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::link_type red_black_tree<T, Compare, Allocator>::create_node(const value_type& value, link_type parent, node_color color) {
	link_type	node = _alloc.allocate(1);
	
	_alloc.construct(node, value);
	if (parent)
		node->parent = parent;
	node->color = color;
	return node;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::link_borders(node_type& _bord, link_type _begin, link_type _end) {
	_bord.left = _begin;
	_bord.right = _end;
	if (_begin)
		_begin->left = &_bord;
	if (_end)
		_end->right = &_bord;
}

} /* FT NAMESPACE */

#endif /* RED_BLACK_TREE_H */
