// begin
template <class T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin() {
  return this->c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::begin() const {
  return this->c.begin();
}

// end
template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
  return this->c.end();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::end() const {
  return this->c.end();
}

// rbegin
template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rbegin() {
  return this->c.rbegin();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rbegin() const {
  return this->c.rbegin();
}

// rend
template <class T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend() {
  return this->c.rend();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rend() const {
  return this->c.rend();
}
