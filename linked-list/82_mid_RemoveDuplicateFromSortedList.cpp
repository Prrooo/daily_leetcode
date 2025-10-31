#include <bits/stdc++.h>
using namespace std;
//
// Topics
// premium lock iconCompanies
//
// Given the head of a sorted linked list, delete all nodes that have duplicate
// numbers, leaving only distinct numbers from the original list. Return the
// linked list sorted as well.
//
//
//
// Example 1:
//
// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
//
// Example 2:
//
// Input: head = [1,1,1,2,3]
// Output: [2,3]

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *root) {
    if (root == NULL || root->next == NULL)
      return root;

    if (root->val == root->next->val) {
      while (root->next != NULL && root->val == root->next->val) {
        root = root->next;
      }
      return deleteDuplicates(root->next);
    }
    root->next = deleteDuplicates(root->next);
    return root;
  }
};

int main() { return 0; }
