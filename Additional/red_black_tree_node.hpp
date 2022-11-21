/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree_node.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:12:45 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/21 15:13:14 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_NODE_H
# define RED_BLACK_TREE_NODE_H

namespace ft
{


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


} /* FT NAMESPACE */

#endif /* RED_BLACK_TREE_NODE_H */