#include <iostream>

using namespace std;

struct Node {
  int val;
  Node* next;
};

int printNthLast(Node* head, int n) {
  Node *mainPtr, *refPtr = mainPtr = head;
  int count = 0;

  while(count < n) {
    refPtr = refPtr -> next;
    count++;
  }

  while(refPtr != nullptr) {
    mainPtr = mainPtr -> next;
    refPtr = refPtr -> next;
  }

  return mainPtr -> val;
}
