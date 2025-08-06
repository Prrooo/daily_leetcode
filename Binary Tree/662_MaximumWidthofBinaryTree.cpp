// Given the root of a binary tree, return the maximum width of the given tree.
//
// The maximum width of a tree is the maximum width among all levels.
//
// The width of one level is defined as the length between the end-nodes (the
// leftmost and rightmost non-null nodes), where the null nodes between the
// end-nodes that would be present in a complete binary tree extending down to
// that level are also counted into the length calculation.
//
// It is guaranteed that the answer will in the range of a 32-bit signed
// integer.
//
// Example 1:
//
// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width exists in the third level with length 4
// (5,3,null,9). Example 2:
//
//
// Input: root = [1,3,2,5,null,null,9,6,null,7]
// Output: 7
// Explanation: The maximum width exists in the fourth level with length 7
// (6,null,null,null,null,null,7). Example 3:
//
// Input: root = [1,3,2,5]
// Output: 2
// Explanation: The maximum width exists in the second level with length 2
// (3,2).

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

int widthOfBinaryTree(TreeNode *root) {
  if (root == NULL)
    return 0;
  queue<pair<TreeNode *, long long>> qu;
  qu.push({root, 0});
  int ans = 0;
  while (!qu.empty()) {
    int minIndex = qu.front().second;
    int sz = qu.size(), first = 0, last = 0;
    for (int i = 0; i < sz; i++) {
      TreeNode *temp = qu.front().first;
      long long currIndex = qu.front().second;
      qu.pop();
      if (i == 0)
        first = currIndex - minIndex;
      else if (i == sz - 1)
        last = currIndex - minIndex;
      if (temp->left != NULL) {
        qu.push({temp->left, currIndex * 2 + 1});
      }
      if (temp->right != NULL) {
        qu.push({temp->right, currIndex * 2 + 2});
      }
    }
    ans = max(ans, last - first + 1);
  }
  return ans;
}

// my solution error TLE

// int widthOfBinaryTree(TreeNode *root) {
//   if (root == NULL)
//     return 0;
//   else if (root->left == NULL || root->right == NULL)
//     return 1;
//   queue<TreeNode *> qu;
//   qu.push(root);
//   qu.push(new TreeNode(-101));
//   int ans = INT_MIN, tempCount = 0, left = -1, right = -1;
//   while (true) {
//     TreeNode *top = qu.front();
//     qu.pop();
//     if (top != NULL && top->val == -101) {
//       if (left == -1)
//         break;
//       else {
//         ans = max(ans, right - left + 1);
//       }
//       qu.push(new TreeNode(-101));
//       left = -1, right = -1, tempCount = 0;
//     } else {
//       if (left == -1 && top != NULL) {
//         left = 0;
//         right = 0;
//       } else if (left != -1 && top != NULL) {
//         right = right + tempCount + 1;
//         tempCount = 0;
//       } else {
//         tempCount++;
//       }
//       if (top == NULL) {
//         qu.push(NULL);
//         qu.push(NULL);
//       } else {
//         if (top->left != NULL)
//           qu.push(top->left);
//         else
//           qu.push(NULL);
//         if (top->right != NULL)
//           qu.push(top->right);
//         else
//           qu.push(NULL);
//       }
//     }
//   }
//   return ans;
// }

int main() { return 0; }
