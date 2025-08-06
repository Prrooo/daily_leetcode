// Given a root of Binary Tree, perform the boundary traversal of the tree.
//
// The boundary traversal is the process of visiting the boundary nodes of the
// binary tree in the anticlockwise direction, starting from the root.
//
// Examples:
// Input : root = [1, 2, 3, 4, 5, 6, 7, null, null, 8, 9]
//
// Output : [1, 2, 4, 8, 9, 6, 7, 3]
//
// Explanation :
//
// Input : root = [1, 2, null, 4, 9, 6, 5, 3, null, null, null, null, null, 7,
// 8]
//
// Output : [1, 2, 4, 6, 5, 7, 8]

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void leftTree(TreeNode *root, vector<int> &res) {
  if (root == NULL)
    return;
  else if (root->left == NULL && root->right == NULL)
    return;
  res.push_back(root->val);
  leftTree(root->left, res);
}

void bottomTree(TreeNode *root, vector<int> &res) {
  if (root == NULL)
    return;
  else if (root->left == NULL && root->right == NULL) {
    res.push_back(root->val);
    return;
  }
  bottomTree(root->left, res);
  bottomTree(root->right, res);
}

void rightTree(TreeNode *root, vector<int> &res) {
  if (root == NULL)
    return;
  if (root->right == NULL && root->left == NULL)
    return;
  rightTree(root->right, res);
  res.push_back(root->val);
}

vector<int> boundary(TreeNode *root) {
  vector<int> res;
  leftTree(root, res);
  bottomTree(root, res);
  rightTree(root, res);
  res.pop_back();
  return res;
}

int main() { return 0; }
