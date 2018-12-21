#include <iostream>
#include <deque>

using namespace std;

deque<int> kMax(int numbers[], int k, int n) {
  deque<int> deque(k);

  for(int i = 0; i < k; i++) {
    while(!deque.empty() && numbers[i] >= numbers[deque.back()]) {
      deque.pop_back();
    }
    deque.push_back(i);
  }

  for(int i = k; i < n; i++) {
    while(!deque.empty() && deque.front() <= i - k) {
      deque.pop_front();
    }
    while(!deque.empty() && numbers[i] >= numbers[deque.back()]) {
      deque.pop_back();
    }
    deque.push_back(i);
  }

  return deque;
}

int main() {
  int n, k;
  cin >> n;
  int numbers[n];
  for(int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  cin >> k;
  deque<int> ans = kMax(numbers, k, n);
  return 0;
}
