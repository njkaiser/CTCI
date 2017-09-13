// Cracking the Coding Interview, Problem 2.5
//
// Given a circular linked list, implement an algorithm which returns node at the
// beginning of the loop.
//
// DEFINITION
// Circular linked list: A (corrupt) linked list in which a node’s next
// pointer points to an earlier node, so as to make a loop in the linked list.
//
// EXAMPLE
// input: A -> B -> C -> D -> E -> C [the same C as earlier]
// output: C

#include <iostream>
#include <unordered_set>

using namespace std;


class Node {
public:
  char data;
  Node* next = NULL;
  Node(char c) { data = c; }
};


Node* detect_circular(Node* head) {
  unordered_set<Node*> s;
  Node* currnode = head;
  while(currnode != NULL) {
    // cout << currnode->data << endl;
    if(s.find(currnode) != s.end()) { return currnode; }
    s.insert(currnode);
    currnode = currnode->next;
  }
  return NULL;
}


Node* tortoise_and_hare(Node* head) {
  Node* slow = head->next;
  Node* fast = head->next->next;
  while(fast != slow) {
    // cout << "tortoise, hare: " << slow->data << ", " << fast->data << endl;
    slow = slow->next;
    fast = fast->next->next;
  }
  slow = head;
  while(fast != slow) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
  // return NULL;
}


int main(int argc, char** argv)
{
  Node* a = new Node('a');
  Node* b = new Node('b');
  Node* c = new Node('c');
  Node* d = new Node('d');
  Node* e = new Node('e');
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = c;

  // cout << "before removal:" << endl;
  // Node *currnode = a;
  // while(currnode != NULL) {
  //   cout << currnode->data << endl;
  //   currnode = currnode->next;
  // }

  Node* answer1 = detect_circular(a);
  Node* answer2 = tortoise_and_hare(a);
  cout << "method 1 answer: " << answer1->data << endl;
  cout << "method 2 answer: " << answer2->data << endl;

  // cout << "after removal:" << endl;
  // currnode = a;
  // while(currnode != NULL) {
  //   cout << currnode->data << endl;
  //   currnode = currnode->next;
  // }

  delete a, b, c, d, e;

  return 0;
}
