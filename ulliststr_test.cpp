/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr test;
  //tests push_back on an empty list
  test.push_back("1");
  //test push_front on making a new Item
  test.push_front("2");
  //tests push_back on a not-full Item
  for(int i = 3; i < 12; i++) {
    test.push_back(to_string(i));
  }
  //push_back makes a new Item here
  test.push_back("12");

  cout << test.get(0) << " " << test.get(1) << " " 
       << test.get(2) << " " << test.get(3) << " " 
       << test.get(4) << " " << test.get(5) << " " 
       << test.get(6) << " " << test.get(7) << " " 
       << test.get(8) << " " << test.get(9) << " " 
       << test.get(10) << " " << test.get(11) << endl;
  // prints: 2 1 3 4 5 6 7 8 9 10 11 12
  cout << test.size() << endl;  // prints 12 

  ULListStr test2;
  //tests push_front on an empty list
  test2.push_front("1");
  //tests push_front on making a new Item
  test2.push_front("2");
  //tests push_front on a not-full Item
  test2.push_front("3");

  cout << test2.get(0) << " " << test2.get(1) << " "
       << test2.get(2) << endl;
  //prints: 3 2 1
  cout << test2.size() << endl; //prints 3

  //prints 3 1
  cout << test2.front() << " " << test2.back() << endl;
  test2.pop_back();
  test2.pop_front();
  cout << test2.get(0) << endl; //prints 2
  cout << test2.size() << endl; //prints 1

  //tests pop_front on empty list
  test2.pop_front();
  cout << test2.size() << endl; //prints 0

  test2.push_front("1");
  cout << test2.get(0) << " " << test2.size() << endl; //prints 1 1
  //tests pop_back on empty list
  test2.pop_back();
  cout << test2.size() << endl; //prints 0

  return 0;
}
