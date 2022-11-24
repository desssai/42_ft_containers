/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:33:47 by ncarob            #+#    #+#             */
/*   Updated: 2022/11/24 18:34:49 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include "Additional/less.hpp"
# include "Additional/equal.hpp"
# include "Additional/red_black_tree.hpp"
# include "Additional/lexicographical_compare.hpp"

namespace ft
{


template <typename T, typename Compare = ft::less<T>, typename Allocator = std::allocator<T> >
class set {

public:

	typedef	T																		key_type;
	typedef	T																		value_type;
	typedef	Compare																	key_compare;
	typedef	Compare																	value_compare;

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

	explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	set(const set& other);
	~set();

	set& operator = (const set& other);

	iterator							begin();
	iterator							end();
	const_iterator						begin() const;
	const_iterator						end() const;
	reverse_iterator					rbegin();
	reverse_iterator					rend();
	const_reverse_iterator				rbegin() const;
	const_reverse_iterator				rend() const;

	bool								empty() const;
	size_type							size(void) const;
	size_type							max_size(void) const;

	template <class InputIterator>
	void								insert(InputIterator first, InputIterator last);
	pair<iterator,bool>					insert(const value_type& val);
	iterator							insert(iterator position, const value_type& val);
	void								erase(iterator position);
	size_type							erase(const key_type& k);
    void								erase(iterator first, iterator last);
	void								swap(set& x);
	void								clear(void);

	key_compare							key_comp() const;
	value_compare						value_comp() const;

	iterator							find(const key_type& k);
	const_iterator						find(const key_type& k) const;
	size_type							count(const key_type& k) const;
	iterator							lower_bound(const key_type& k);
	const_iterator						lower_bound(const key_type& k) const;
	iterator							upper_bound(const key_type& k);
	const_iterator 						upper_bound(const key_type& k) const;
	pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
	pair<iterator,iterator>				equal_range(const key_type& k);

	allocator_type						get_allocator() const;

	private:
		tree_type				_tree;
};


template <typename T, typename Compare, typename Allocator>
set<T, Compare, Allocator>::set (const key_compare& comp, const allocator_type& alloc) : _tree(comp, alloc) { }

template <typename T, typename Compare, typename Allocator>
template <class InputIterator>
set<T, Compare, Allocator>::set(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc) : _tree(comp, alloc) {
	for (; first != last; ++first)
		_tree.insert(nullptr, *first);
}

template <typename T, typename Compare, typename Allocator>
set<T, Compare, Allocator>::set(const set& other) : _tree(other._tree._compare, other._tree._alloc) {
	for (const_iterator it1 = other.begin(), it2 = other.end(); it1 != it2; ++it1)
		_tree.insert(nullptr, *it1);
}

template <typename T, typename Compare, typename Allocator>
set<T, Compare, Allocator>::~set() { }

template <typename T, typename Compare, typename Allocator>
set<T, Compare, Allocator>& set<T, Compare, Allocator>::operator = (const set& other) {
	_tree = other._tree;
	return *this;
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::begin() {
	return _tree.begin();
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::end() {
	return _tree.end();
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_iterator set<T, Compare, Allocator>::begin() const {
	return _tree.begin();
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_iterator set<T, Compare, Allocator>::end() const {
	return _tree.end();
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::reverse_iterator set<T, Compare, Allocator>::rbegin() {
	return _tree.rbegin();
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::reverse_iterator set<T, Compare, Allocator>::rend() {
	return _tree.rend();
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_reverse_iterator set<T, Compare, Allocator>::rbegin() const {
	return _tree.rbegin();
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_reverse_iterator set<T, Compare, Allocator>::rend() const {
	return _tree.rend();
}

template <typename T, typename Compare, typename Allocator>
bool set<T, Compare, Allocator>::empty() const {
	return size() ? false : true;
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::size(void) const {
	return _tree.size();
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::max_size(void) const {
	return _tree._alloc.max_size() > __LONG_LONG_MAX__ ? __LONG_LONG_MAX__ : _tree._alloc.max_size();
}

template <typename T, typename Compare, typename Allocator>
template <class InputIterator>
void set<T, Compare, Allocator>::insert(InputIterator first, InputIterator last) {
	for (; first != last; ++first)
		_tree.insert(nullptr, *first);
}

template <typename T, typename Compare, typename Allocator>
ft::pair<typename set<T, Compare, Allocator>::iterator, bool> set<T, Compare, Allocator>::insert(const value_type& val) {
	return _tree.insert(nullptr, val);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::insert(iterator position, const value_type& val) {
	return _tree.insert(position._base, val).first;
}

template <typename T, typename Compare, typename Allocator>
void set<T, Compare, Allocator>::erase(iterator position) {
	_tree.erase(position._base);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::erase(const key_type& k) {
	iterator	it = find(k);

	if (it != end()) {
		_tree.erase(it._base);
		return 1;
	}
	return 0;
}

template <typename T, typename Compare, typename Allocator>
void set<T, Compare, Allocator>::erase(iterator first, iterator last) {
	size_type	arr_size = std::distance(first, last);
	key_type*	array = new key_type [arr_size];

	for (size_type i = 0; first != last; ++first, ++i) {
		array[i] = *first;
	}
	for (size_type i = 0; i < arr_size; ++i) {
		erase(array[i]);
	}
	delete [] array;
}

template <typename T, typename Compare, typename Allocator>
void set<T, Compare, Allocator>::swap(set& x) {
	tree_type	buf = x._tree;

	x._tree = _tree;
	_tree = buf;
}


template <typename T, typename Compare, typename Allocator>
void set<T, Compare, Allocator>::clear(void) {
	_tree.clear();
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::key_compare set<T, Compare, Allocator>::key_comp(void) const {
	return key_compare();	
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::value_compare set<T, Compare, Allocator>::value_comp(void) const {
	return value_compare();
}



template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::find(const key_type& k) {
	return _tree.find(k);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_iterator set<T, Compare, Allocator>::find(const key_type& k) const {
	return _tree.find(k);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::count(const key_type& k) const {
	return (_tree.find(k) == end() ? 0 : 1);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::lower_bound(const key_type& k) {
	return _tree.lower_bound(k);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_iterator set<T, Compare, Allocator>::lower_bound(const key_type& k) const {
	return _tree.lower_bound(k);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::upper_bound(const key_type& k) {
	return _tree.upper_bound(k);
}

template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::const_iterator set<T, Compare, Allocator>::upper_bound(const key_type& k) const {
	return _tree.upper_bound(k);
}

template <typename T, typename Compare, typename Allocator>
ft::pair<typename set<T, Compare, Allocator>::const_iterator, typename set<T, Compare, Allocator>::const_iterator> set<T, Compare, Allocator>::equal_range(const key_type& k) const {
	return ft::make_pair(lower_bound(k), upper_bound(k));
};

template <typename T, typename Compare, typename Allocator>
ft::pair<typename set<T, Compare, Allocator>::iterator, typename set<T, Compare, Allocator>::iterator> set<T, Compare, Allocator>::equal_range(const key_type& k) {
	return ft::make_pair(lower_bound(k), upper_bound(k));
}



template <typename T, typename Compare, typename Allocator>
typename set<T, Compare, Allocator>::allocator_type set<T, Compare, Allocator>::get_allocator() const {
	return allocator_type();
}


template <typename T, typename Compare, typename Allocator>
bool operator	==	(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T, typename Compare, typename Allocator>
bool operator	!=	(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs) {
	return !(lhs == rhs);
}

template <typename T, typename Compare, typename Allocator>
bool operator	<	(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T, typename Compare, typename Allocator>
bool operator	<=	(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs) {
	return !(rhs < lhs);
}

template <typename T, typename Compare, typename Allocator>
bool operator	>	(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs) {
	return (rhs < lhs);
}

template <typename T, typename Compare, typename Allocator>
bool operator	>=	(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs) {
	return !(lhs < rhs);
}

template <typename T, typename Compare, typename Allocator>
void swap(set<T, Compare, Allocator>& lhs, set<T, Compare, Allocator>& rhs) {
	lhs.swap(rhs);
}



} /* FT NAMESPACE */


#endif /* SET_H */