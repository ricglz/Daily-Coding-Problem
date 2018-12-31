#include <iostream>

using namespace std;

int min3(int a, int b, int c) {
  if(a < b) {
    if(a < c) return a;
    return c;
  }
  if(b < c) return b;
  return c;
}

int editDistance(string str1, string str2) {
  int n = str1.length(), m = str2.length();

  int dp[m + 1][n + 1];

  for(int i = 0; i <= n; i++) {
    dp[0][i] = i;
  }
  for(int i = 0; i <= m; i++) {
    dp[i][0] = i;
  }

  for(int i = 0; i <= m; i++) {
    for(int j = 0; j <= n; j++) {
      if(str1[j - 1] == str2[i - 1]) {
        dp[i][j] = dp[i-1][j-1];
      } else {
        dp[i][j] = 1 + min3(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
      }
    }
  }

  return dp[m][n];
}

int main() {
  string str1, str2;
  cin >> str1 >> str2;
  cout << editDistance(str1, str2) << endl;
  return 0;
}
