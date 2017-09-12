// Cracking the Coding Interview, Problem 1.1
// Implement an algorithm to determine if a string has all unique characters. What
// if you can not use additional data structures?

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


bool is_anagram(const string& s1, const string& s2) {
  // cout << "string 1, string 2: " << s1 << ", " << s2 << endl;
  unordered_map<char, int> um;
  unordered_map<char, int>::iterator loc;
  for(int i = 0; i < s1.size(); i++) {
    loc = um.find(s1[i]);
    if(loc != um.end()) {
      loc->second += 1;
      // cout << s1[i] << ": " << loc->second << endl;
    }
    else {
      um.insert(pair<char, int>(s1[i], 1));
      // cout << s1[i] << ": " << 1 << endl;
    }
  }

  for(int i = 0; i < s2.size(); i++) {
    loc = um.find(s2[i]);
    if(loc == um.end()) { return false; }
    loc->second -= 1;
    // cout << s2[i] << ": " << loc->second << endl;
  }

  for(loc = um.begin(); loc != um.end(); loc++) {
    if(loc->second) { return false; }
  }

  return true;
}


int main(int argc, char** argv)
{
  string string1 = "abccd";
  string string2 = "dcbca";
  string string3 = "dcdac";

  cout << "string 1, string 2: " << is_anagram(string1, string2) << endl;
  cout << "string 2, string 3: " << is_anagram(string2, string3) << endl;
  cout << "string 3, string 1: " << is_anagram(string3, string1) << endl;

  return 0;
}
