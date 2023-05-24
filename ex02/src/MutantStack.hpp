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

  // Implicit conversion to Container
  //operator Container() const { return this->c; }

  // begin
  iterator begin();
  const_iterator begin() const;

  // end
  iterator end();
  const_iterator end() const;

  // rbegin
  iterator rbegin();
  const_iterator rbegin() const;

  // rend
  iterator rend();
  const_iterator rend() const;
};

#include "MutantStack.tpp"

#endif
