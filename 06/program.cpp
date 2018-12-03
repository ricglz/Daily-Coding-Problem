#include <iostream>

using namespace std;

struct Node {
  int val;
  struct Node* nodeXor;
};

struct Node* XOR(struct Node* a, struct Node* b) {
  return (struct Node*) ((uintptr_t)(a) ^ (uintptr_t)(b));
}

void add(struct Node** head, int val) {
  struct Node *new_node = (struct Node *) malloc (sizeof (struct Node) );
  new_node -> val = val;

  new_node -> nodeXor = XOR(*head, NULL);
  if (head != NULL) {
    struct Node* next = XOR((*head) -> nodeXor, NULL);
    (*head) -> nodeXor = XOR(new_node, next);
  }
  *head = new_node;
}

struct Node* get(int index) {
  struct Node *curr = head;
  struct Node *prev = NULL;
  struct Node *next;
  while(curr != NULL && index) {
    next = XOR(curr -> npx, prev);
    prev = curr;
    curr = next;
    index--;
  }
  return curr;
}

int main(int argc, const char *argv[]) {

  return 0;
}
