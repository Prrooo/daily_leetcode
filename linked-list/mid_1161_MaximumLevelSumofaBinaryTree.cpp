// Given the root of a binary tree, the level of its root is 1, the level of its
// children is 2, and so on.
//
// Return the smallest level x such that the sum of all the values of nodes at
// level x is maximal.
//
// Example 1:
//
// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation:
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.
// Example 2:
//
// Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
// Output: 2
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

int maxLevelSum(TreeNode *root) {
  if (root == NULL)
    return 0;
  else if (root->left == NULL && root->right == NULL)
    return root->val;
  int ans = 0, level = 0, sum = INT_MIN, tempSum = 0;
  queue<TreeNode *> qu;
  qu.push(root);
  while (!qu.empty()) {
    level++;
    tempSum = 0;
    int n = qu.size();
    for (int i = 0; i < n; i++) {
      TreeNode *top = qu.front();
      qu.pop();
      tempSum += top->val;
      if (top->left != NULL)
        qu.push(top->left);
      if (top->right != NULL)
        qu.push(top->right);
    }
    if (tempSum > sum) {
      ans = level;
      sum = tempSum;
    }
  }
  return ans;
}

int main() { return 0; }
