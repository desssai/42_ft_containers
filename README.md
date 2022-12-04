# ft_containers

## Overview

The aim of the project is to improve C++ skills by tinkering with C++ standard library containers, understanding them
and reimplementing them. The containers are written in the Orthodox Canonical form. All the C++98 features are present 
(even the deprecated ones). All of the later ones are not. Everything in this project is written inside the `namespace ft`.


The project is about implementing data structures, algorithms, templates, overloads, working with classes, using
inheritance and abstract classes. Every class and every method has the same naming system as the STL ones.

## Usage 

1. Clone the repository to your project's directory.
2. Include the container's header file.
```
# include "ft_containers/vector.hpp"
# include "ft_containers/stack.hpp"
# include "ft_containers/map.hpp"
# include "ft_containers/set.hpp"
```
3. Use them like you would the STL C++ containers.

## Containers

### Vector

Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can 
also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. 
But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.
Internally, vectors use a dynamically allocated array to store their elements. This array may need to be reallocated 
in order to grow in size when new elements are inserted, which implies allocating a new array and moving all elements to it.

https://cplusplus.com/reference/vector/vector/ \
https://en.cppreference.com/w/cpp/container/vector

### Stack

Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out),
where elements are inserted and extracted only from one end of the container. The underlying container may
be any of the standard container class templates or some other specifically designed container class.
The container shall support the following methods: `empty()`, `size()`, `back()`, `push_back()`, `pop_back().`
By default, the underlying container used is `ft::vector`. However, a different object can be passed to the stack during
instanciation.

https://cplusplus.com/reference/stack/stack/ \
https://en.cppreference.com/w/cpp/container/stack

### Map

Maps are associative containers that store elements formed by a combination of a key value and a mapped value,
following a specific order. In a map, the key values are generally used to sort and uniquely identify the elements,
while the mapped values store the content associated to this key. The types of key and mapped value may differ,
and are grouped together in member type `value_type`, which is a `pair` type combining both.
Internally, the elements in a map are always sorted by its key following a specific <b>strict weak ordering.</b>
`ft::map` is implemented as a binary search tree. A red-black-tree to be exact.

https://cplusplus.com/reference/map/map/ \
https://en.cppreference.com/w/cpp/container/map

### Set

Sets are containers that store unique elements following a specific order.
In a set, the value of an element also identifies it (the value is itself the key, of type `T`), and each value
must be unique. The value of the elements in a set cannot be modified once in the container (the elements
are always const), but they can be inserted or removed from the container. Internally, the elements in a
set are always sorted following a specific <b>strict weak ordering.</b> `ft::set` is implemented as a binary search tree.
A red-black-tree to be exact.

https://cplusplus.com/reference/set/set/ \
https://en.cppreference.com/w/cpp/container/set

## Other templates

| Template | Description |
| -------- | ----------- |
| enable_if | The type T is enabled as member type `enable_if::type` if `Cond` is true. |
| equal | Compares the elements in the range `[first1,last1)` with those in the range beginning at `first2`, and returns true if all of the elements in both ranges match. |
| lexicographical_compare | Returns true if the range `[first1,last1)` compares lexicographically less than the range `[first2,last2).` |
| less | Binary function object class whose call returns whether the its first argument compares less than the second (as returned by operator <). |
| integral_constant | This template is designed to provide compile-time constants as types. |
| is_integral | It inherits from `integral_constant` as being either `true_type` or `false_type`, depending on whether `T` is an integral type. |
| pair | This class couples together a pair of values, which may be of different types (`T1` and `T2`). The individual values can be accessed through its public members `first()` and `second().` |
| make_pair | Constructs a `pair` object with its first element set to `x` and its second element set to `y.` |
| red_black_tree | A well-known self-balancing binary search tree that colors its nodes with either red or black colors so as to ensure balancing properties. |
| iterator_traits | Traits class defining properties of iterators. |
| vector_iterator | A random-access iterator for vector |
| red_black_tree_iterator | A bidirectional iterator for red black tree |
| reverse_iterator | A class of an adaptive iterator that reverses the direction in which a bidirectional or random-access iterator iterates through a range. |
