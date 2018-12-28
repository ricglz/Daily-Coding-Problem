#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool wellFormed(string s) {
  stack <char> stack;
  unordered_map <char, char> pairs;
  pairs['('] = ')';
  pairs['{'] = '}';
  pairs['['] = ']';
  for(char elem : s) {
    if(elem == '{' || elem == '[' || elem == '(') {
      stack.push(elem);
    } else if(elem == '}' || elem == ']' || elem == ')') {
      char pair = stack.top();
      if(pairs[pair] != elem) return false;
    }
  }
  return true;
}

int main() {
  string sequence;
  cin >> sequence;
  cout << (wellFormed(sequence) ? "Yes" : "No") << endl;
  return 0;
}
