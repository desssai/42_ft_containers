/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:12:45 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/22 17:58:56 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_H
# define RED_BLACK_TREE_H

# include <iostream>

# include <memory>
# include "less.hpp"
# include "pair.hpp"
# include "make_pair.hpp"
# include "reverse_iterator.hpp"
# include "red_black_tree_node.hpp"
# include "red_black_tree_iterator.hpp"

namespace ft
{


template <typename T, typename Compare, typename Allocator = std::allocator<ft::node<T> > >
class red_black_tree {

public:
	typedef	T															value_type;
	typedef	T*															pointer;
	typedef	const T*													const_pointer;
	typedef	T&															reference;
	typedef	const T&													const_reference;
	typedef ft::node<value_type>										node_type;
	typedef ft::node<value_type>*										link_type;
	typedef ft::red_black_tree_iterator<value_type, node_type>			iterator;
	typedef ft::const_red_black_tree_iterator<value_type, node_type>	const_iterator;
	typedef ft::reverse_iterator<iterator>								reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
	typedef	Compare														compare_type;
	typedef	typename Allocator::template rebind<node_type>::other		allocator_type;
	typedef	std::ptrdiff_t												difference_type;
	typedef std::size_t													size_type;
	
	red_black_tree(const compare_type& compare = compare_type(), const allocator_type& alloc = allocator_type());
	red_black_tree(const red_black_tree& other);
	~red_black_tree();

	red_black_tree&						operator = (const red_black_tree& other);

	iterator							begin();
	iterator							end();
	const_iterator						begin() const;
	const_iterator						end() const;
	reverse_iterator					rbegin();
	reverse_iterator					rend();
	const_reverse_iterator				rbegin() const;
	const_reverse_iterator				rend() const;

	ft::pair<iterator, bool>			insert(link_type new_node, const value_type& value);
	void								erase(link_type node);

	void								clear(void);

	size_type							size(void) const;

	iterator							find(const value_type& value);
	const_iterator						find(const value_type& value) const;
	iterator							lower_bound(const value_type& key);
	const_iterator						lower_bound(const value_type& key) const;
	iterator							upper_bound(const value_type& key);
	const_iterator						upper_bound(const value_type& key) const;

	link_type		_null;
	link_type		_root;
	size_type		_size;
	compare_type	_compare;
	allocator_type	_alloc;

private:

	void	_M_check_tree(void) const;
	void	_M_check_branches(link_type start, int ref_height, int cur_height = 0)	const;

	void								recursive_copy(link_type* dest, link_type src, link_type _null, link_type parent);

	void								balance_after_insertion(link_type new_node);
	void								balance_after_deletion(link_type new_node);

	link_type							minimum(link_type node = nullptr) const;
	link_type							maximum(link_type node = nullptr) const;
	void								delete_node(link_type node);
	void								clear_tree(link_type node);

	void								right_rotate(link_type node);
	void								left_rotate(link_type node);

