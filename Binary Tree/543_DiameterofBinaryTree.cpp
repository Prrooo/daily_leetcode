// Given the root of a binary tree, return the length of the diameter of the
// tree.
//
// The diameter of a binary tree is the length of the longest path between any
// two nodes in a tree. This path may or may not pass through the root.
//
// The length of a path between two nodes is represented by the number of edges
// between them.
//
// Example 1:
//
// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
// Example 2:
//
// Input: root = [1,2]
// Output: 1
//

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

int solve(TreeNode *root, int &ans) {
  if (root == NULL)
    return 0;
  else if (root->left == NULL && root->right == NULL)
    return 1;
  int left = solve(root->left, ans);
  int right = solve(root->right, ans);
  ans = max(ans, left + right + 1);
  return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode *root) {
  if (root == NULL)
    return 0;
  else if (root->left == NULL && root->right == NULL)
    return 0;
  int ans = 0;
  solve(root, ans);
  return ans-1;
}

int main() { return 0; }
