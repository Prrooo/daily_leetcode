// Given the root of a binary tree, imagine yourself standing on the right side
// of it, return the values of the nodes you can see ordered from top to bottom.
//
// Example 1:
//
// Input: root = [1,2,3,null,5,null,4]
//
// Output: [1,3,4]
//
// Explanation:
//
// Example 2:
//
// Input: root = [1,2,3,4,null,null,null,5]
//
// Output: [1,3,4,5]
//
// Explanation:
//
// Example 3:
//
// Input: root = [1,null,3]
//
// Output: [1,3]
//
// Example 4:
//
// Input: root = []
//
// Output: []

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

vector<int> rightSideView(TreeNode *root) {
  if (root == NULL)
    return {};
  vector<int> ans;
  queue<TreeNode *> qu;
  qu.push(root);
  while (!qu.empty()) {
    int n = qu.size();
    for (int i = 0; i < n; i++) {
      TreeNode *top = qu.front();
      qu.pop();
      if (i == n - 1)
        ans.push_back(top->val);
      if (top->left != NULL)
        qu.push(top->left);
      if (top->right != NULL)
        qu.push(top->right);
    }
  }
  return ans;
}

int main() { return 0; }
