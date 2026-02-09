// Given a binary tree, determine if it is height-balanced.
//
// Example 1:
//
// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:
//
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:
//
// Input: root = []
// Output: true

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

// best solution time complexity O(N)

class Solution1 {
public:
  bool isBalanced(TreeNode *root) { return height(root) != -1; }

  int height(TreeNode *node) {
    if (!node)
      return 0;
    int left = height(node->left);
    int right = height(node->right);
    if (left == -1 || right == -1 || abs(left - right) > 1)
      return -1;
    return max(left, right) + 1;
  }
};

int treeHeight(TreeNode *root) {
  if (root == NULL)
    return 0;
  if (root->left == NULL && root->right == NULL)
    return 1;
  return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

bool isBalanced(TreeNode *root) {
  if (root == NULL)
    return true;
  else if (root->left == NULL && root->right == NULL)
    return true;
  if (!isBalanced(root->left) || !isBalanced(root->right))
    return false;
  int left = treeHeight(root->left);
  int right = treeHeight(root->right);
  if (abs(right - left) > 1)
    return false;
  return true;
}

int main() { return 0; }
