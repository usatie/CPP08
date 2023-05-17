#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>

template <class T, class Container = std::deque<T> >
class MutantStack {
 private:
  Container c;

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
  operator Container() const { return c; }

  // Copy Constructor
  MutantStack(const MutantStack& other);
  // Destructor (without virtual, thus MutantStack should not be inherited)
  ~MutantStack();
  // Default constructor and constructor
  explicit MutantStack(const Container& cont = Container());
  // Copy assignment operator
  MutantStack& operator=(const MutantStack& other);

  // top
  reference top();
  const_reference top() const;

  // empty
  bool empty() const;

  // size
  size_type size() const;

  // push
  void push(const_reference value);

  // pop
  void pop();

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

template <class T, class Container>
void swap(MutantStack<T, Container>& a, MutantStack<T, Container>& b);

#include "MutantStack.tpp"

#endif
