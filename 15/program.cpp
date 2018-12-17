#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int randomElement(vector <int> bigStream) {
  element = bigStream[0];
  srand(time(NULL));
  for(int i = 1, i < bigStream.size(), i++) {
    int j = rand() % (i + 1);
    if(j == 0) element = bigStream[j];
  }
  return element;
}

int main() {
  return 0;
}
