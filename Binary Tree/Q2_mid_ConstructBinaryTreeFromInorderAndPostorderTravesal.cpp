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
  TreeNode *solve(vector<int> &inorder, vector<int> &postorder,
                  unordered_map<int, int> &mp, int inStart, int inEnd,
                  int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
      return NULL;
    }
    TreeNode *newNode = new TreeNode(postorder[postEnd]);
    int inorderMidIndex = mp[postorder[postEnd]];
    int leftTreeSize = inorderMidIndex - inStart;
    newNode->left = solve(inorder, postorder, mp, inStart, inorderMidIndex - 1,
                          postStart, postStart + leftTreeSize - 1);
    newNode->right = solve(inorder, postorder, mp, inorderMidIndex + 1, inEnd,
                           postStart + leftTreeSize, postEnd - 1);
    return newNode;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    unordered_map<int, int> mp;
    int n = inorder.size();
    for (int i = 0; i < n; i++) {
      mp[inorder[i]] = i;
    }
    return solve(inorder, postorder, mp, 0, n - 1, 0, n - 1);
  }
};

int main() { return 0; }
