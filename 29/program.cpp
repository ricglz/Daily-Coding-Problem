#include <iostream>
#include <string>

using namespace std;

string encode(string sequence) {
  int n = sequence.length();
  string encoded = "";
  for(int i = 0; i < n; i++) {

    int count = 1;
    while(i < n - 1 && sequence[i] == sequence[i+1]) {
      i++;
      count++;
    }

    encoded += to_string(count) + sequence[i];
  }
  return encoded;
}

string multiplyChar(char elem, int count) {
  string str = "";
  for(int i = 0; i < count; i++) {
    str += elem;
  }
  return str;
}

string decode(string sequence) {
  string decoded = "";
  int count = 0;
  for(char elem : sequence) {
    if(elem >= '0' && elem <= '9') {
      count = count * 10 + elem - '0';
    } else {
      decoded += multiplyChar(elem, count);
    }
  }
  return decoded;
}

int main() {
  string sequence;
  cin >> sequence;
  string encoded = encode(sequence);
  cout << encoded << endl;
  cout << (decode(encoded) == sequence ? "Yes" : "No") << endl;
  return 0;
}
