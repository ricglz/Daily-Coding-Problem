#include <iostream>
#include <climits>

using namespace std;
const int MAX_SIZE = 1000000;
int cost_per_house[MAX_SIZE][MAX_SIZE];

int min(int a, int b) {
  if(a < b) return a;
  return b;
}

int min_cost(int houses, int colors) {
  int dp[houses][colors];

  for(int i = 0; i < colors; i++) {
    dp[0][i] = cost_per_house[0][i];
  }

  for(int i = 1; i < houses; i++) {
    dp[i][0] = cost_per_house[i][0] + min(cost_per_house[i-1][1],
                                          cost_per_house[i-1][2]);
    dp[i][1] = cost_per_house[i][1] + min(cost_per_house[i-1][0],
                                          cost_per_house[i-1][2]);
    dp[i][2] = cost_per_house[i][2] + min(cost_per_house[i-1][1],
                                          cost_per_house[i-1][0]);
  }

  int lastIndex = houses - 1;
  int minCost = dp[lastIndex][0];
  for(int i = 1; i < colors; i++) {
    minCost = min(minCost, dp[lastIndex][i]);
  }
  return minCost;
}

int main() {
  int houses, colors;
  cin >> houses >> colors;
  for(int i = 0; i < houses; i++) {
    for(int j = 0; j < colors; j++) {
      cin >> cost_per_house[i][j];
    }
  }
  cout << min_cost(houses, colors) << endl;
  return 0;
}
