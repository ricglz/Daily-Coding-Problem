#include <iostream>

using namespace std;

struct Node {
  int value;
  Node* next;
};

int count(Node* list) {
  int count = 0;
  while(list != nullptr) {
    list = list -> next;
    count++;
  }
  return count;
}

Node* findIntersection(int difference, Node* list1, Node* list2) {
  while(difference--) {
    if(list1 == nullptr) return nullptr;
    list1 = list1 -> next;
  }
  while(list1 != nullptr && list2 != nullptr) {
    if(list1 == list2) return list1;
    list1 = list1 -> next;
    list2 = list2 -> next;
  }
  return nullptr;
}

Node* findDifference(Node* list1, Node* list2) {
  int count1 = count(list1),
      count2 = count(list2);
  if(count1 > count2) {
    return findIntersection(count1 -  count2, list1, list2);
  }
  return findIntersection(count1 -  count2, list2, list1);
}

int main() {
  return 0;
}
