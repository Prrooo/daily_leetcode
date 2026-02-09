//
// Given the root of a binary search tree, return a balanced binary search tree
// with the same node values. If there is more than one answer, return any of
// them.
//
// A binary search tree is balanced if the depth of the two subtrees of every
// node never differs by more than 1.
//
//
//
// Example 1:
//
// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also
// correct.
//
// Example 2:
//
// Input: root = [2,1,3]
// Output: [2,1,3]

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
  TreeNode *solve(int start, int end, vector<TreeNode *> &nums) {
    if (start <= end) {
      int mid = start + (end - start) / 2;
      TreeNode *center = nums[mid];
      center->left = solve(start, mid - 1, nums);
      center->right = solve(mid + 1, end, nums);
      return center;
    }
    return NULL;
  }

  int is_balanced(TreeNode *root, vector<TreeNode *> &nums) {
    if (root == NULL)
      return 0;
    int left = is_balanced(root->left, nums);
    nums.push_back(root);
    int right = is_balanced(root->right, nums);
    if (left == -1 || right == -1 || abs(right - left) > 1) {
      return -1;
    }
    return 1 + max(left, right);
  }

  TreeNode *balanceBST(TreeNode *root) {
    vector<TreeNode *> nums;
    if (is_balanced(root, nums) != -1)
      return root;
    int n = nums.size();
    return solve(0, n - 1, nums);
  }
};

int main() { return 0; }
