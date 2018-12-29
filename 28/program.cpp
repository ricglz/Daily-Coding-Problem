#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<string> solve(vector<string> words, int m) {
  vector<string> ans;
  int n = words.size(), i, j, currlen, cost, dp[n], indexes[n];
  dp[n - 1] = 0;
  indexes[n - 1] = n - 1;

  for(i = n - 2; i >= 0; i--) {
    currlen = -1;
    dp[i] = INT_MAX;

    for(j = i; j < n; j++) {
      currlen += (words[j].length() + 1);

      if(currlen > m) break;

      if(j == n - 1) {
        cost = 0;
      } else {
        cost = (m - currlen) * (m - currlen) + dp[j + 1];
      }

      if(cost < dp[i]) {
        dp[i] = cost;
        indexes[i] = j;
      }

    }
  }

  i = 0;
  while(i < n) {
    string line = "";
    for(; i < indexes[i]; i++) {
      line += indexes[i];
    }
    ans.push_back(line);
    i = indexes[i];
  }

  return ans;
}

int main() {
  int n, m;
  cin >> n;
  vector<string> words(n);
  for(int i = 0; i < n; i++) {
    cin >> words[i];
  }
  cin >> m;
  vector<string> justifiedStrings = solve(words, m);
  return 0;
}
