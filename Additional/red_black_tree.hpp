/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:12:45 by ncarob            #+#    #+#             */
/*   Updated: 2023/02/20 19:22:32 by ncarob           ###   ########.fr       */
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
	void								erase(iterator node);

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

	void								recursive_copy(link_type* dest, link_type src, link_type _null, link_type parent);

	void								balance_and_delete(link_type new_node, link_type replacing_node);
	void								replace_node(link_type old_node, link_type new_node);
	void								balance_after_insertion(link_type new_node);
	void								right_rotate(link_type node);
	void								left_rotate(link_type node);

	void								delete_node(link_type node);
	void								clear_tree(link_type node);

	link_type							minimum(link_type node = nullptr) const;
	link_type							maximum(link_type node = nullptr) const;
	void								unlink_borders(void);
	void								link_borders(void);
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
	link_type	parent = nullptr;
	new_node = _root;

	/* Find position for new_node */

	unlink_borders();
	while (new_node) {
		parent = new_node;
		if (_compare(value, new_node->value))
			new_node = new_node->left;
		else if (_compare(new_node->value, value))
			new_node = new_node->right;
		else if (!_compare(value, new_node->value) && !_compare(new_node->value, value)) {
			link_borders();
			return ft::make_pair(iterator(new_node, _null), false);
		}
	}

	/* Create new_node if the same value doesn't exist */

	new_node = _alloc.allocate(1);
	_alloc.construct(new_node, value);

	/* Assign new_node to its parent || root */

	if (!_root)
		_root = new_node;
	else if (_compare(value, parent->value))
		parent->left = new_node;
	else if (_compare(parent->value, value))
		parent->right = new_node;
	new_node->parent = parent;

	/* Rebalance the tree */

	++_size;
	balance_after_insertion(new_node);
	link_borders();
	return ft::make_pair(iterator(new_node, _null), true);
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::erase(iterator iter) {
	link_type	replacing_node = nullptr;
	link_type	buffer_node = nullptr;
	link_type	node = iter._base;

	/* Check if a node exists */

	if (!node || node == _null)
		return ;

	unlink_borders();

	/* Firtsly: perform BST deletion */

	while (true) {

		/* If node is a leaf node ==> replace it with null after balancing */

		if (!node->left && !node->right) {
			replacing_node = nullptr;
			break ;
		}

		/* Else if node has only one child ==> replace the node with its child */

		else if (!node->left) {
			replacing_node = node->right;
			break ;
		}
		else if (!node->right) {
			replacing_node = node->left;
			break ;
		}

		/* Else: node has both children ==> replace it with node's inorder successor */

		else {
			replacing_node = minimum(node->right);

			/* Create a buffer node so as to store inorder successor's value */

			buffer_node = _alloc.allocate(1);
			_alloc.construct(buffer_node, *replacing_node);

			/* Copy node's links and color to buffer node */

			*buffer_node = *node;

			/* Replace node's parent's and children's links so that they point to buffer node */
	
			replace_node(node, buffer_node);
			if (buffer_node->left)
				buffer_node->left->parent = buffer_node;
			if (buffer_node->right)
				buffer_node->right->parent = buffer_node;

			/* Delete previous node with old value that was replaced */

			delete_node(node);
			node = replacing_node;

			/* Assign replacing node to node so as to check if it has children for the deletion in the next iteration */
		}
	}
	balance_and_delete(node, replacing_node);
	link_borders();
	--_size;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::clear(void) {
	unlink_borders();
	clear_tree(_root);
	_root = nullptr;
	_size = 0;
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::size_type red_black_tree<T, Compare, Allocator>::size(void) const {
	return _size;
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::find(const value_type& value) {
	link_type	curr = _root;
	
	while (curr && curr != _null) {
		if (_compare(value, curr->value))
			curr = curr->left;
		else if (_compare(curr->value, value))
			curr = curr->right;
		else if (!_compare(curr->value, value) && !_compare(value, curr->value))
			return iterator(curr, _null);
	}
	return iterator(_null, _null);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::find(const value_type& value) const {
	link_type	curr = _root;
	
	while (curr && curr != _null) {
		if (_compare(value, curr->value))
			curr = curr->left;
		else if (_compare(curr->value, value))
			curr = curr->right;
		else if (!_compare(curr->value, value) && !_compare(value, curr->value))
			return const_iterator(curr, _null);
	}
	return const_iterator(_null, _null);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::lower_bound(const value_type& value) {
	link_type	curr = _root;
	
	while (curr && curr != _null) {	
		if (_compare(value, curr->value) && curr->left && curr->left != _null)
			curr = curr->left;
		else if (_compare(curr->value, value) && curr->right && curr->right != _null)
			curr = curr->right;
		else if (!_compare(curr->value, value) && !_compare(value, curr->value))
			return iterator(curr, _null);
		else if (_compare(value, curr->value) && (!curr->left || curr->left == _null))
			return iterator(curr, _null);
		else if (_compare(curr->value, value) && (!curr->right || curr->right == _null))
			return ++iterator(curr, _null);
	}
	return iterator(_null, _null);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::lower_bound(const value_type& value) const {
	link_type	curr = _root;
	
	while (curr && curr != _null) {
		if (_compare(value, curr->value) && curr->left && curr->left != _null)
			curr = curr->left;
		else if (_compare(curr->value, value) && curr->right && curr->right != _null)
			curr = curr->right;
		else if (!_compare(curr->value, value) && !_compare(value, curr->value))
			return const_iterator(curr, _null);
		else if (_compare(value, curr->value) && (!curr->left || curr->left == _null))
			return const_iterator(curr, _null);
		else if (_compare(curr->value, value) && (!curr->right || curr->right == _null))
			return ++const_iterator(curr, _null);
	}
	return const_iterator(_null, _null);
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::iterator red_black_tree<T, Compare, Allocator>::upper_bound(const value_type& value) {
	iterator it = lower_bound(value);
	
	if (it != end() && !_compare(value, *it) && !_compare(*it, value))
		++it;
	return it;	
}

template <typename T, typename Compare, typename Allocator>
typename red_black_tree<T, Compare, Allocator>::const_iterator red_black_tree<T, Compare, Allocator>::upper_bound(const value_type& value) const {
	const_iterator it = lower_bound(value);
	
	if (it != end() && !_compare(value, *it) && !_compare(*it, value))
		++it;
	return it;
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
	if(!node)
		return ;
	if (node->left)
		clear_tree(node->left);
	if (node->right)
		clear_tree(node->right);
	delete_node(node);
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::balance_after_insertion(link_type new_node) {
	link_type	uncle = nullptr;
	
	while (true) {
		/* CASE 0: If node is root ==> color it black */

		if (!new_node->parent) {
			new_node->color = black;
			break ;
		}

		/* CASE 1: If node parent is black ==> nothing is violated */

		if (new_node->parent->color == black)
			break ;

		uncle = new_node->uncle();

		/* CASE 3: If node's uncle's color is black or if it doesn't exist ==> perform a rotation */

		if (!uncle || uncle->color == black) {
			if (new_node->is_left_child()) {
				if (new_node->parent->is_left_child()) {
					new_node->parent->color = black;
					new_node->parent->parent->color = red;
					right_rotate(new_node->parent->parent);
				}
				else {
					new_node->color = black;
					new_node->parent->parent->color = red;
					right_rotate(new_node->parent);
					left_rotate(new_node->parent);
				}
			}
			else {
				if (new_node->parent->is_left_child()) {
					new_node->color = black;
					new_node->parent->parent->color = red;
					left_rotate(new_node->parent);
					right_rotate(new_node->parent);
				}
				else {
					new_node->parent->color = black;
					new_node->parent->parent->color = red;
					left_rotate(new_node->parent->parent);
				}
			}
			break ;
		}

		/* CASE 4: If node's uncle's color is red ==> change color of parent && uncle to red, change grandparent's color to red */

		else if (uncle->color == red) {
			uncle->color = black;
			new_node->parent->color = black;
			new_node->parent->parent->color = red;
			new_node = new_node->parent->parent;
		}

		/* Check if the result of CASE 4 doesn't violate tree properties on next iterations */
	}
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::balance_and_delete(link_type node, link_type replacing_node) {
	link_type	sibling = nullptr;
	link_type	red_cousin = nullptr;
	link_type	close_cousin = nullptr;
	link_type	distant_cousin = nullptr;

	/* CASE 0: Node is _root && replacing node doesn't exist ==> delete _root and return */

	// std::cout << node->value.first << std::endl;

	if (node == _root && !replacing_node) {
		delete_node(_root);
		_root = nullptr;
		return ;
	}

	/* CASE 1: If either node or replacing node is red (both can't be red) ==> mark replacing node as black */

	if (node->color == red || (replacing_node && replacing_node->color == red)) {
		replace_node(node, replacing_node);
		if (replacing_node)
			replacing_node->color = black;
	}

	/* CASE 2: If both node and replacing node are black */

	else {
		replacing_node = node;
		while (true) {
			/* If double black is root ==> simply break from the loop */

			if (replacing_node == _root)
				break ;

			/* Assign pointers to nodes so as to use them with ease */

			sibling = replacing_node->sibling();
			close_cousin = replacing_node->close_cousin();
			distant_cousin = replacing_node->distant_cousin();
			if (distant_cousin && distant_cousin->color == red)
				red_cousin = distant_cousin;
			else if (close_cousin && close_cousin->color == red)
				red_cousin = close_cousin;
			else
				red_cousin = nullptr;

			/* CASE 2.1: Sibling is black && at least one child is red */

			if (sibling->color == black && red_cousin) {
				if (sibling->is_left_child()) {
					if (red_cousin == distant_cousin) {
						if (replacing_node->parent->color == red) {
							replacing_node->parent->color = black;
							sibling->color = red;
						}
						distant_cousin->color = black;
						right_rotate(replacing_node->parent);
						break ;
					}
					else {
						close_cousin->color = black;
						sibling->color = red;
						left_rotate(sibling);
					}
				}
				else {
					if (red_cousin == close_cousin) {
						close_cousin->color = black;
						sibling->color = red;
						right_rotate(sibling);
					}
					else {
						if (replacing_node->parent->color == red) {
							replacing_node->parent->color = black;
							sibling->color = red;
						}
						red_cousin->color = black;
						left_rotate(replacing_node->parent);
						break ;
					}
				}
			}

			/* CASE 2.2: Sibling is black && both children are black */

			else if (sibling->color == black && !red_cousin) {	
				sibling->color = red;
				if (replacing_node->parent->color == red) {
					replacing_node->parent->color = black;
					break ;
				}
				replacing_node = replacing_node->parent;
			}

			/* CASE 2.3: Sibling is red ==> rotate left or right && recolor sibling aand parent */

			else if (sibling->color == red) {
				replacing_node->parent->color = red;
				sibling->color = black;
				if (sibling->is_left_child())
					right_rotate(replacing_node->parent);
				else
					left_rotate(replacing_node->parent);
			}
		}

		/* Unlink and delete node after balancing */

		if (node->is_left_child())
			node->parent->left = nullptr;
		else
			node->parent->right = nullptr;
	}
	delete_node(node);
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::right_rotate(link_type node) {
	link_type	left_node = node->left;

    replace_node(node, left_node);
    node->left = left_node->right;
    if (left_node->right != NULL)
        left_node->right->parent = node;
    left_node->right = node;
    node->parent = left_node;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::left_rotate(link_type node) {
	link_type	right_node = node->right;

    replace_node(node, right_node);
    node->right = right_node->left;
    if (right_node->left != NULL)
        right_node->left->parent = node;
    right_node->left = node;
    node->parent = right_node;
}

template <typename T, typename Compare, typename Allocator>
void red_black_tree<T, Compare, Allocator>::replace_node(link_type old_node, link_type new_node) {
    if (!old_node->parent)
        _root = new_node;
    else {
        if (old_node->is_left_child())
            old_node->parent->left = new_node;
        else
            old_node->parent->right = new_node;
    }
    if (new_node)
        new_node->parent = old_node->parent;
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
