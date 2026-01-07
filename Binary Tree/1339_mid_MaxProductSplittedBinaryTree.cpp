// Given the root of a binary tree, split the binary tree into two subtrees by
// removing one edge such that the product of the sums of the subtrees is
// maximized.
//
// Return the maximum product of the sums of the two subtrees. Since the answer
// may be too large, return it modulo 109 + 7.
//
// Note that you need to maximize the answer before taking the mod and not after
// taking it.
//
//
//
// Example 1:
//
// Input: root = [1,2,3,4,5,6]
// Output: 110
// Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10.
// Their product is 110 (11*10)
//
// Example 2:
//
// Input: root = [1,null,2,3,4,null,null,5,6]
// Output: 90
// Explanation: Remove the red edge and get 2 binary trees with sum 15
// and 6.Their product is 90 (15*6)

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

class Solution {
public:
  int MOD = 1e9 + 7;

  int countSum(TreeNode *root) {
    if (root == NULL)
      return 0;
    return root->val = root->val + countSum(root->left) + countSum(root->right);
  }

  void solve(TreeNode *root, int sum, long long &ans) {
    if (root == NULL)
      return;
    long long temp = 1LL * (sum - root->val) * root->val;
    ans = max(ans, temp);
    solve(root->left, sum, ans);
    solve(root->right, sum, ans);
  }

  int maxProduct(TreeNode *root) {
    long long ans = 0;
    countSum(root);
    solve(root, root->val, ans);
    return ans % MOD;
  }
};

int main() { return 0; }
