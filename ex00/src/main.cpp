#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"
/*
#include <array>
#include <forward_list>
*/

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

// print test subtitle in white color surrounded by '-'
void printSubtitle(std::string const& subtitle) {
  // print '-'
  std::cout << std::setfill('-') << std::setw(80) << "" << std::endl;
  // print subtitle at the center
  std::cout << std::setfill(' ') << std::setw(40 - subtitle.length() / 2) << ""
            << subtitle << std::endl;
  // print '-'
  std::cout << std::setfill('-') << std::setw(80) << "" << std::endl;
  // reset color
  std::cout << RESET << std::setfill(' ') << std::setw(0);
}

template <typename Container>
std::ostream& easyprint(std::ostream& os, Container const& container) {
  os << "{ ";
  for (typename Container::const_iterator it = container.begin();
       it != container.end(); ++it) {
    if (it != container.begin()) os << ", ";
    os << *it;
  }
  os << " }" << std::endl;
  return os;
}

template <typename E>
std::ostream& operator<<(std::ostream& os, std::vector<E> const& v) {
  return easyprint(os, v);
}

template <typename E>
std::ostream& operator<<(std::ostream& os, std::list<E> const& v) {
  return easyprint(os, v);
}

template <typename E>
std::ostream& operator<<(std::ostream& os, std::deque<E> const& v) {
  return easyprint(os, v);
}

template <typename Container>
void test_easy_find() {
  Container c;
  c.push_back(0);
  c.push_back(1);
  c.push_back(4);
  c.push_back(7);
  printSubtitle("Container");
  std::cout << c << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << i << ": ";
    if (easyfind(c, i) == c.end())
      std::cout << "N/A" << std::endl;
    else
      std::cout << "FOUND" << std::endl;
  }
  printSubtitle("const Container");
  const Container const_c(c);
  std::cout << const_c << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << i << ": ";
    if (easyfind(const_c, i) == const_c.end())
      std::cout << "N/A" << std::endl;
    else
      std::cout << "FOUND" << std::endl;
  }
}

void test_list() {
  printTitle("Test easyfind on std::list<int>");
  test_easy_find<std::list<int> >();
}

void test_vector() {
  printTitle("Test easyfind on std::vector<int>");
  test_easy_find<std::vector<int> >();
}

void test_deque() {
  printTitle("Test easyfind on std::deque<int>");
  test_easy_find<std::deque<int> >();
}

int main(void) {
  test_vector();
  test_list();
  test_deque();
  return 0;
}
