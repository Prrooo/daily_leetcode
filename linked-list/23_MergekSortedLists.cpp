// You are given an array of k linked-lists lists, each linked-list is sorted in
// ascending order.
//
// Merge all the linked-lists into one sorted linked-list and return it.
//
// Example 1:
//
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:
//
// Input: lists = []
// Output: []
// Example 3:
//
// Input: lists = [[]]
// Output: []

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// brute force solution my solution

void solve(ListNode *&l1, ListNode *&l2) {
  if (l1 == NULL && l2 == NULL)
    return;
  else if (l1 == NULL && l2 != NULL) {
    l1 = l2;
    return;
  } else if (l1 != NULL && l2 == NULL) {
    return;
  }
  ListNode *t1;
  ListNode *t2;
  if (l1->val < l2->val) {
    t1 = l1;
    t2 = l2;
  } else {
    t1 = l2;
    t2 = l1;
  }
  l1 = t1;
  ListNode *temp = t1->next;
  while (temp != NULL && t2 != NULL) {
    if (temp->val < t2->val) {
      t1->next = temp;
      temp = temp->next;
    } else {
      t1->next = t2;
      t2 = t2->next;
    }
    t1 = t1->next;
  }
  t1->next = temp ? temp : t2;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
  int n = lists.size();
  if (n == 0)
    return {};
  for (int i = 1; i < n; i++) {
    solve(lists[0], lists[i]);
  }
  return lists[0];
}

int main() { return 0; }
