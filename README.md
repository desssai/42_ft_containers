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
# include "ft_containers/list.hpp"
# include "ft_containers/stack.hpp"
# include "ft_containers/deque.hpp"
# include "ft_containers/queue.hpp"
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

### List

Lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence, and iteration in both directions.
List containers are implemented as doubly-linked lists; Doubly linked lists can store each of the elements they contain in different and unrelated storage locations. The ordering is kept internally by the association to each element of a link to the element preceding it and a link to the element following it. Compared to other base standard sequence containers (array, vector and deque), lists perform generally better in inserting, extracting and moving elements in any position within the container for which an iterator has already been obtained, and therefore also in algorithms that make intensive use of these, like sorting algorithms.

https://cplusplus.com/reference/list/list/ \
https://en.cppreference.com/w/cpp/container/list

### Stack

Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out),
where elements are inserted and extracted only from one end of the container. The underlying container may
be any of the standard container class templates or some other specifically designed container class.
The container shall support the following methods: `empty()`, `size()`, `back()`, `push_back()`, `pop_back().`
By default, the underlying container used is `ft::vector`. However, a different object can be passed to the stack during
instanciation.

https://cplusplus.com/reference/stack/stack/ \
https://en.cppreference.com/w/cpp/container/stack

### Deque

Deque is an irregular acronym of double-ended queue. Double-ended queues are sequence containers with dynamic sizes that can be expanded or contracted on both ends (either its front or its back). Both vectors and deques provide a very similar interface and can be used for similar purposes, but internally both work in quite different ways: While vectors use a single array that needs to be occasionally reallocated for growth, the elements of a deque can be scattered in different chunks of storage, with the container keeping the necessary information internally to provide direct access to any of its elements in constant time and with a uniform sequential interface (through iterators). Therefore, deques are a little more complex internally than vectors, but this allows them to grow more efficiently under certain circumstances, especially with very long sequences, where reallocations become more expensive.

https://cplusplus.com/reference/deque/deque \
https://en.cppreference.com/w/cpp/container/deque

### Queue

Queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out), where elements are inserted into one end of the container and extracted from the other. Queues are implemented as containers adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements. Elements are pushed into the "back" of the specific container and popped from its "front". The underlying container may
be any of the standard container class templates or some other specifically designed container class.
The container shall support the following methods: `empty()`, `size()`, `front()`, `back()`, `push_back()`, `pop_front().`

https://cplusplus.com/reference/queue/queue/ \
https://en.cppreference.com/w/cpp/container/queue

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
