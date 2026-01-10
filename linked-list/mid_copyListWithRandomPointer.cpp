#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

// best solution with O(n) space complexity
// and O(Nlog(n)) time complexity

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == NULL)
      return head;
    Node *temp = head;
    unordered_map<Node *, Node *> mp;
    while (temp) {
      mp[temp] = new Node(temp->val);
      temp = temp->next;
    }
    temp = head;
    while (temp) {
      mp[temp]->next = mp[temp->next];
      mp[temp]->random = mp[temp->random];
      temp = temp->next;
    }
    return mp[head];
  }
};

// best solution with O(1) space complexity
// and O(N^2) time complexity

class Solution1 {
public:
  Node *findRandom(Node *target, Node *newHead, Node *head) {
    if (target == head)
      return newHead;
    return findRandom(target, newHead->next, head->next);
  }

  Node *copyRandomList(Node *head) {
    if (head == NULL)
      return head;
    Node *newHead = new Node(head->val);
    Node *temp = newHead;
    Node *orgTemp = head->next;
    while (orgTemp) {
      Node *newEle = new Node(orgTemp->val);
      temp->next = newEle;
      temp = temp->next;
      orgTemp = orgTemp->next;
    }

    temp = newHead;
    orgTemp = head;
    while (temp) {
      if (orgTemp->random) {
        temp->random = findRandom(orgTemp->random, newHead, head);
      }
      temp = temp->next;
      orgTemp = orgTemp->next;
    }

    return newHead;
  }
};

int main() { return 0; }
