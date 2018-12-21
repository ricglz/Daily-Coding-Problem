#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> kMax(int numbers[], int k, int n) {
  deque<int> deque(k);
  vector<int> v;

  for(int i = 0; i < k; i++) {
    while(!deque.empty() && numbers[i] >= numbers[deque.back()]) {
      deque.pop_back();
    }
    deque.push_back(i);
  }

  v.push_back(numbers[deque.front()]);

  for(int i = k; i < n; i++) {
    while(!deque.empty() && deque.front() <= i - k) {
      deque.pop_front();
    }
    while(!deque.empty() && numbers[i] >= numbers[deque.back()]) {
      deque.pop_back();
    }
    deque.push_back(i);
    v.push_back(numbers[deque.front()]);
  }

  return v;
}

int main() {
  int n, k;
  cin >> n;
  int numbers[n];
  for(int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  cin >> k;
  vector<int> ans = kMax(numbers, k, n);
  return 0;
}
