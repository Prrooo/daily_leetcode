// In a linked list of size n, where n is even, the ith node (0-indexed) of the
// linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2)
// - 1.
//
// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the
// twin of node 2. These are the only nodes with twins for n = 4. The twin sum
// is defined as the sum of a node and its twin.
//
// Given the head of a linked list with even length, return the maximum twin sum
// of the linked list.
//
// Example 1:
//
// Input: head = [5,4,2,1]
// Output: 6
// Explanation:
// Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum
// = 6. There are no other nodes with twins in the linked list. Thus, the
// maximum twin sum of the linked list is 6. Example 2:
//
// Input: head = [4,2,2,3]
// Output: 7
// Explanation:
// The nodes with twins present in this linked list are:
// - Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
// - Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
// Thus, the maximum twin sum of the linked list is max(7, 4) = 7.
// Example 3:
//
// Input: head = [1,100000]
// Output: 100001
// Explanation:
// There is only one node with a twin in the linked list having twin sum of 1 +
// 100000 = 100001.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// best solution space complexity O(1) time complexity O(n)

ListNode *rev(ListNode *head) {
  if (head->next == NULL)
    return head;
  ListNode *pre = NULL;
  ListNode *curr = head;
  ListNode *nx = NULL;
  while (curr != NULL) {
    nx = curr->next;
    curr->next = pre;
    pre = curr;
    curr = nx;
  }
  return pre;
}

int pairSum(ListNode *head) {
  ListNode *fast = head;
  ListNode *slow = head;
  while (fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  fast = rev(slow->next);
  slow->next = NULL;
  slow = head;
  int ans = 0;
  while (fast != NULL && slow != NULL) {
    ans = max(ans, fast->val + slow->val);
    fast = fast->next;
    slow = slow->next;
  }
  return ans;
}

// not the best solution because of the space complexity can be of O(1) but it
// is O(n) now int pairSum(ListNode *head) {
//   stack<ListNode *> st;
//   ListNode *temp = head;
//   int n = 0, ans = 0;
//   while (temp != NULL) {
//     st.push(temp);
//     temp = temp->next;
//     n++;
//   }
//   temp = head;
//   for (int i = 0; i < n / 2; i++) {
//     ans = max(ans, (temp->val + st.top()->val));
//     st.pop();
//     temp = temp->next;
//   }
//   return ans;
// }

int main() { return 0; }
