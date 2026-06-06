#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// understand this solution

class Solution2 {
public:
  ListNode *insertionSortList(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy, *cur = head;
    while (cur) {
      if ((cur->next) && (cur->next->val < cur->val)) {
        while ((pre->next) && (pre->next->val < cur->next->val)) {
          pre = pre->next;
        }
        ListNode *temp = pre->next;
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = temp;
        pre = dummy;
      } else {
        cur = cur->next;
      }
    }
    return dummy->next;
  }
};

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    stack<ListNode *> first;
    stack<ListNode *> second;
    ListNode *temp = head;
    ListNode *tempNext = NULL;
    while (temp != NULL) {
      tempNext = temp->next;
      if (first.empty()) {
        first.push(temp);
      } else {
        while (!first.empty() && first.top()->val > temp->val) {
          second.push(first.top());
          first.pop();
        }
        first.push(temp);
        while (!second.empty()) {
          first.push(second.top());
          second.pop();
        }
      }
      temp = tempNext;
    }
    ListNode *tempAns = NULL;
    while (!first.empty()) {
      first.top()->next = tempAns;
      tempAns = first.top();
      first.pop();
    }
    return tempAns;
  }
};

int main() { return 0; }
