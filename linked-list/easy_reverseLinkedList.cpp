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
  ListNode *reverseList(ListNode *head) {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode *pre = NULL;
    ListNode *curr = head;
    ListNode *fur = NULL;
    while (curr != NULL) {
      fur = curr->next;
      curr->next = pre;
      pre = curr;
      curr = fur;
    }
    return pre;
  }
};

int main() { return 0; }
