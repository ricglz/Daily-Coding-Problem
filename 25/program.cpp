#include <iostream>
#include <string>

using namespace std;

bool matchPatter(string sequence, string pattern) {
  int n = sequence.length(), m = pattern.length();
  if(m == 0) {
    return n == 0;
  }
  bool lookup[n+1][m+1];
  memset(lookup, false, sizeof lookup);

  lookup[0][0] = true;

  for(int i = 1; i <= m; i++) {
    if(pattern[i - 1] == '*') lookup[0][i] = lookup[0][i-1];
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(pattern[j - 1] == '*') {
        lookup[i][j] = lookup[i-1][j] || lookup[i][j-1];
      } else if(pattern[j-1] == '.' || sequence[i-1] == pattern[j-1]) {
        lookup[i][j] = lookup[i-1][j-1];
      } else {
        lookup[i][j] = false;
      }
    }
  }
  return lookup[n][m];
}

int main() {
  string sequence, pattern;
  cin >> sequence >> pattern;
  cout << (matchPatter(sequence, pattern) ? "Yes" : "No") << endl;
  return 0;
}
