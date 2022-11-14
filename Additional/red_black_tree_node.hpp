/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree_node.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:12:45 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/14 21:01:57 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_NODE_H
# define RED_BLACK_TREE_NODE_H

namespace ft
{


enum node_color {red = false, black = true};
enum node_side {right = false, left = true, none = true};

/* CLASS TEMPLATE FOR A SINGLE NDOE OF A RED BLACK TREE */
template <typename T>
class node {

public:
	/* MEMBER TYPES */

	typedef T				value_type;
	typedef T*				pointer;
	typedef T& 				reference;
	typedef node<T>*		link_type;
	typedef const node<T>*	const_link_type;
	
	/* ASSIGNMENT */
	
	node(const value_type& _value = value_type());
	node(const node& other);
	~node();

	node& operator = (const node& other);

	/* MEMBER METHODS */

	link_type			minimum(void);
	const_link_type		minimum(void) const;
	link_type			maximum(void);
	const_link_type		maximum(void) const;

	/* ATTRIBUTES */

	value_type	value;
	node_color	color;
	link_type	left;
	link_type	right;
	link_type	parent;
};

/* ASSIGNMENT START --> */

template <typename T>
node<T>::node(const value_type& _value) : value(_value), color(red), left(nullptr), right(nullptr), parent(nullptr) { }

template <typename T>
node<T>::node(const node& other) : value(other.value), color(other.color), left(other.left), right(other.right), parent(other.parent) { }

template <typename T>
node<T>::~node() { }

template <typename T>
node<T>& node<T>::operator = (const node& other) {
	value = other.value;
	color = other.color;
	left = other.left;
	right = other.right;
	parent = other.parent;
}

/* <-- ASSIGNMENT END */

/* MEMBER METHODS START --> */

template <typename T>
typename node<T>::link_type node<T>::minimum(void) {
	link_type	copy(this);

	while (copy->left)
		copy = copy->left;
	return copy;
}

template <typename T>
typename node<T>::const_link_type node<T>::minimum(void) const {
	const_link_type	copy(this);

	while (copy->left)
		copy = copy->left;
	return copy;
}

template <typename T>
typename node<T>::link_type node<T>::maximum(void) {
	link_type	copy(this);

	while (copy->right)
		copy = copy->right;
	return copy;
}

template <typename T>
typename node<T>::const_link_type node<T>::maximum(void) const {
	const_link_type	copy(this);

	while (copy->right)
		copy = copy->right;
	return copy;
}

/* <-- MEMBER METHODS END */


} /* FT NAMESPACE */

#endif /* RED_BLACK_TREE_NODE_H */