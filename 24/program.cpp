#include <iostream>

struct Node {
  int val;
  Node *father, *left, *right;
  bool isLocked = false;
  int lockedDescendantsCount = 0;

  bool canLockOrUnlock() {
    if(lockedDescendantsCount) return false;

    Node *cur = father;
    while(cur != nullptr) {
      if(cur -> is_locked()) return false;
      cur = cur -> father;
    }

    return true;
  }

  bool is_locked() {
    return isLocked;
  }

  bool lock() {
    if(canLockOrUnlock()) {
      isLocked = true;

      Node *cur = father;

      while(cur != nullptr) {
        cur -> lockedDescendantsCount += 1;
        cur = cur -> father;
      }
      return true;
    } else {
      return false;
    }
  }

  bool unlock() {
    if(canLockOrUnlock()) {
      isLocked = false;

      Node *cur = father;

      while(cur != nullptr) {
        cur -> lockedDescendantsCount -= 1;
        cur = cur -> father;
      }
      return true;
    } else {
      return false;
    }
  }
};
