#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string& s, char delimiter) {
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
   }
   return tokens;
}

bool contains(char desired, string sequence) {
  for(char elem : sequence) {
    if(elem == desired) return true;
  }
  return false;
}

bool isFile(string s) {
  for(char elem : s) {
    if(elem == '.') return true;
  }
  return false;
}

int longestPath(string path) {
  stack<int> stack;
  stack.push(0);
  int max = 0;
  vector<string> directories = split(path, '\n');
  for(string elem : directories) {
    int tabs = 0;
    while(elem[tabs] == '\t') tabs++;
    while(tabs + 1 < stack.size()) stack.pop();
    int len = stack.top() + elem.length() - tabs + 1;
    stack.push(len);
    if(isFile(elem) && max < len) max = len;
  }
  return max;
}

int main() {
  string path;
  cin >> path;
  longestPath(path);
  return 0;
}
