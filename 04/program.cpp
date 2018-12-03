#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int& a, int& b) {
  a^=b;
  b^=a;
  a^=b;
}

int positivesToTheRight(int arr[], int size) {
  int notPositives = 0;
  for (int i = 1; i < size; i++) {
    if (arr[i] <= 0) {
      swap(arr[i++], arr[notPositives]);
    }
  }
  return notPositives;
}

int findPositiveMissing(int arr[], int size) {
  int i = 0;
  for (i = 0; i < size; i++) {
    int positionValue = abs(arr[i]);
    if (positionValue - 1 < size && arr[positionValue - 1] > 0) {
      arr[positionValue - 1] *= -1;
    }
  }
  for (i = 0; i < size; i++) {
    if (arr[i] > 0) {
      return i + 1;
    }
  }
  return size + 1;
}

int findMissing(int arr[], int size) {
  int notPositives = positivesToTheRight(arr, size);
  return findPositiveMissing(arr+notPositives, size-notPositives);
}

int main(int argc, const char *argv[]) {

  return 0;
}
