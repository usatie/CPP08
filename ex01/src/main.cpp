#include <iomanip>
#include <iostream>

#include "Span.hpp"

#define RESET "\033[m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BOLD "\033[1m"

// print title in green color surrounded by '='
void printTitle(std::string const& title) {
  // set color to green
  std::cout << GREEN << BOLD;
  // print '='
  std::cout << std::setfill('=') << std::setw(80) << "" << std::endl;
  // print title at the center
  std::cout << std::setfill(' ') << std::setw(40 - title.length() / 2) << ""
            << title << std::endl;
  // print '='
  std::cout << std::setfill('=') << std::setw(80) << "" << std::endl;
  // reset color
  std::cout << RESET << std::setfill(' ') << std::setw(0);
}

void test_from_subject() {
  printTitle("Test from sunject pdf");
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

void test_random() {
  printTitle("Test randomly generated numbers for 10,000,000 times");
  unsigned int size = 10000000;
  Span sp = Span(size);
  for (unsigned int i = 0; i < size; i++) {
    sp.addNumber(rand());
  }

  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

void test_add_number_range() {
  printTitle("Test addNumber with range");
  Span sp = Span(5);
  std::vector<int> v;
  for (int i = 0; i < 5; i++) {
    v.push_back(i);
  }
  sp.addNumberRange(v.begin(), v.end());
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

void test_add_number_range_exception() {
  printTitle("Test addNumber with range exception");
  Span sp = Span(5);
  std::vector<int> v;
  for (int i = 0; i < 6; i++) {
    v.push_back(i);
  }
  try {
    sp.addNumberRange(v.begin(), v.end());
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

int main(void) {
  srand(time(0));
  test_from_subject();
  test_random();
  test_add_number_range();
  test_add_number_range_exception();
  return 0;
}
