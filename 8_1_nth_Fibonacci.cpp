// Cracking the Coding Interview, Problem 8.1
//
// Write a method to generate the nth Fibonacci number.

#include <iostream>
#include <assert.h>

using namespace std;


int fib(int n) {
  assert(n >= 0);
  if(n == 0) { return 1; }
  if(n == 1) { return 1; }
  return (fib(n-1) + fib(n-2));
}


int main(int argc, char** argv)
{
  int n = 10;

  for(int i = 0; i <= n; i++) {
    cout << "answer for " << i << ": " << fib(i) << endl;
  }

  return 0;
}
