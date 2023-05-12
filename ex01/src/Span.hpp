#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
 public:
  Span();
  Span(const Span& s);
  Span& operator=(const Span& s);
  ~Span();
  // Constructor
  explicit Span(unsigned int N);
  // Member Functions
  void addNumber(int n);
  int shortestSpan();
  int longestSpan();
  template <typename Container>
  void addNumberRange(typename Container::const_iterator start,
                      typename Container::const_iterator last) {
    for (typename Container::const_iterator it = start; it != last; ++it)
      addNumber(*it);
  }

 private:
  unsigned int _size;
  std::vector<int> _data;
};
#endif
