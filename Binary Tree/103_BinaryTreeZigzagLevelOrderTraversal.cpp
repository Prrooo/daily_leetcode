// https://www.youtube.com/watch?v=3OXWEdlIGl4

// Given the root of a binary tree, return the zigzag level order traversal of
// its nodes' values. (i.e., from left to right, then right to left for the next
// level and alternate between).
//
// Example 1:
//
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Example 2:
//
// Input: root = [1]
// Output: [[1]]
// Example 3:
//
// Input: root = []
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

// best solution

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
  if (root == NULL)
    return {};
  queue<TreeNode *> qu;
  vector<vector<int>> res;
  qu.push(root);
  bool leftToRight = true;
  while (!qu.empty()) {
    int sz = qu.size();
    vector<int> temp(sz);
    for (int i = 0; i < sz; i++) {
      TreeNode *top = qu.front();
      qu.pop();
      int index = leftToRight ? (i) : (sz - i - 1);
      temp[index] = top->val;
      if (top->left != NULL)
        qu.push(top->left);
      if (top->right != NULL)
        qu.push(top->right);
    }
    leftToRight = !leftToRight;
    res.push_back(temp);
  }
  return res;
}

// my solution work great but complex

// vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
//   if (root == NULL)
//     return {};
//   else if (root->right == NULL && root->left == NULL)
//     return {{root->val}};
//   vector<vector<int>> res;
//   deque<TreeNode *> dq;
//   bool dir = true;
//   dq.push_back(root);
//   while (!dq.empty()) {
//     int sz = dq.size();
//     vector<int> temp;
//     for (int i = dir ? 0 : sz - 1; dir ? (i < sz) : (i >= 0);
//          dir ? (i++) : (i--)) {
//       TreeNode *top = dir ? (dq.front()) : (dq.back());
//       temp.push_back(top->val);
//       (dir ? (dq.pop_front()) : (dq.pop_back()));
//       if (dir) {
//         if (top->left != NULL)
//           dq.push_back(top->left);
//         if (top->right != NULL)
//           dq.push_back(top->right);
//       } else {
//         if (top->right != NULL)
//           dq.push_front(top->right);
//         if (top->left != NULL)
//           dq.push_front(top->left);
//       }
//     }
//     res.push_back(temp);
//     dir = !dir;
//   }
//   return res;
// }

int main() { return 0; }
