#include <iostream>

using namespace std;

int numberOfDecodings(string message, int i = 0) {
  if(i == message.length() || message[i] == '0') return 0;
  int charsLeft = message.length() - i - 1;
  if(charsLeft > 1) {
    if(message[i] == '1' || (message[i] == '2' && message[i+1] <= '6')) {
      return 2 + numberOfDecodings(message, i + 2) +
             numberOfDecodings(message, i + 1);
    }
    return 1 + numberOfDecodings(message, i + 1);
  }
  return 1;
}

int main(int argc, const char *argv[]) {
  string message;
  cin >> message;
  cout << numberOfDecodings(message);
  return 0;
}
