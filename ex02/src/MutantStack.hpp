#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
 public:
  // Member types
  typedef Container container_type;
  typedef typename Container::value_type value_type;
  typedef typename Container::size_type size_type;
  typedef typename Container::reference reference;
  typedef typename Container::const_reference const_reference;
  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;
  typedef typename Container::reverse_iterator reverse_iterator;
  typedef typename Container::const_reverse_iterator const_reverse_iterator;

  // Implicit conversion to Container
  //operator Container() const { return this->c; }

  // begin
  iterator begin();
  const_iterator begin() const;

  // end
  iterator end();
  const_iterator end() const;

  // rbegin
  reverse_iterator rbegin();
  const_reverse_iterator rbegin() const;

  // rend
  reverse_iterator rend();
  const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif
