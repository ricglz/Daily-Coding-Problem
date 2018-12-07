#include <iostream>
#include <algorithm>

using namespace std;

int largestSumNotAdjecent(int arr[], int n) {
  int included = arr[0], excluded = 0;
  for (int i = 1; i < n; i++) {
    int exc_new = max(included, excluded);
    included = excluded + arr[i];
    excluded = exc_new;
  }
  return max(included, excluded);
}

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << largestSumNotAdjecent(arr, n) << endl;
  return 0;
}
