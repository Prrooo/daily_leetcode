// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
//  
// Example 1:
// 
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:
// 
// Input: root = [1]
// Output: [[1]]
// Example 3:
// 
// Input: root = []
// Output: []
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

vector<vector<int>> levelOrder(TreeNode *root) {
  if(root==NULL) return {};
  queue<TreeNode*> qu;
  vector<vector<int>> res;
  qu.push(root);
  while(!qu.empty()){
    int sz=qu.size();
    vector<int> temp;
    for(int i=0;i<sz;i++){
      TreeNode* top=qu.front();
      qu.pop();
      temp.push_back(top->val);
      if(top->left!=NULL) qu.push(top->left);
      if(top->right!=NULL) qu.push(top->right);
    }
    res.push_back(temp);
  }
  return res;
}

int main() { return 0; }
