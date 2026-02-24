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

// optimal, time complexity O(n) where n is the number of nodes in the tree

class Solution {
public:
  int solve(TreeNode *root, int curr) {
    if (root == NULL)
      return 0;
    curr = curr * 2 + root->val;
    if (!root->right && !root->left)
      return curr;
    return solve(root->right, curr) + solve(root->left, curr);
  }

  int sumRootToLeaf(TreeNode *root) { return solve(root, 0); }
};

// brute force, time complexity O(n^2) where n is the number of nodes in the
// tree

class Solution1 {
public:
  void solve(TreeNode *root, int &sum, string temp) {
    if (root == NULL) {
      return;
    } else if (root->left == NULL && root->right == NULL) {
      temp += root->val + '0';
      int n = temp.size();
      for (int i = n - 1; i >= 0; i--) {
        if (temp[i] == '1') {
          sum += pow(2, n - i - 1);
        }
      }
      return;
    }
    temp += root->val + '0';
    solve(root->left, sum, temp);
    solve(root->right, sum, temp);
  }

  int sumRootToLeaf(TreeNode *root) {
    int sum = 0;
    string temp = "";
    solve(root, sum, temp);
    return sum;
  }
};

int main() { return 0; }
