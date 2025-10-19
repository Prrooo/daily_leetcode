#include <bits/stdc++.h>
using namespace std;

// probable better solution exist but this is what i come up with
// and it works so fine with me

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void solve(TreeNode *root, vector<int> &inOrder) {
  if (root == NULL)
    return;
  if (!root->left && !root->right) {
    inOrder.push_back(root->val);
    return;
  }
  solve(root->left, inOrder);
  inOrder.push_back(root->val);
  solve(root->right, inOrder);
}

class BSTIterator {
public:
  vector<int> inOrder;
  int index = 0, n = 0;
  BSTIterator(TreeNode *root) {
    solve(root, inOrder);
    n = inOrder.size();
  }

  int next() { return inOrder[index++]; }

  bool hasNext() {
    if (index < n)
      return true;
    return false;
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() { return 0; }
