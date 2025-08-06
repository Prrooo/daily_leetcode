// Given a binary tree
//
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
//
// Populate each next pointer to point to its next right node. If there is no
// next right node, the next pointer should be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
//
//
// Example 1:
//
// Input: root = [1,2,3,4,5,null,7]
// Output: [1,#,2,3,#,4,5,7,#]
// Explanation: Given the above binary tree (Figure A), your function should
// populate each next pointer to point to its next right node, just like in
// Figure B. The serialized output is in level order as connected by the next
// pointers, with '#' signifying the end of each level.
//
// Example 2:
//
// Input: root = []
// Output: []
//

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    if (root == NULL || (root->right == NULL && root->left == NULL))
      return root;

    queue<Node *> qu;
    qu.push(root);
    while (!qu.empty()) {
      int sz = qu.size();
      for (int i = 0; i < sz; i++) {
        Node *temp = qu.front();
        qu.pop();
        if (!qu.empty() && i < (sz - 1)) {
          temp->next = qu.front();
        }
        if (temp->left != NULL) {
          qu.push(temp->left);
        }
        if (temp->right != NULL) {
          qu.push(temp->right);
        }
      }
    }
    return root;
  }
};

int main() { return 0; }
