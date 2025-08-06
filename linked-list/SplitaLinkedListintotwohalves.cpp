// https://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/

// Given a Circular linked list. The task is split into two Circular Linked
// lists. If there are an odd number of nodes in the given circular linked list
// then out of the resulting two halved lists, the first list should have one
// node more than the second list.
//
// Examples :
//
// Input: LinkedList : 10->4->9
// Output: 10->4 , 9
//
// Explanation: After dividing linked list into 2 parts , the first part
// contains 10, 4 and second part contain only 9. Input: LinkedList :
// 10->4->9->10 Output: 10->4 , 9->10
//
// Explanation: After dividing linked list into 2 parts , the first part
// contains 10, 4 and second part contain 9, 10.

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

pair<Node *, Node *> splitList(struct Node *head) {
  struct Node *slow = head;
  struct Node *fast = head;
  while (fast->next != head && fast->next->next != head) {
    slow = slow->next;
    fast = fast->next->next;
  }
  if (fast->next != head)
    fast = fast->next;
  fast->next = slow->next;
  slow->next = head;
  return {head, fast->next};
}

int main() { return 0; }
