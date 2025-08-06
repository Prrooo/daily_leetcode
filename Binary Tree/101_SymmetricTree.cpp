// Given the root of a binary tree, check whether it is a mirror of itself
// (i.e., symmetric around its center).
//
// Example 1:
//
// Input: root = [1,2,2,3,4,4,3]
// Output: true
// Example 2:
//
// Input: root = [1,2,2,null,3,null,3]
// Output: false
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

bool solve(TreeNode *root1, TreeNode *root2) {
  if (root1 == NULL && root2 == NULL)
    return true;
  if (root1 == NULL || root2 == NULL)
    return false;
  return root1->val == root2->val && solve(root1->left, root2->right) &&
         solve(root1->right, root2->left);
}

bool isSymmetric(TreeNode *root) { return solve(root->left, root->right); }

int main() { return 0; }
