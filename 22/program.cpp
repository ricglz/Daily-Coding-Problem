#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool dictionaryContains(string word, unordered_set<string> dictionary) {
  unordered_set<string>::const_iterator got = dictionary.find(word);
  return got != dictionary.end();
}

vector<string> wordBreak(string word, unordered_set<string> dictionary) {
  int n = word.size();
  if(!n) return vector<string>();

  vector<bool> dp(n + 1, false);
  vector<string> ans;

  int match_index = - 1;

  for(int i = 0; i < n; i++) {
    string sb = word.substr(match_index + 1, i - match_index);

    if(dictionaryContains(sb, dictionary)) {
      dp[i] = true;
      match_index = 1;
      ans.push_back(sb);
    }
  }

  return dp[n - 1] ? ans : vector<string>();
}

int main() {
  int n;
  cin >> n;
  unordered_set <string> dictionary;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    dictionary.insert(s);
  }
  string word;
  cin >> word;
  vector <string> words = wordBreak(word, dictionary);
  for(string elem : words) {
    cout << elem << ' ';
  }
  cout << endl;
  return 0;
}
