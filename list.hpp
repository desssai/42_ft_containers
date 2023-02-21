#ifndef LIST_H
# define LIST_H

# include <memory>
# include "Additional/equal.hpp"
# include "Additional/is_integral.hpp"
# include "Additional/reverse_iterator.hpp"
# include "Additional/lexicographical_compare.hpp"

namespace ft
{


template <typename T>
class list_node {
public:
	typedef T				value_type;
	typedef list_node<T>*	link_type;

	list_node(const value_type& val = value_type());
	list_node(const list_node& other);

	value_type	val;
	link_type	prev;
	link_type	next;
};

template <typename T>
list_node<T>::list_node(const value_type& _val) : val(_val), prev(nullptr), next(nullptr) {}

template <typename T>
list_node<T>::list_node(const list_node& other) : val(other.val), prev(nullptr), next(nullptr) {}


template <typename T, typename Node>
class list_iterator {
public:
	typedef	Node*								iterator;
	typedef	T									value_type;
	typedef	T*									pointer;
	typedef	T&									reference;
	typedef	std::ptrdiff_t						difference_type;
	typedef	std::bidirectional_iterator_tag		iterator_category;

	list_iterator(const iterator& base = iterator(), const iterator& null = iterator());
	list_iterator(const list_iterator& other);
	~list_iterator();

	list_iterator&	operator = (const list_iterator& other);

	reference		operator * (void) const;
	pointer			operator -> (void) const;

	list_iterator	operator ++ (int);
	list_iterator&	operator ++ (void);
	list_iterator	operator -- (int);
	list_iterator&	operator -- (void);
	
