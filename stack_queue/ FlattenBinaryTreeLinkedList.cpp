// 114. Flatten Binary Tree to Linked List
// we just store the preOrder into the stack and them go throught the stack and
// place them in the right of the root

#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
  TreeNode *left;
  TreeNode *right;
  int val;
  TreeNode(int data) {
    val = data;
    left = NULL;
    right = NULL;
  }
};

void preOrderPush(TreeNode *root, stack<TreeNode *> &st) {
  if (root == NULL)
    return;
  st.push(root);
  preOrderPush(root->left, st);
  preOrderPush(root->right, st);
}

void flatten(TreeNode *root) {
  if (root == NULL)
    return;
  stack<TreeNode *> st;
  preOrderPush(root, st);
  TreeNode *pre = NULL;
  while (!st.empty()) {
    st.top()->right = pre;
    st.top()->left = NULL;
    pre = st.top();
    st.pop();
  }
  root->right = pre->right;
}
int main() { return 0; }
