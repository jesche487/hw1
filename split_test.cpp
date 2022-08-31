#include <iostream>
#include "split.h"
using namespace std;

void printLinkedList(Node* head)
{
  while(head != NULL) {
    cout << head->value << " ";
    head = head->next;
  }
}

int main() {
  //cout << "hello world";

  //change nums for testing
  Node n4(4,NULL);
  Node* p4 = &n4;
  Node n3(8,p4);
  Node* p3 = &n3;
  Node n2(2,p3);
  Node* p2 = &n2;
  Node n1(2,p2);
  Node* p1 = &n1;

  Node* odds = NULL;
  Node* evens = NULL;

  printLinkedList(p1);
  cout << endl;

  split(p1, odds, evens);

  printLinkedList(odds);
  cout << endl;
  printLinkedList(evens);
  cout << endl;
  printLinkedList(p1);
  cout << endl;

  return 0;
}