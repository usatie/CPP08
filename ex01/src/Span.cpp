#include "Span.hpp"

#include <algorithm>
#include <iostream>

// Orthodox Canonical Form
Span::Span() : _size(0), _data(0) {
  std::cout << "[ Span Default constructor called ]" << std::endl;
}

Span::Span(const Span& s) : _size(s._size), _data(s._data) {
  std::cout << "[ Span Copy constructor called ]" << std::endl;
}

Span& Span::operator=(const Span& s) {
  std::cout << "[ Span Copy assignment operator called ]" << std::endl;
  if (this != &s) {
    _size = s._size;
    _data = s._data;
  }
  return *this;
}

Span::~Span() { std::cout << "[ Span destructor called ]" << std::endl; }

// Constructor
Span::Span(unsigned int N) : _size(N), _data(0) {
  std::cout << "[ Span constructor called ]" << std::endl;
}

// Member Functions
// addNumber is fast: O(1)
void Span::addNumber(int n) {
  if (_data.size() >= _size) throw std::exception();
  // O(1) push_back
  _data.push_back(n);
}

// shortestSpan and longestSpan are slow: O(nlogn)
int Span::shortestSpan() {
  if (_data.size() < 2) throw std::exception();
  // O(nlogn) sort
  std::sort(_data.begin(), _data.end());
  int span = INT_MAX;
  for (unsigned long i = 0; i < _data.size() - 1; i++)
    span = std::min(span, _data[i + 1] - _data[i]);
  return span;
}

// shortestSpan and longestSpan are slow: O(nlogn)
int Span::longestSpan() {
  if (_data.size() < 2) throw std::exception();
  // O(nlogn) sort
  std::sort(_data.begin(), _data.end());
  int min = *(_data.begin());
  int max = *(_data.end() - 1);
  return max - min;
}
