#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Node {
   string val;
   Node* left;
   Node* right;
};

string serialize(Node* root) {
  if(root == NULL) return "NULL";
  return root -> val + serialize(root -> left) + serialize(root -> right);
}

Node* createNode(std::vector<string> words, int& i) {
  if(words[i] == "NULL") {
    i++;
    return NULL;
  }
  Node* root = new Node();
  root -> val = words[i++];
  root -> left = createNode(words, i);
  root -> right = createNode(words, i);
  return root;
}

Node* deserialize(string serializeTree) {
  std::vector<string> words;
  istringstream buf(serializeTree);
  string word;
  while(buf >> word) words.push_back(word);
  int i = 0;
  return createNode(words, i);
}

int main(int argc, const char *argv[]) {
  return 0;
}
