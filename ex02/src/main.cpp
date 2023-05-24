#include <iomanip>
#include <iostream>
#include <list>
#include <stack>

#include "MutantStack.hpp"

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

void test_from_subject() {
  printTitle("Test with MutantStack from sunject pdf");
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

void test_with_list() {
  printTitle("Test with std::list");
  std::list<int> list;
  list.push_back(5);
  list.push_back(17);
  std::cout << list.back() << std::endl;
  list.pop_back();
  std::cout << list.size() << std::endl;
  list.push_back(3);
  list.push_back(5);
  list.push_back(737);
  //[...]
  list.push_back(0);
  std::list<int>::iterator it = list.begin();
  std::list<int>::iterator ite = list.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int, std::list<int> > s(list);
}

void test_all_methods() {
  printTitle("Test all methods with MutantStack");
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  mstack.pop();
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);

  printSubtitle("Test iterator");
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }

  printSubtitle("Test const_iterator");
  MutantStack<int>::const_iterator cit = mstack.begin();
  MutantStack<int>::const_iterator cite = mstack.end();
  ++cit;
  --cit;
  while (cit != cite) {
    std::cout << *cit << std::endl;
    ++cit;
  }
  printSubtitle("Test reverse iterator");
  MutantStack<int>::reverse_iterator rit = mstack.rbegin();
  MutantStack<int>::reverse_iterator rite = mstack.rend();
  ++rit;
  --rit;
  while (rit != rite) {
    std::cout << *rit << std::endl;
    ++rit;
  }
  printSubtitle("Test const reverse iterator");
  MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
  MutantStack<int>::const_reverse_iterator crite = mstack.rend();
  ++crit;
  --crit;
  while (crit != crite) {
    std::cout << *crit << std::endl;
    ++crit;
  }
}

int main(void) {
  test_all_methods();
  test_from_subject();
  test_with_list();
  return 0;
}
