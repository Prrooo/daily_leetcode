// You are given the head of a singly linked-list. The list can be represented
// as:
//
// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:
//
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may
// be changed.
//
//
//
// Example 1:
//
//
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
  ListNode *next;
  int data;
  ListNode(int val) {
    data = val;
    next = NULL;
  }
};

void reorderList(ListNode *head) {
  if (head == NULL || head->next == NULL)
    return;

  // Step 1: Find the middle of the list
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // Step 2: Reverse the second half of the list
  ListNode *prev = NULL;
  ListNode *curr = slow->next;
  slow->next = NULL; // Split the list into two halves
  while (curr != NULL) {
    ListNode *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  // Step 3: Merge the two halves
  ListNode *first = head;
  ListNode *second = prev;
  while (second != NULL) {
    ListNode *temp1 = first->next;
    ListNode *temp2 = second->next;
    first->next = second;
    second->next = temp1;
    first = temp1;
    second = temp2;
  }
}

int main() { return 0; }
