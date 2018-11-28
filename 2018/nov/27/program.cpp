#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
 * The first possible solution that I think of would be
 * simply checking through every other number ahead in
 * the array if there's any that would sum to k.
 * Nevertheless this will be a cuadratic solution, and
 * I want to prioritize time over anything else. So my
 * solution will be to store every number that has
 * already pass in a map and check if one of the next
 * numbers need this specific number to sum to k. I
 * decided for a map because it allows different key
 * values, also because its insertion and read
 * complexity is constant.
*/

bool pairSumsToK(vector<int> numbers, int k) {
  map <int, bool> exists;
  for (int num : numbers) {
    int desiredNumber = k - num;
    if (exists[desiredNumber]) {
      return true;
    }
    exists[num] = true;
  }
  return false;
}

int main(int argc, const char *argv[]) {
  int n, k; // n being the length of the array
  cin >> n;
  vector<int> numbers(n);
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  cin >> k;
  if(pairSumsToK(numbers, k)) {
    cout << "There's a pair that sums to k";
  } else {
    cout << "There isn't a pair that sums to k";
  }
  cout << endl;
  return 0;
}
