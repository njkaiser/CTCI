// Cracking the Coding Interview, Problem 1.1
// Implement an algorithm to determine if a string has all unique characters. What
// if you can not use additional data structures?

#include <iostream>
#include <string>
#include <algorithm> // std::swap()

using namespace std;


void reverse_string(char* s, int L) {
  for (int i = 0; i < L/2; i++) {
    swap(*(s+i), *(s+L-i-1));
  }
}


int main(int argc, char** argv)
{
  char string1[] = "abc";
  char string2[] = "abcd";

  reverse_string(string1, 3);
  reverse_string(string2, 4);

  cout << "string 1: " << string1 << endl;
  cout << "string 2: " << string2 << endl;

  return 0;
}
