// Given head which is a reference node to a singly-linked list. The value of
// each node in the linked list is either 0 or 1. The linked list holds the
// binary representation of a number.
//
// Return the decimal value of the number in the linked list.
//
// The most significant bit is at the head of the linked list.
//
//
//
// Example 1:
//
// Input: head = [1,0,1]
// Output: 5
// Explanation: (101) in base 2 = (5) in base 10
//
// Example 2:
//
// Input: head = [0]
// Output: 0

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void solve(ListNode *head, int &pos, int &ans) {
    if (head->next == NULL) {
      pos = 0;
      if (head->val == 1)
        ans += 1;
      return;
    }
    solve(head->next, pos, ans);
    pos++;
    if (head->val == 1) {
      ans += pow(2, pos);
    }
  }

  int getDecimalValue(ListNode *head) {
    int pos = -1, ans = 0;
    solve(head, pos, ans);
    return ans;
  }
};

int main() { return 0; }
