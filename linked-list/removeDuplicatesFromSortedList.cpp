// Given the head of a sorted linked list, delete all duplicates such that each
// element appears only once. Return the linked list sorted as well.
//
//
//
// Example 1:
//
// Input: head = [1,1,2]
// Output: [1,2]
//
// Example 2:
//
// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
  int val;
  ListNode *next;
  ListNode(int data) {
    val = data;
    next = NULL;
  }
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *temp = head;
    while (temp && temp->next) {
      if (temp->val == temp->next->val) {
        temp->next = temp->next->next;
      } else {
        temp = temp->next;
      }
    }
    return head;
  }
};

int main() { return 0; }
