#include <iostream>
#include <vector>

using namespace std;

int trappedWater(vector<int> heights) {
  int result = 0, leftMax = 0, rightMax = 0, lo = 0, hi = heights.size() - 1;
  while(lo <= hi) {
    if(heights[lo] < heights[hi]) {
      if(heights[lo] > leftMax) {
        leftMax = heights[lo];
      } else {
        result += leftMax - heights[lo];
        lo++;
      }
    } else {
      if(heights[hi] > rightMax) {
        rightMax = heights[hi];
      } else {
        result += rightMax - heights[hi];
        hi--;
      }
    }
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<int> heights(n);
  for(int i = 0; i < n; i++) {
    cin >> heights[i];
  }
  cout << trappedWater(heights) << endl;
  return 0;
}
