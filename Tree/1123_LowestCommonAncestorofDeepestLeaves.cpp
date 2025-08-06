// Given the root of a binary tree, return the lowest common ancestor of its
// deepest leaves.
//
// Recall that:
//
// The node of a binary tree is a leaf if and only if it has no children
// The depth of the root of the tree is 0. if the depth of a node is d, the
// depth of each of its children is d + 1. The lowest common ancestor of a set S
// of nodes, is the node A with the largest depth such that every node in S is
// in the subtree with root A.
//
// Example 1:
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4]
// Output: [2,7,4]
// Explanation: We return the node with value 2, colored in yellow in the
// diagram. The nodes coloured in blue are the deepest leaf-nodes of the tree.
// Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2,
// but the depth of nodes 7 and 4 is 3. Example 2:
//
// Input: root = [1]
// Output: [1]
// Explanation: The root is the deepest node in the tree, and it's the lca of
// itself. Example 3:
//
// Input: root = [0,1,3,null,2]
// Output: [2]
// Explanation: The deepest leaf node in the tree is 2, the lca of one node is
// itself.

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

int depSolve(TreeNode *root) {
  if (root == NULL)
    return 0;
  else if (root->right == NULL && root->left == NULL) {
    return 1;
  }
  int left = depSolve(root->left);
  int right = depSolve(root->right);
  return 1 + max(left, right);
}

int solve(TreeNode *root) {
  if (root == NULL)
    return 0;
  int leftDepth = depSolve(root->left);
  int rightDepth = depSolve(root->right);
  return leftDepth == rightDepth ? leftDepth : -1;
}

TreeNode *lcaDeepestLeaves(TreeNode *root) {
  if (root == NULL || (root->left == NULL && root->right == NULL))
    return root;
  queue<TreeNode *> qu;
  pair<TreeNode *, int> pt(NULL, 0);
  int level = 0;
  qu.push(root);
  qu.push(NULL);
  while (!qu.empty()) {
    TreeNode *temp = qu.front();
    qu.pop();
    if (temp == NULL && !qu.empty()) {
      level++;
      qu.push(NULL);
      continue;
    } else if (temp == NULL && qu.empty()) {
      break;
    };
    int depth = solve(temp);
    if (depth != -1 && depth + level > pt.second) {
      pt.first = temp;
      pt.second = depth + level;
    }
    if (temp->left != NULL)
      qu.push(temp->left);
    if (temp->right != NULL)
      qu.push(temp->right);
  }
  return pt.first;
}

int main() { return 0; }
