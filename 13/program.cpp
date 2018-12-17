#include <iostream>

using namespace std;

bool isValid(int count [], int maxCharacters) {
  int charactersCount = 0;
  for(int i = 0; i < 26; i++) {
    if(count[i] > 0 ) charactersCount++;
  }
  return charactersCount <= maxCharacters;
}

int longestSubstring(string sequence, int maxCharacters) {
  int uniqueChars = 0, length = sequence.length();
  int count[26] = { 0 };
  int curr_start, curr_end = curr_start = 0;
  int max_length = 1;

  count[sequence[0] - 'a']++;
  for(int i = 1; i < length; i++) {
    count[sequence[i] - 'a']++;
    curr_end++;

    while(!isValid(count, maxCharacters)) {
      count[sequence[curr_start++] - 'a']--;
    }

    int curr_length = curr_end - curr_start + 1;
    if(curr_length > max_length) max_length = curr_length;
  }
  return max_length;
}

int main() {
  string sequence;
  int maxCharacters;
  cin >> sequence >> maxCharacters;
  cout << longestSubstring(sequence, maxCharacters) << endl;
  return 0;
}
