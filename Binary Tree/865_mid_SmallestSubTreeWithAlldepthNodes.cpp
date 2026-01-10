// Given the root of a binary tree, the depth of each node is the shortest
// distance to the root.
//
// Return the smallest subtree such that it contains all the deepest nodes in
// the original tree.
//
// A node is called the deepest if it has the largest depth possible among any
// node in the entire tree.
//
// The subtree of a node is a tree consisting of that node, plus the set of all
// descendants of that node.
//
//
//
// Example 1:
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4]
// Output: [2,7,4]
// Explanation: We return the node with value 2, colored in yellow in the
// diagram. The nodes coloured in blue are the deepest nodes of the tree. Notice
// that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the
// smallest subtree among them, so we return it.

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
  int findDepth(TreeNode *root) {
    if (root == NULL)
      return 0;
    return 1 + max(findDepth(root->left), findDepth(root->right));
  }

  void solve(TreeNode *root, TreeNode *&ans) {
    if (root == NULL)
      return;
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);
    if (leftDepth == rightDepth) {
      ans = root;
      return;
    } else if (leftDepth > rightDepth) {
      solve(root->left, ans);
    } else {
      solve(root->right, ans);
    }
  }

  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    TreeNode *ans = root;
    solve(root, ans);
    return ans;
  }
};

int main() { return 0; }
