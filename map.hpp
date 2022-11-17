/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:33:47 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/17 00:22:28 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "Additional/red_black_tree.hpp"

namespace ft
{


template <typename Key, typename T, typename Compare = ft::less<T>, typename Allocator = std::allocator<ft::pair<const Key, T> > >
class map {

private:
	typedef typename ft::red_black_tree<typename ft::pair<const Key, T>, Compare, Allocator>	tree_type;

public:
	typedef	Key																		key_type;
	typedef	T																		mapped_type;
	typedef	ft::pair<const Key, T>													value_type;
	typedef	Compare																	key_compare;
	// typedef	Compare																	value_compare;
	typedef typename tree_type::pointer 											pointer;
	typedef typename tree_type::const_pointer										const_pointer;
	typedef typename tree_type::reference											reference;
	typedef typename tree_type::const_reference										const_reference;
	typedef typename tree_type::iterator											iterator;
	typedef typename tree_type::const_iterator										const_iterator;
	typedef typename tree_type::reverse_iterator									reverse_iterator;
	typedef typename tree_type::const_reverse_iterator								const_reverse_iterator;
	typedef Allocator																allocator_type;
	typedef	std::ptrdiff_t															difference_type;
	typedef	std::size_t																size_type;

	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	map(const map& other);
	~map();

	iterator					begin();
	iterator					end();
	const_iterator				begin() const;
	const_iterator				end() const;
	reverse_iterator			rbegin();
	reverse_iterator			rend();
	const_reverse_iterator		rbegin() const;
	const_reverse_iterator		rend() const;

	size_type					size(void) const;

	private:
		tree_type				_tree;
};


template <typename Key, typename T, typename Compare, typename Allocator>
map<Key, T, Compare, Allocator>::map (const key_compare& comp, const allocator_type& alloc) : _tree(comp, alloc) { }

template <typename Key, typename T, typename Compare, typename Allocator>
template <class InputIterator>
map<Key, T, Compare, Allocator>::map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc) : _tree(comp, alloc) {
	for (; first != last; ++first)
		_tree.insert(_tree.end(), *first);
}

template <typename Key, typename T, typename Compare, typename Allocator>
map<Key, T, Compare, Allocator>::map(const map& other) {
	_tree = other._tree;
}

template <typename Key, typename T, typename Compare, typename Allocator>
map<Key, T, Compare, Allocator>::~map() { }

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::begin() {
	return _tree.begin();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::end() {
	return _tree.end();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::begin() const {
	return _tree.begin();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::end() const {
	return _tree.end();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::reverse_iterator map<Key, T, Compare, Allocator>::rbegin() {
	return _tree.rbegin();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::reverse_iterator map<Key, T, Compare, Allocator>::rend() {
	return _tree.rend();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::const_reverse_iterator map<Key, T, Compare, Allocator>::rbegin() const {
	return _tree.rbegin();
}

template <typename Key, typename T, typename Compare, typename Allocator>
typename map<Key, T, Compare, Allocator>::const_reverse_iterator map<Key, T, Compare, Allocator>::rend() const {
	return _tree.rend();
}

template <typename Key, typename T, typename Compare, typename Allocator>
size_type					size(void) const;

} /* FT NAMESPACE */

#endif /* MAP_H */