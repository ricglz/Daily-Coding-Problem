#include <iostream>
#include <climits>
#include <vector>

using namespace std;

vector<long> normalStaircase() {
  vector<long> waysToClimb;
  waysToClimb.push_back(1);
  waysToClimb.push_back(1);
  for (int i = 2; i < INT_MAX; i++) {
    waysToClimb.push_back(waysToClimb[i-1] + waysToClimb[i-2]);
  }
  return waysToClimb;
}

vector<long> newStaircase(vector<int> steps) {
  vector<long> waysToClimb;
  waysToClimb.push_back(1);
  for (int i = 1; i < INT_MAX; i++) {
    int num = 1;
    for(int step : steps) {
      if (i - step >= 0) {
        num += waysToClimb[i - step];
      }
    }
    waysToClimb.push_back(num);
  }
  return waysToClimb;
}

int main(int argc, const char *argv[]) {

  return 0;
}
