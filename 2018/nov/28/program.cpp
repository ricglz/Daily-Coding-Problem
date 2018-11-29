#include <iostream>
#include <vector>

using namespace std;

/*
 * The first solution that I came up with is to multiply
 * each element of the array since the start. I also
 * noticed that is very probable that the multiplication
 * of a lot of elements will lead to an overflow. But even
 * if I use long long or other date types this problem may
 * still persist if there are not small data range.
*/
vector<int> multiplyElements(vector<int> nums) {
  int multiplier = 1;
  for (int num : nums) {
    multiplier *= num;
  }
  vector<int> newArray;
  for (int num : nums) {
    newArray.push_back(multiplier / num);
  }
  return newArray;
}

/*
 * But as the followup says now I should solve it with out
 * using division. For these you have to build two arrays,
 * one containing the product of the left numbers and one
 * that contains the one of the right.
*/
vector<int> productArrayConstructor(vector<int> nums) {
  int size = nums.size();
  vector<int> left;
  // For the first number there will be no number at its left
  left.push_back(1);
  for (int i = 1; i < size; i++) {
    left.push_back(left[i - 1] * nums[i - 1]);
  }
  vector<int> right(size);
  // The last number will no have no number at its right
  right[size-1] = 1;
  for (int i = size - 2; i > 0; i--) {
    right[i] = right[i + 1] * nums[i + 1];
  }
  vector<int> productArray;
  for (int i = 0; i < size; i++) {
    productArray.push_back(left[i] * right[i]);
  }
  return productArray;
}

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  vector<int> productArray = productArrayConstructor(nums);
  for (int num : productArray) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
