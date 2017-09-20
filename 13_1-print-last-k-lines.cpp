// Cracking the Coding Interview, Problem 13.1
//
// Write a method to print the last K lines of an input file using C++.


#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;


int main(int argc, char** argv)
{
  int nlines = 4;
  string s;
  list<string> l;

  ifstream ifs;
  ifs.open("13_1-example-file.txt", ios::in);
  while(getline(ifs, s)) {
    l.push_back(s);
    if(l.size() > 4) { l.pop_front(); }
  }
  ifs.close();

  list<string>::iterator it = l.begin();
  while(it != l.end()) { cout << *it++ << endl; }

  return 0;
}
