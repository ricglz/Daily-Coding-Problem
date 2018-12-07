#include <iostream>

using namespace std;

struct Node {
  int value;
  Node* left, right;
}

int count = 0;

bool sameValue(int nodeValue, Node* node) {
  return node == nullptr ||  nodeValue == node -> value;
}

bool universalTree(Node* root) {
  if(root == nullptr) return true;

  bool leftIsUniversal = universalTree(root -> left),
       rightIsUniversal = universalTree(root -> right);


  if(leftIsUniversal && rightIsUniversal) {
    int value = root -> value;
    bool leftIsSame = sameValue(value, root -> left),
         rightIsSame = sameValue(value, root -> right);
    return left && right;
  }
  return false;
}

int main() {
  return 0;
}
