// Cracking the Coding Interview, Problem 2.3
//
// Implement an algorithm to delete a node in the middle of a single linked list,
// given only access to that node.
//
// EXAMPLE
// Input: the node ‘c’ from the linked list
// a->b->c->d->e
//
// Result: nothing is returned, but the new linked list looks like
// a->b->d->e

#include <iostream>

using namespace std;


class Node {
public:
  char data;
  Node* next = NULL;
  Node(char c) { data = c; }
};


void remove_node(Node* N) {
  // only works with nodes NOT first/last in the list (per the wording of the question)
  N->data = N->next->data;
  Node* tmp = N->next->next;
  // delete N->next;
  N->next = tmp;
}


int main(int argc, char** argv)
{
  Node a('a');
  Node b('b');
  Node c('c');
  Node d('d');
  Node e('e');
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;

  cout << "before removal:" << endl;
  Node *currnode = &a;
  while(currnode != NULL) {
    cout << currnode->data << endl;
    currnode = currnode->next;
  }

  remove_node(&c);

  cout << "after removal:" << endl;
  currnode = &a;
  while(currnode != NULL) {
    cout << currnode->data << endl;
    currnode = currnode->next;
  }

  return 0;
}