	void								link_borders(void);
	void								unlink_borders(void);
};


template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>::red_black_tree(const compare_type& compare, const allocator_type& alloc) :  _null(nullptr), _root(nullptr), _size(0), _compare(compare), _alloc(alloc) {
	_null = _alloc.allocate(1);
	_alloc.construct(_null, value_type());
	_null->left = _null;
	_null->right = _null;
}

template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>::red_black_tree(const red_black_tree& other) : _null(nullptr), _root(nullptr), _size(other._size), _compare(other._compare), _alloc(other._alloc) {
	_null = _alloc.allocate(1);
	_alloc.construct(_null, value_type());
	_null->left = _null;
	_null->right = _null;
	recursive_copy(&_root, other._root, other._null, nullptr);
	link_borders();
}

template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>::~red_black_tree() {
	clear();
	delete_node(_null);
}

template <typename T, typename Compare, typename Allocator>
red_black_tree<T, Compare, Allocator>& red_black_tree<T, Compare, Allocator>::operator = (const red_black_tree& other) {	
	clear();
	_size = other._size;
	_alloc = other._alloc;
	_compare = other._compare;
	recursive_copy(&_root, other._root, other._null, nullptr);
	link_borders();
	return *this;
}

/* ITERATORS START --> */

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::begin() {
	return iterator(_null->left, _null);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::end() {
	return iterator(_null, _null);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::begin() const {
	return const_iterator(_null->left, _null);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::end() const {
	return const_iterator(_null, _null);
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
ft::pair<typename red_black_tree<T, Compare, Allocator>::iterator, bool> red_black_tree<T, Compare, Allocator>::insert(link_type new_node, const value_type& value) {
	(void)new_node;
	(void)value;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::erase(link_type node) {
	(void)node;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::clear(void) {
	clear_tree(_root);
	unlink_borders();
	_size = 0;
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::size_type red_black_tree<T, Compare, Allocator>::size(void) const {
	return _size;
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::find(const value_type& value) {
	iterator it1 = begin();
	iterator it2 = end();
	
	while (it1 != it2) {
		if (!_compare(*it1, value) && !_compare(value, *it1))
			break ;
		++it1;
	}
	return it1;
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::find(const value_type& value) const {
	const_iterator it1 = begin();
	const_iterator it2 = end();
	
	while (it1 != it2) {
		if (!_compare(*it1, value) && !_compare(value, *it1))
			break ;
		++it1;
	}
	return it1;
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::lower_bound(const value_type& value) {
	iterator it1 = begin();
	iterator it2 = end();
	
	while (it1 != it2) {
		if (!_compare(*it1, value))
			break ;
		++it1;
	}
	return it1;
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::lower_bound(const value_type& value) const {
	const_iterator it1 = begin();
	const_iterator it2 = end();
	
	while (it1 != it2) {
		if (!_compare(*it1, value))
			break ;
		++it1;
	}
	return it1;
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::upper_bound(const value_type& value) {
	iterator it1 = begin();
	iterator it2 = end();
	
	while (it1 != it2) {
		if (_compare(value, *it1))
			break ;
		++it1;
	}
	return it1;
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::upper_bound(const value_type& value) const {
	const_iterator it1 = begin();
	const_iterator it2 = end();
	
	while (it1 != it2) {
		if (_compare(value, *it1))
			break ;
		++it1;
	}
	return it1;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::recursive_copy(link_type* dest, link_type src, link_type _null, link_type parent) {
	if (!src || src == _null) {
		*dest = nullptr;
		return ;
	}
	*dest = _alloc.allocate(1);
	_alloc.construct(*dest, *src);
	(*dest)->parent = parent;
	recursive_copy(&(*dest)->left, src->left, _null, *dest);
	recursive_copy(&(*dest)->right, src->right, _null, *dest);
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::delete_node(link_type node) {
	if (node) {
		_alloc.destroy(node);
		_alloc.deallocate(node, 1);
	}
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::clear_tree(link_type node) {
	if(!node || node == _null)
		return ;
	unlink_borders();
	if (node->left)
		clear_tree(node->left);
	if (node->right)
		clear_tree(node->right);
	delete_node(node);
}

template <typename T, typename Compare, typename Allocator>
void	red_black_tree<T, Compare, Allocator>::_M_check_tree(void)	const
			{
				if (!this->_root)
					return ;

				link_type	cursor = this->_root;
				int		height = 1;

				while (cursor)
				{
					if (cursor->color == black)
					height++;
					cursor = cursor->left;
				}

				this->_M_check_branches(this->_root, height);
			}

template <typename T, typename Compare, typename Allocator>
void	red_black_tree<T, Compare, Allocator>::_M_check_branches(link_type start, int ref_height, int cur_height)	const
			{
				if (start && start->color == red && start->parent && start->parent->color == red)
				{
					std::cout << "node: " << start->value.first << std::endl;
					std::cout << "_root: " << _root->value.first << std::endl;
					std::cout << "parent: " << start->parent->value.first << std::endl;
					throw std::logic_error("red child have red parent");
				}

				cur_height += (!start || !(start->color == red));

				if (!start)
				{
					if (cur_height != ref_height)
						throw std::logic_error("number of black nodes differ");

					return ;
				}

				this->_M_check_branches(start->left, ref_height, cur_height);
				this->_M_check_branches(start->right, ref_height, cur_height);
			}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::balance_after_insertion(link_type new_node) {
	(void)new_node;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::balance_after_deletion(link_type node) {
	(void)node;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::right_rotate(link_type node) {
	(void)node;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::left_rotate(link_type node) {
	(void)node;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::link_borders(void) {
	if (!_root)
		return ;
	
	link_type	min = minimum();
	link_type	max = maximum();

	min->left = _null;
	max->right = _null;
	_null->left = min;
	_null->right = max;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::unlink_borders(void) {
	if(_root) {
		minimum()->left = nullptr;
		maximum()->right = nullptr;
	}
	else
		_root = nullptr;
	_null->left = _null;
	_null->right = _null;
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::link_type red_black_tree<T, Compare, Allocator>::minimum(link_type node) const {
	if (!node)
		node = _root;
	while (node->left && node->left != _null)
		node = node->left;
	return node;
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::link_type red_black_tree<T, Compare, Allocator>::maximum(link_type node) const {
	if (!node)
		node = _root;
	while (node->right && node->right != _null)
		node = node->right;
	return node;
}


} /* FT NAMESPACE */

#endif /* RED_BLACK_TREE_H */
