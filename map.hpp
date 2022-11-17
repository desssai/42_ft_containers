/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:33:47 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/17 23:25:49 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "Additional/red_black_tree.hpp"

namespace ft
{


template <typename Key, typename T, typename Compare = ft::less<T>, typename Allocator = std::allocator<ft::pair<const Key, T> > >
class map {

public:

	typedef	Key																		key_type;
	typedef	T																		mapped_type;
	typedef	ft::pair<const Key, T>													value_type;
	typedef	Compare																	key_compare;

	class value_compare : public std::binary_function<value_type, value_type, bool>
	{
		friend class map;
		
		protected:
			key_compare	m_comparator;
			value_compare(key_compare comparator = key_compare()) : m_comparator(comparator) {};
			value_compare &	operator=(const value_compare & rhd) {
				this->m_comparator = rhd.m_comparator;
				return (*this);
			};
	
		public:
			bool	operator()(const value_type & lhd, const value_type & rhd)	const {
				return (this->m_comparator(lhd.first, rhd.first));
			};
	};

private:
	typedef typename ft::red_black_tree<value_type, value_compare, Allocator>		tree_type;
	
public:
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

	// ft::pair<iterator, bool>	insert(iterator pos, const value_type&, )

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
		_tree.insert(nullptr, *first);
}

template <typename Key, typename T, typename Compare, typename Allocator>
map<Key, T, Compare, Allocator>::map(const map& other) : _tree(other._tree._compare, other._tree._alloc) { }

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
typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::size(void) const {
	return _tree.size();
}

} /* FT NAMESPACE */


#endif /* MAP_H */