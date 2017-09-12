// Cracking the Coding Interview, Problem 1.1
// Implement an algorithm to determine if a string has all unique characters. What
// if you can not use additional data structures?

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


bool unique_string_A(const string& s) {
  unordered_set<int> u;
  for (int i = 0; i < s.size(); i++) {
    if(u.count(s[i])) { return false; }
    u.insert(s[i]);
  }
  return true;
}


bool unique_string_B(const string& s) {
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + 1; j < s.size(); j++) {
      if(s[i] == s[j]) { return false; }
    }
  }
  return true;
}


int main(int argc, char** argv)
{
  string string1 = "blah";
  string string2 = "blaah";

  cout << "string 1, method A: " << unique_string_A(string1) << endl;
  cout << "string 2, method A: " << unique_string_A(string2) << endl;
  cout << "string 1, method B: " << unique_string_B(string1) << endl;
  cout << "string 2, method B: " << unique_string_B(string2) << endl;

  return 0;
}
