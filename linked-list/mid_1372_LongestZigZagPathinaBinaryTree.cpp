// need to revice 

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

int path = 0;

void solve(TreeNode *root, bool goLeft, int step) {
  if (root == NULL)
    return;
  path = max(path, step);
  if (goLeft) {
    solve(root->left, false, step + 1);
    solve(root->right, true, 1);
  } else {
    solve(root->right, true, step + 1);
    solve(root->left, false, 1);
  }
}

int longestZigZag(TreeNode *root) {
  solve(root, true, 0);
  return path;
}

int main() { return 0; }
