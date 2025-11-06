// You are given an array of integers nums and the head of a linked list. Return
// the head of the modified linked list after removing all nodes from the linked
// list that have a value that exists in nums.
//
//
//
// Example 1:
//
// Input: nums = [1,2,3], head = [1,2,3,4,5]
//
// Output: [4,5]
//
// Explanation:
//
// Remove the nodes with values 1, 2, and 3.
//
// Example 2:
//
// Input: nums = [1], head = [1,2,1,2,1,2]
//
// Output: [2,2,2]
//
// Explanation:
//
// Remove the nodes with value 1.
//
// Example 3:
//
// Input: nums = [5], head = [1,2,3,4]
//
// Output: [1,2,3,4]
//
// Explanation:
//
// No node has value 5.
//

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
  ListNode *modifiedList(vector<int> &nums, ListNode *head) {
    unordered_set<int> st(nums.begin(), nums.end());

    while (head != NULL && st.find(head->val) != st.end()) {
      head = head->next;
    }
    if (head == NULL)
      return head;

    ListNode *i = head;

    while (i->next != NULL) {
      if (st.find(i->next->val) != st.end()) {
        ListNode *temp = i->next;
        i->next = i->next->next;
        delete temp;
      } else {
        i = i->next;
      }
    }
    return head;
  }
};

class Solution {
public:
  ListNode *solve(ListNode *root, unordered_set<int> &st) {
    if (root == NULL)
      return root;

    while (root != NULL && st.find(root->val) != st.end()) {
      root = root->next;
    }

    if (root == NULL)
      return root;

    root->next = solve(root->next, st);
    return root;
  }

  ListNode *modifiedList(vector<int> &nums, ListNode *head) {
    unordered_set<int> st;
    for (auto i : nums) {
      st.insert(i);
    }
    return solve(head, st);
  }
};

int main() { return 0; }
