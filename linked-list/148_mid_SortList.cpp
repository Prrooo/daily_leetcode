#include <bits/stdc++.h>
using namespace std;

// using merge Sort

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *findMid(ListNode *root) {
    ListNode *slow = root;
    ListNode *fast = root->next;
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  ListNode *mergeSort(ListNode *left, ListNode *right) {
    ListNode *res = new ListNode(-1);
    ListNode *temp = res;
    while (left != NULL && right != NULL) {
      if (left->val < right->val) {
        temp->next = left;
        temp = temp->next;
        left = left->next;
      } else {
        temp->next = right;
        temp = temp->next;
        right = right->next;
      }
    }
    if (left != NULL)
      temp->next = left;
    else
      temp->next = right;
    return res->next;
  }

  ListNode *sortList(ListNode *head) {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode *mid = findMid(head);
    ListNode *right = mid->next;
    mid->next = NULL;
    ListNode *left = head;
    left = sortList(left);
    right = sortList(right);
    return mergeSort(left, right);
  }
};

// using prority_queue
// list time complxity O(n) but space complexity O(N)

class Solution1 {
public:
  ListNode *sortList(ListNode *head) {
    if (head == NULL)
      return head;
    priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>,
                   greater<pair<int, ListNode *>>>
        pt;
    ListNode *i = head;
    ListNode *ans = NULL;
    while (i != NULL) {
      pt.push({i->val, i});
      i = i->next;
    }
    ans = pt.top().second;
    pt.pop();
    i = ans;
    while (!pt.empty()) {
      i->next = pt.top().second;
      i = i->next;
      i->next = NULL;
      pt.pop();
    }
    return ans;
  }
};

int main() { return 0; }
