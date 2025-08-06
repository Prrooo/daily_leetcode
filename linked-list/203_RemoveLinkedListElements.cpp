// Given the head of a linked list and an integer val, remove all the nodes of
// the linked list that has Node.val == val, and return the new head.
//
//
//
// Example 1:
//
//
// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]
// Example 2:
//
// Input: head = [], val = 1
// Output: []
// Example 3:
//
// Input: head = [7,7,7,7], val = 7
// Output: []

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
  int val;
  ListNode *next;
};

ListNode *removeElements(ListNode *head, int val) {
  if (head == NULL) {
    return NULL;
  }

  while (head != NULL && head->val == val) {
    head = head->next;
  }
  ListNode *temp = head;
  while (temp != NULL && temp->next != NULL) {
    if (temp->next->val == val) {
      temp->next = temp->next->next;
    } else {
      temp = temp->next;
    }
  }
  return head;
}

int main() { return 0; }
