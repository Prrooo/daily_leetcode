// https://www.youtube.com/watch?v=_-QHfMDde90

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
// in the tree.
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor
// is defined between two nodes p and q as the lowest node in T that has both p
// and q as descendants (where we allow a node to be a descendant of itself).”
//
// Example 1:
//
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
// Example 2:
//
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
// of itself according to the LCA definition. Example 3:
//
// Input: root = [1,2], p = 1, q = 2
// Output: 1

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// best solution time complex O(n) where n is the no. of nodes in the tree

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (root == NULL || root == p || root == q)
    return root;
  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);
  if (left == NULL)
    return right;
  else if (right == NULL)
    return left;
  else {
    return root;
  }
}

// correct solution but have more time complexity

// bool check(TreeNode *root, TreeNode *target1, TreeNode *target2) {
//   if (root == NULL)
//     return false;
//   if (root == target1 || root == target2)
//     return true;
//   return check(root->right, target1, target2) ||
//          check(root->left, target1, target2);
// }
//
// void solve(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode * &ans) {
//   if (root == NULL)
//     return;
//   if (root == p) {
//     if (check(root->left, p, q) || check(root->right,p, q)) {
//       ans = root;
//       return;
//     }
//   } else if (root == q) {
//     if (check(root->left, p, q) || check(root->right, p, q)) {
//       ans = root;
//       return;
//     }
//   } else {
//     bool left=check(root->left, p,q);
//     bool right=check(root->right,p,q);
//     if(left && right){
//       ans=root;
//       return;
//     }
//     else if(left){
//       solve(root->left,p,q,ans);
//     }
//     else{
//       solve(root->right,p,q,ans);
//     }
//   }
// }
//
// TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
//   TreeNode *ans;
//   solve(root, p, q, ans);
//   return ans;
// }

int main() { return 0; }
