#include <bits/stdc++.h>
using namespace std;
//
// Given the head of a linked list and a value x, partition it such that all
// nodes less than x come before nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the
// two partitions.
//
//
//
// Example 1:
//
// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]
//
// Example 2:
//
// Input: head = [2,1], x = 2
// Output: [1,2]

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *pre = NULL;
    ListNode *i = head;
    while (i != NULL) {
      if (i->val < x) {
        pre = i;
        i = i->next;
      } else {
        if (i->next != NULL && i->next->val < x) {
          ListNode *temp = i->next;
          i->next = i->next->next;
          if (pre != NULL) {
            temp->next = pre->next;
            pre->next = temp;
            pre = pre->next;
          } else {
            temp->next = head;
            pre = temp;
            head = pre;
          }
        } else {
          cout << i->val << " ";
          i = i->next;
        }
      }
    }
    return head;
  }
};

int main() { return 0; }
