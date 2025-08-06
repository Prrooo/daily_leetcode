// https://www.youtube.com/watch?v=aZNaLrVebKQ

// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
//  
// Example 1:
// 
// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:
// 
// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
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

TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int preIndex,
                int inOrderStart, int inOrderEnd) {
  if (preIndex >= preorder.size() || inOrderEnd < inOrderStart)
    return NULL;
  TreeNode *root = new TreeNode(preorder[preIndex]);
  for (int i = inOrderStart; i <= inOrderEnd; i++) {
    if (inorder[i] == preorder[preIndex]) {
      int jump = i - inOrderStart + 1;
      root->left =
          jump > 0 ? solve(preorder, inorder, preIndex + 1, inOrderStart, i - 1)
                   : NULL;
      root->right =
          solve(preorder, inorder, preIndex + jump, i + 1, inOrderEnd);
    }
  }
  return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  TreeNode *root = solve(preorder, inorder, 0, 0, preorder.size() - 1);
  return root;
}

int main() { return 0; }

