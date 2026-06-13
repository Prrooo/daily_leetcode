// You are given a 2D integer array descriptions where descriptions[i] =
// [parenti, childi, isLefti] indicates that parenti is the parent of childi in
// a binary tree of unique values. Furthermore,
//
//     If isLefti == 1, then childi is the left child of parenti.
//     If isLefti == 0, then childi is the right child of parenti.
//
// Construct the binary tree described by descriptions and return its root.
//
// The test cases will be generated such that the binary tree is valid.
//
//
//
// Example 1:
//
// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
// Explanation: The root node is the node with value 50 since it has no parent.
// The resulting binary tree is shown in the diagram.
//
// Example 2:
//
// Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
// Output: [1,2,null,null,3,4]
// Explanation: The root node is the node with value 1 since it has no parent.
// The resulting binary tree is shown in the diagram.
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

class Solution {
public:
  TreeNode *createBinaryTree(vector<vector<int>> &desc) {
    unordered_map<int, pair<TreeNode *, bool>> mp;
    int n = desc.size();
    for (int i = 0; i < n; i++) {
      if (mp.find(desc[i][0]) == mp.end()) {
        mp[desc[i][0]] = {NULL, false};
        mp[desc[i][0]].first = new TreeNode(desc[i][0]);
      }
      if (mp.find(desc[i][1]) == mp.end()) {
        mp[desc[i][1]] = {NULL, true};
        mp[desc[i][1]].first = new TreeNode(desc[i][1]);
      }
      if (desc[i][2] == 1) {
        mp[desc[i][1]].second = true;
        mp[desc[i][0]].first->left = mp[desc[i][1]].first;
      } else {
        mp[desc[i][1]].second = true;
        mp[desc[i][0]].first->right = mp[desc[i][1]].first;
      }
    }
    for (auto i : mp) {
      if (!i.second.second)
        return i.second.first;
    }
    return NULL;
  }
};

int main() { return 0; }