	const iterator&	base(void) const;
	const iterator&	null(void) const;

protected:
	iterator	_base;
	iterator	_null;
};

template <typename T, typename Node>
list_iterator<T, Node>::list_iterator(const iterator& base, const iterator& null) : _base(base), _null(null) { }

template <typename T, typename Node>
list_iterator<T, Node>::list_iterator(const list_iterator& other) : _base(other.base()), _null(other.null()) { }

template <typename T, typename Node>
list_iterator<T, Node>::~list_iterator() { }

template <typename T, typename Node>
list_iterator<T, Node>& list_iterator<T, Node>::operator = (const list_iterator& other) {
	if (*this != other)
		_base = other.base();
	return *this;
}

template <typename T, typename Node>
typename list_iterator<T, Node>::reference list_iterator<T, Node>::operator * (void) const {
	return _base->val;
}

template <typename T, typename Node>
typename list_iterator<T, Node>::pointer list_iterator<T, Node>::operator -> (void) const {
	return &_base->val;
}

template <typename T, typename Node>
list_iterator<T, Node> list_iterator<T, Node>::operator ++ (int) {
	iterator	copy = _base;

	_base = _base->next;
	return copy;
}

template <typename T, typename Node>
list_iterator<T, Node>& list_iterator<T, Node>::operator ++ (void) {
	_base = _base->next;
	return *this;
}

template <typename T, typename Node>
list_iterator<T, Node> list_iterator<T, Node>::operator -- (int) {
	iterator	copy = _base;

	_base = _base->prev;
	return copy;
}

template <typename T, typename Node>
list_iterator<T, Node>& list_iterator<T, Node>::operator -- (void) {
	_base = _base->prev;
	return *this;
}


template <typename T, typename Node>
const typename list_iterator<T, Node>::iterator&	list_iterator<T, Node>::base(void) const {
	return _base;
}

template <typename T, typename Node>
const typename list_iterator<T, Node>::iterator&	list_iterator<T, Node>::null(void) const {
	return _null;
}


template <typename _T, typename _Node>
bool operator == (const list_iterator<_T, _Node>& lhs, const list_iterator<_T, _Node>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename _T, typename _Node>
bool operator != (const list_iterator<_T, _Node>& lhs, const list_iterator<_T, _Node>& rhs) {
	return !(lhs.base() == rhs.base());
}


template <typename T, typename Node>
class const_list_iterator {
public:
	typedef	Node*								iterator;
	typedef	const T								value_type;
	typedef	const T*							pointer;
	typedef	const T&							reference;
	typedef	std::ptrdiff_t						difference_type;
	typedef	std::bidirectional_iterator_tag		iterator_category;

	const_list_iterator(const iterator& base = iterator(), const iterator& null = iterator());
	const_list_iterator(const const_list_iterator& other);
	const_list_iterator(const list_iterator<T, Node>& other);
	~const_list_iterator();

	const_list_iterator&	operator = (const const_list_iterator& other);
	const_list_iterator&	operator = (const list_iterator<T, Node>& other);

	reference				operator * (void) const;
	pointer					operator -> (void) const;

	const_list_iterator		operator ++ (int);
	const_list_iterator&	operator ++ (void);
	const_list_iterator		operator -- (int);
	const_list_iterator&	operator -- (void);
	
	const iterator&			base(void) const;
	const iterator&			null(void) const;

protected:
	iterator	_base;
	iterator	_null;
};

template <typename T, typename Node>
const_list_iterator<T, Node>::const_list_iterator(const iterator& base, const iterator& null) : _base(base), _null(null) { }

template <typename T, typename Node>
const_list_iterator<T, Node>::const_list_iterator(const const_list_iterator& other) : _base(other.base()), _null(other.null()) { }

template <typename T, typename Node>
const_list_iterator<T, Node>::const_list_iterator(const list_iterator<T, Node>& other) : _base(other.base()), _null(other.null()) { }

template <typename T, typename Node>
const_list_iterator<T, Node>::~const_list_iterator() { }

template <typename T, typename Node>
const_list_iterator<T, Node>& const_list_iterator<T, Node>::operator = (const const_list_iterator& other) {
	if (*this != other)
		_base = other.base();
	return *this;
}

template <typename T, typename Node>
const_list_iterator<T, Node>& const_list_iterator<T, Node>::operator = (const list_iterator<T, Node>& other) {
	if (*this != other)
		_base = other.base();
	return *this;
}

template <typename T, typename Node>
typename const_list_iterator<T, Node>::reference const_list_iterator<T, Node>::operator * (void) const {
	return _base->val;
}

template <typename T, typename Node>
typename const_list_iterator<T, Node>::pointer const_list_iterator<T, Node>::operator -> (void) const {
	return &_base->val;
}

template <typename T, typename Node>
const_list_iterator<T, Node> const_list_iterator<T, Node>::operator ++ (int) {
	iterator	copy = _base;

	_base = (_base->next != _null ? _base->next : _null);
	return copy;
}

template <typename T, typename Node>
const_list_iterator<T, Node>& const_list_iterator<T, Node>::operator ++ (void) {
	_base = (_base->next != _null ? _base->next : _null);
	return *this;
}

template <typename T, typename Node>
const_list_iterator<T, Node> const_list_iterator<T, Node>::operator -- (int) {
	iterator	copy = _base;

	_base = (_base->prev != _null ? _base->prev : _null);
	return copy;
}

template <typename T, typename Node>
const_list_iterator<T, Node>& const_list_iterator<T, Node>::operator -- (void) {
	_base = (_base->prev != _null ? _base->prev : _null);
	return *this;
}


template <typename T, typename Node>
const typename const_list_iterator<T, Node>::iterator&	const_list_iterator<T, Node>::base(void) const {
	return _base;
}

template <typename T, typename Node>
const typename const_list_iterator<T, Node>::iterator&	const_list_iterator<T, Node>::null(void) const {
	return _null;
}


template <typename _T, typename _Node>
bool operator == (const const_list_iterator<_T, _Node>& lhs, const const_list_iterator<_T, _Node>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename _T, typename _Node>
bool operator != (const const_list_iterator<_T, _Node>& lhs, const const_list_iterator<_T, _Node>& rhs) {
	return !(lhs.base() == rhs.base());
}

template <typename _T, typename _Node>
bool operator == (const list_iterator<_T, _Node>& lhs, const const_list_iterator<_T, _Node>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename _T, typename _Node>
bool operator != (const list_iterator<_T, _Node>& lhs, const const_list_iterator<_T, _Node>& rhs) {
	return !(lhs.base() == rhs.base());
}

template <typename _TL, typename _TR, typename _Node>
bool operator == (const const_list_iterator<_TL, _Node>& lhs, const list_iterator<_TR, _Node>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename _TL, typename _TR, typename _Node>
bool operator != (const const_list_iterator<_TL, _Node>& lhs, const list_iterator<_TR, _Node>& rhs) {
	return !(lhs.base() == rhs.base());
}


template <typename T, typename Allocator = std::allocator<T> >
class list {
public:
	typedef T 														value_type;

private:
	typedef typename ft::list_node<value_type>						node_type;
	typedef typename ft::list_node<value_type>*						link_type;

public:
	typedef typename Allocator::template rebind<node_type>::other	allocator_type;
	typedef value_type&												reference;
	typedef const value_type&										const_reference;
	typedef value_type*												pointer;
	typedef const value_type*										const_pointer;
	typedef typename ft::list_iterator<T, node_type>				iterator;
	typedef typename ft::const_list_iterator<T, node_type>			const_iterator;
	typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	typedef ptrdiff_t												difference_type;
	typedef size_t													size_type;

	template <class InputIterator>
	list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	explicit list(const allocator_type& alloc = allocator_type());
	explicit list(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
	list(const list& x);
	~list();

	list&					operator = (const list& other);

	iterator				begin();
	const_iterator			begin() const;
	iterator				end();
	const_iterator			end() const;
	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;

	bool					empty() const;
	size_type				size() const;
	size_type				max_size() const;

	reference				front();
	const_reference			front() const;
	reference				back();
	const_reference			back() const;

	template <class InputIterator>
	void					assign(InputIterator first, InputIterator last);
	void					assign(size_type n, const value_type& val);
	void					push_front(const value_type& val);
	void					pop_front();
	void					push_back(const value_type& val);
	void					pop_back();
	template <class InputIterator>
	void					insert(iterator position, InputIterator first, InputIterator last);
	iterator				insert(iterator position, const value_type& val);
    void					insert(iterator position, size_type n, const value_type& val);
	iterator				erase(iterator position);
	iterator				erase(iterator first, iterator last);
	void					swap(list& x);
	void					resize(size_type n, value_type val = value_type());
	void					clear();

	void					splice(iterator position, list& x);
	void					splice(iterator position, list& x, iterator i);
	void					splice(iterator position, list& x, iterator first, iterator last);
	template <class Predicate>
	void					remove_if(Predicate pred);
	void					remove(const value_type& val);
	template <class BinaryPredicate>
	void					unique(BinaryPredicate binary_pred);
	void					unique();
	template <class Compare>
	void					merge(list& x, Compare comp);
	void					merge(list& x);
	template <class Compare>
	void					sort(Compare comp);
	void					sort();
	void					reverse();

	allocator_type			get_allocator() const;

protected:
	allocator_type	_alloc;
	size_type		_size;
	link_type		_null;
	
	template <typename _Integer>
	void					__assign(_Integer size, _Integer val, ft::true_type);
	template <typename _Iterator>
	void					__assign(_Iterator first, _Iterator last, ft::false_type);

	template <typename _Integer>
	void					__insert(iterator position, _Integer size, _Integer val, ft::true_type);
	template <typename _Iterator>
	void					__insert(iterator position, _Iterator first, _Iterator last, ft::false_type);

	template <class Compare>
	link_type				__sort(Compare comp, link_type head);
	link_type				__sort(link_type head);

	template <class Compare>
	link_type				__merge(Compare comp, link_type head1, link_type head2);
	link_type				__merge(link_type head1, link_type head2);
};

template <typename T, typename Allocator>
list<T, Allocator>::list(const allocator_type& alloc) : _alloc(alloc), _size(0) {
	_null = _alloc.allocate(1);
	_alloc.construct(_null, value_type());
	_null->prev = _null;
	_null->next = _null;
}

template <typename T, typename Allocator>
list<T, Allocator>::list(size_type n, const value_type& val, const allocator_type& alloc) : _alloc(alloc), _size(0) {
	_null = _alloc.allocate(1);
	_alloc.construct(_null, value_type());
	_null->prev = _null;
	_null->next = _null;
	assign(n, val);
}

template <typename T, typename Allocator>
template <class InputIterator>
list<T, Allocator>::list(InputIterator first, InputIterator last, const allocator_type& alloc) : _alloc(alloc), _size(0) {
	_null = _alloc.allocate(1);
	_alloc.construct(_null, value_type());
	_null->prev = _null;
	_null->next = _null;
	typedef typename ft::is_integral<InputIterator>::type _Integer;
	__assign(first, last, _Integer());
}

template <typename T, typename Allocator>
list<T, Allocator>::list(const list<T, Allocator>& other) : _alloc(other._alloc), _size(0) {
	_null = _alloc.allocate(1);
	_alloc.construct(_null, value_type());
	_null->prev = _null;
	_null->next = _null;
	__assign(other.begin(), other.end(), ft::false_type());
}

template <typename T, typename Allocator>
list<T, Allocator>::~list() {
	clear();
	_alloc.destroy(_null);
	_alloc.deallocate(_null, 1);
}

template <typename T, typename Allocator>
list<T, Allocator>&	list<T, Allocator>::operator = (const list& other) {
	if (*this != other) {
		_size = 0;
		_alloc = other.get_allocator();
		__assign(other.begin(), other.end(), ft::false_type());
	}
	return *this;
}


template <typename T, typename Allocator>
typename list<T, Allocator>::iterator list<T, Allocator>::begin() {
	return iterator(_null->next, _null);
}

template <typename T, typename Allocator>
typename list<T, Allocator>::const_iterator list<T, Allocator>::begin() const {
	return const_iterator(_null->next, _null);
}

template <typename T, typename Allocator>
typename list<T, Allocator>::iterator list<T, Allocator>::end() {
	return iterator(_null, _null);
}

template <typename T, typename Allocator>
typename list<T, Allocator>::const_iterator list<T, Allocator>::end() const {
	return const_iterator(_null, _null);
}

template <typename T, typename Allocator>
typename list<T, Allocator>::reverse_iterator list<T, Allocator>::rbegin() {
	return reverse_iterator(end());
}

template <typename T, typename Allocator>
typename list<T, Allocator>::const_reverse_iterator list<T, Allocator>::rbegin() const {
	return const_reverse_iterator(end());
}

template <typename T, typename Allocator>
typename list<T, Allocator>::reverse_iterator list<T, Allocator>::rend() {
	return reverse_iterator(begin());
}

template <typename T, typename Allocator>
typename list<T, Allocator>::const_reverse_iterator list<T, Allocator>::rend() const {
	return const_reverse_iterator(begin());
}


template <typename T, typename Allocator>
bool list<T, Allocator>::empty() const {
	return _size ? false : true;
}

template <typename T, typename Allocator>
typename list<T, Allocator>::size_type list<T, Allocator>::size() const {
	return _size;
}

template <typename T, typename Allocator>
typename list<T, Allocator>::size_type list<T, Allocator>::max_size() const {
	return _alloc.max_size() > __LONG_LONG_MAX__ ? __LONG_LONG_MAX__ : _alloc.max_size();
}

template <typename T, typename Allocator>
typename list<T, Allocator>::reference list<T, Allocator>::front() {
	return _null->next->val;
}

template <typename T, typename Allocator>
typename list<T, Allocator>::const_reference list<T, Allocator>::front() const {
	return _null->next->val;
}

template <typename T, typename Allocator>
typename list<T, Allocator>::reference list<T, Allocator>::back() {
	return _null->prev->val;
}

template <typename T, typename Allocator>
typename list<T, Allocator>::const_reference list<T, Allocator>::back() const {
	return _null->prev->val;
}


template <typename T, typename Allocator>
void list<T, Allocator>::assign(size_type n, const value_type& val) {
	clear();
	for (size_type i = 0; i < n; ++i)
		push_front(val);
}

template <typename T, typename Allocator>
template <class InputIterator>
void list<T, Allocator>::assign(InputIterator first, InputIterator last) {
	typedef typename ft::is_integral<InputIterator>::type _Integer;
	__assign(first, last, _Integer());
}

template <typename T, typename Allocator>
template <typename _Integer>
void list<T, Allocator>::__assign(_Integer n, _Integer val, ft::true_type) {
	assign(static_cast<size_type>(n), val);
}

template <typename T, typename Allocator>
template <typename _Iterator>
void list<T, Allocator>::__assign(_Iterator first, _Iterator last, ft::false_type) {
	clear();
	while (first != last)
		push_back(*first++);
}

template <typename T, typename Allocator>
void list<T, Allocator>::push_front(const value_type& val) {
	link_type	ptr = _alloc.allocate(1);

	if (ptr) {
		_alloc.construct(ptr, val);
		_null->next->prev = ptr;
		ptr->next = _null->next;
		ptr->prev = _null;
		_null->next = ptr;
		_size++;
	}
}

template <typename T, typename Allocator>
void list<T, Allocator>::pop_front() {
	link_type	ptr = _null->next;

	if (ptr != _null) {
		ptr->next->prev = _null;
		_null->next = ptr->next;
		_alloc.destroy(ptr);
		_alloc.deallocate(ptr, 1);
		_size--;
	}
}

template <typename T, typename Allocator>
void list<T, Allocator>::push_back(const value_type& val) {
	link_type	ptr = _alloc.allocate(1);

	if (ptr) {
		_alloc.construct(ptr, val);
		_null->prev->next = ptr;
		ptr->prev = _null->prev;
		ptr->next = _null;
		_null->prev = ptr;
		_size++;
	}
}

template <typename T, typename Allocator>
void list<T, Allocator>::pop_back() {
	link_type	ptr = _null->prev;

	if (ptr != _null) {
		ptr->prev->next = _null;
		_null->prev = ptr->prev;
		_alloc.destroy(ptr);
		_alloc.deallocate(ptr, 1);
		_size--;
	}
}

template <typename T, typename Allocator>
template <class InputIterator>
void list<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last) {
	typedef typename ft::is_integral<InputIterator>::type	_Integer;
	__insert(position, first, last, _Integer());
}

template <typename T, typename Allocator>
typename list<T, Allocator>::iterator list<T, Allocator>::insert(iterator position, const value_type& val) {
	link_type	ptr = _alloc.allocate(1);

	if (ptr) {
		_alloc.construct(ptr, val);
		ptr->prev = position.base()->prev;
		position.base()->prev->next = ptr;
		ptr->next = position.base();
		position.base()->prev = ptr;
		_size++;
	}
	return --position;
}

template <typename T, typename Allocator>
void list<T, Allocator>::insert(iterator position, size_type n, const value_type& val) {
	while (n--)
		insert(position, val);
}

template <typename T, typename Allocator>
template <typename _Integer>
void list<T, Allocator>::__insert(iterator position, _Integer n, _Integer val, ft::true_type) {
	insert(position, static_cast<size_type>(n), val);
}

template <typename T, typename Allocator>
template <typename _Iterator>
void list<T, Allocator>::__insert(iterator position, _Iterator first, _Iterator last, ft::false_type) {
	while (first != last)
		insert(position, *first++);
}

template <typename T, typename Allocator>
typename list<T, Allocator>::iterator list<T, Allocator>::erase(iterator position) {	
	link_type ptr = nullptr;
	
	if (position.base() != _null) {
		ptr = position.base();
		++position;
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		_alloc.destroy(ptr);
		_alloc.deallocate(ptr, 1);
		_size--;
	}
	return position;
}

template <typename T, typename Allocator>
typename list<T, Allocator>::iterator list<T, Allocator>::erase(iterator first, iterator last) {
	while (first != last) {
		if (first.base() == _null)
			return first;
		first = erase(first);
	}
	return first;
}

template <typename T, typename Allocator>
void list<T, Allocator>::swap(list& x) {
	iterator	it1 = begin();
	iterator	ite1 = end();
	iterator	it2 = x.begin();
	iterator	ite2 = x.end();

	x.splice(x.begin(), *this);
	splice(begin(), x, it2, ite2);
}

template <typename T, typename Allocator>
void list<T, Allocator>::resize(size_type n, value_type val) {
	if (n > _size) {
		while (n > _size)
			push_back(val);
	}
	else {
		while (_size > n)
			pop_back();
	}
}

template <typename T, typename Allocator>
void list<T, Allocator>::clear() {
	link_type	buf = nullptr;

	while (_size--) {
		buf = _null->next;
		_null->next = buf->next;
		_alloc.destroy(buf);
		_alloc.deallocate(buf, 1);
	}
	_size = 0;
	_null->next = _null;
	_null->prev = _null;
}


template <typename T, typename Allocator>
void list<T, Allocator>::splice(iterator position, list& x) {
	if (x.begin() != x.end()) {
		position.base()->prev->next = x.begin().base();
		x.begin().base()->prev = position.base()->prev;
		position.base()->prev = (--x.end()).base();
		position.base()->prev->next = position.base(); 
		x._null->next = x._null;
		x._null->prev = x._null;
	}
	_size += x._size;
	x._size = 0;
}

template <typename T, typename Allocator>
void list<T, Allocator>::splice(iterator position, list& x, iterator i) {
	i.base()->prev->next = i.base()->next;
	i.base()->next->prev = i.base()->prev;
	i.base()->prev = position.base()->prev;
	i.base()->next = position.base();
	position.base()->prev->next = i.base();
	position.base()->prev = i.base();
	_size++;
	x._size--;
}

template <typename T, typename Allocator>
void list<T, Allocator>::splice(iterator position, list& x, iterator first, iterator last) {
	link_type	fprv = first.base()->prev;

	if (first == last)
		return ;
	first.base()->prev->next = last.base();
	first.base()->prev = position.base()->prev;
	position.base()->prev->next = first.base();
	last.base()->prev->next = position.base();
	position.base()->prev = last.base()->prev;
	last.base()->prev = fprv;
	while (first++ != position) {
		_size++;
		x._size--;
	}
}

template <typename T, typename Allocator>
template <class Predicate>
void list<T, Allocator>::remove_if(Predicate pred) {
	link_type	ptr = _null->next;
	link_type	buf = nullptr;

	while (ptr != _null) {
		if (pred(ptr->val)) {
			buf = ptr->next;
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			_alloc.destroy(ptr);
			_alloc.deallocate(ptr, 1);
			ptr = buf;
			_size--;
		}
		else
			ptr = ptr->next;
	}
}

template <typename T, typename Allocator>
void list<T, Allocator>::remove(const value_type& val) {
	link_type	ptr = _null->next;
	link_type	buf = nullptr;

	while (ptr != _null) {
		if (ptr->val == val) {
			buf = ptr->next;
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			_alloc.destroy(ptr);
			_alloc.deallocate(ptr, 1);
			ptr = buf;
			_size--;
		}
		else
			ptr = ptr->next;
	}
}

template <typename T, typename Allocator>
template <class BinaryPredicate>
void list<T, Allocator>::unique(BinaryPredicate binary_pred) {
	link_type	prv = _null->next;
	link_type	nxt = _null->next->next;

	while (nxt != _null) {
		if (binary_pred(prv->val, nxt->val)) {
			prv->next = nxt->next;
			nxt->next->prev = prv;
			_alloc.destroy(nxt);
			_alloc.deallocate(nxt, 1);
			nxt = prv->next;
			_size--;
		}
		else {
			prv = nxt;
			nxt = nxt->next;
		}
	}
}

template <typename T, typename Allocator>
void list<T, Allocator>::unique() {
	link_type	prv = _null->next;
	link_type	nxt = _null->next->next;

	while (nxt != _null) {
		if (prv->val == nxt->val) {
			prv->next = nxt->next;
			nxt->next->prev = prv;
			_alloc.destroy(nxt);
			_alloc.deallocate(nxt, 1);
			nxt = prv->next;
			_size--;
		}
		else {
			prv = nxt;
			nxt = nxt->next;
		}
	}
}

template <typename T, typename Allocator>
template <class Compare>
void list<T, Allocator>::merge(list& x, Compare comp) {
	iterator	tt = begin();
	iterator	tte = end();
	iterator	xt = x.begin();
	iterator	xte = x.end();
	iterator	buf;

	if (x == *this)
		return ;

	while (tt != tte && xt != xte) {
		if (comp(*xt, *tt)) {
			buf = xt;
			xt++;
			splice(tt, x, buf);
		}
		else
			tt++;
	}
	splice(end(), x);
}

template <typename T, typename Allocator>
void list<T, Allocator>::merge(list& x) {
	iterator	tt = begin();
	iterator	tte = end();
	iterator	xt = x.begin();
	iterator	xte = x.end();
	iterator	buf;

	if (x == *this)
		return ;

	while (tt != tte && xt != xte) {
		if (*tt > *xt) {
			buf = xt;
			xt++;
			splice(tt, x, buf);
		}
		else
			tt++;
	}
	splice(end(), x);
}

template <typename T, typename Allocator>
template <class Compare>
void list<T, Allocator>::sort(Compare comp) {
	link_type	head = nullptr;
	link_type	prev = nullptr;

	if (_size < 2)
		return ;

	head = _null->prev;
	head->next = nullptr;
	head = _null->next;
	head->prev = nullptr;
	_null->next = _null;
	_null->prev = _null;
	head = __sort(comp, head);
	_null->next = head;
	prev = _null;
	while (head->next) {
		head->prev = prev;
		prev = head;
		head = head->next;
	}
	head->next = _null;
	_null->prev = head;
}

template <typename T, typename Allocator>
void list<T, Allocator>::sort() {
	link_type	head = nullptr;
	link_type	prev = nullptr;

	if (_size < 2)
		return ;

	head = _null->prev;
	head->next = nullptr;
	head = _null->next;
	head->prev = nullptr;
	_null->next = _null;
	_null->prev = _null;
	head = __sort(head);
	_null->next = head;
	prev = _null;
	while (head->next) {
		head->prev = prev;
		prev = head;
		head = head->next;
	}
	head->next = _null;
	_null->prev = head;
}

template <typename T, typename Allocator>
template <class Compare>
typename list<T, Allocator>::link_type list<T, Allocator>::__sort(Compare comp, link_type head) {
	link_type	head2 = head;
	link_type	head1 = head;

	while (head1->next && head1->next->next) {
		head2 = head2->next;
		head1 = head1->next->next;
	}

	if (head2->next) {
		head1 = head2->next;
		head2->next = nullptr;
	}
	head2 = head;

	if (head2 && head2->next)
		head2 = __sort(comp, head2);
	if (head1 && head1->next)
		head1 = __sort(comp, head1);

	return __merge(comp, head1, head2);
}

template <typename T, typename Allocator>
typename list<T, Allocator>::link_type list<T, Allocator>::__sort(link_type head) {
	link_type	head2 = head;
	link_type	head1 = head;

	while (head1->next && head1->next->next) {
		head2 = head2->next;
		head1 = head1->next->next;
	}

	if (head2->next) {
		head1 = head2->next;
		head2->next = nullptr;
	}
	head2 = head;

	if (head2 && head2->next)
		head2 = __sort(head2);
	if (head1 && head1->next)
		head1 = __sort(head1);

	return __merge(head1, head2);
}

template <typename T, typename Allocator>
template <class Compare>
typename list<T, Allocator>::link_type list<T, Allocator>::__merge(Compare comp, link_type head1, link_type head2) {
	link_type	ptr = nullptr;
	link_type	head = nullptr;

	while (head1 && head2) {
		if (comp(head2->val, head1->val)) {
			(head ? ptr->next : head) = head2;
			ptr = head2;
			head2 = head2->next;
		}
		else {
			(head ? ptr->next : head) = head1;
			ptr = head1;
			head1 = head1->next;
		}
	}
	while (head1) {
		(head ? ptr->next : head) = head1;
		ptr = head1;
		head1 = head1->next;
	}
	while (head2) {
		(head ? ptr->next : head) = head2;
		ptr = head2;
		head2 = head2->next;
	}
	return head;
}

template <typename T, typename Allocator>
typename list<T, Allocator>::link_type list<T, Allocator>::__merge(link_type head1, link_type head2) {
	link_type	ptr = nullptr;
	link_type	head = nullptr;

	while (head1 && head2) {
		if (head1->val < head2->val) {
			(head ? ptr->next : head) = head1;
			ptr = head1;
			head1 = head1->next;
		}
		else {
			(head ? ptr->next : head) = head2;
			ptr = head2;
			head2 = head2->next;
		}
	}
	while (head1) {
		(head ? ptr->next : head) = head1;
		ptr = head1;
		head1 = head1->next;
	}
	while (head2) {
		(head ? ptr->next : head) = head2;
		ptr = head2;
		head2 = head2->next;
	}
	return head;
}

template <typename T, typename Allocator>
void list<T, Allocator>::reverse() {
	link_type	ptr = _null;
	link_type	buf;

	for (size_type i = 0; i < _size + 1; ++i) {
		buf = ptr->next;
		ptr->next = ptr->prev;
		ptr->prev = buf;
		ptr = buf;
	}
}


template <typename T, typename Allocator>
typename list<T, Allocator>::allocator_type list<T, Allocator>::get_allocator() const {
	return _alloc;
}


template <typename T, typename Allocator>
bool operator == (const list<T, Allocator>& lhs, const list<T, Allocator>& rhs) {
	if (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
		return true;
	return false;
}

template <typename T, typename Allocator>
bool operator != (const list<T, Allocator>& lhs, const list<T, Allocator>& rhs) {
	return !(lhs == rhs);
}

template <typename T, typename Allocator>
bool operator < (const list<T, Allocator>& lhs, const list<T, Allocator>& rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T, typename Allocator>
bool operator <= (const list<T, Allocator>& lhs, const list<T, Allocator>& rhs) {
	return !(rhs < lhs);
}

template <typename T, typename Allocator>
bool operator > (const list<T, Allocator>& lhs, const list<T, Allocator>& rhs) {
	return (rhs < lhs);
}

template <typename T, typename Allocator>
bool operator >= (const list<T, Allocator>& lhs, const list<T, Allocator>& rhs) {
	return !(lhs < rhs);
}

template <class T, class Allocator>
void swap (list<T, Allocator>& x, list<T, Allocator>& y) {
	x.swap(y);
}


} /* FT NAMESPACE */

#endif /* LIST_H */