// Copy Constructor
template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : c(other.c) {}

// Destructor (without virtual, thus MutantStack should not be inherited)
template <class T, class Container>
MutantStack<T, Container>::~MutantStack() {}

// Default constructor and constructor
template <class T, class Container>
MutantStack<T, Container>::MutantStack(const Container& cont) : c(cont) {}

// Copy assignment operator
template <class T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(
    const MutantStack& other) {
  if (this != &other) {
    c = other.c;
  }
  return *this;
}

// top
template <class T, class Container>
typename Container::reference MutantStack<T, Container>::top() {
  return c.back();
}

template <class T, class Container>
typename Container::const_reference MutantStack<T, Container>::top() const {
  return c.back();
}

// empty
template <class T, class Container>
bool MutantStack<T, Container>::empty() const {
  return c.empty();
}

// size
template <class T, class Container>
typename Container::size_type MutantStack<T, Container>::size() const {
  return c.size();
}

// push
template <class T, class Container>
void MutantStack<T, Container>::push(
    typename Container::const_reference value) {
  c.push_back(value);
}

// pop
template <class T, class Container>
void MutantStack<T, Container>::pop() {
  c.pop_back();
}

// begin
template <class T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin() {
  return c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::begin() const {
  return c.begin();
}

// end
template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
  return c.end();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::end() const {
  return c.end();
}

// rbegin
template <class T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::rbegin() {
  return c.rbegin();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::rbegin() const {
  return c.rbegin();
}

// rend
template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::rend() {
  return c.rend();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::rend() const {
  return c.rend();
}
