/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree_node.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:12:45 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/23 20:06:11 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_NODE_H
# define RED_BLACK_TREE_NODE_H

namespace ft
{

# include <iostream>

enum node_color {red = true, black = false};

template <typename T>
class node {

public:
	typedef T			value_type;
	typedef T*			pointer;
	typedef	T&			reference;
	typedef node<T>*	link_type;


	node(const value_type& val = value_type());
	node(const node& other);
	~node();

	node&		operator = (const node& other);
	
	bool		is_left_child(void) const;

	link_type	distant_cousin(void);
	link_type	close_cousin(void);
	link_type	grandparent(void);
	link_type	sibling(void);
	link_type	uncle(void);

	value_type	value;
	link_type	parent;
	link_type	left;
	link_type	right;
	node_color	color;
};

template <typename T>
node<T>::node(const value_type& val) : value(val), parent(nullptr), left(nullptr), right(nullptr), color(red) { }

template <typename T>
node<T>::node(const node& other) : value(other.value), parent(other.parent), left(other.left), right(other.right), color(other.color) { }

template <typename T>
node<T>::~node() { }

template <typename T>
node<T>& node<T>::operator = (const node& other) {
	parent = other.parent;
	left = other.left;
	right = other.right;
	color = other.color;
	return *this;
}

template <typename T>
bool node<T>::is_left_child(void) const {
	return (parent->left == this ? true : false);
}

template <typename T>
typename node<T>::link_type node<T>::distant_cousin(void) {
	link_type	sibl = sibling();

	if (!sibl)
		return nullptr;
	else if (sibl->is_left_child())
		return sibl->left;
	else
		return sibl->right;
}

template <typename T>
typename node<T>::link_type node<T>::close_cousin(void) {
	link_type	sibl = sibling();

	if (!sibl)
		return nullptr;
	else if (sibl->is_left_child())
		return sibl->right;
	else
		return sibl->left;
}

template <typename T>
typename node<T>::link_type node<T>::grandparent(void) {
	link_type	copy = this;

	if (copy->parent)
		return copy->parent->parent;
	return nullptr;
}

template <typename T>
typename node<T>::link_type node<T>::sibling(void) {
	link_type	copy = this;

	if (copy->parent)
		return (copy->parent->left == copy ? copy->parent->right : copy->parent->left);
	return nullptr;
}

template <typename T>
typename node<T>::link_type node<T>::uncle(void) {
	link_type	copy = this;

	if (copy->parent && copy->parent->parent)
		return (copy->parent->parent->left == copy->parent ? copy->parent->parent->right : copy->parent->parent->left);
	return nullptr;
}


} /* FT NAMESPACE */

#endif /* RED_BLACK_TREE_NODE_H */