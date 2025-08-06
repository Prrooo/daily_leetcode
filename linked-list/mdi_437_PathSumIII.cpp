// look for better solution not the best solution  

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

void solve(TreeNode* root,int targetSum,int &ans,int sum){
  if(root==NULL) return;
  sum+=root->val;
  if(sum==targetSum){
    ans++;
  } 
  solve(root->left,targetSum,ans,sum);
  solve(root->right,targetSum,ans,sum);
}

int pathSum(TreeNode *root, int targetSum) {
  if(root==NULL) return 0;
  int ans=0,sum=0;
  solve(root,targetSum,ans,sum);
  int left=pathSum(root->left,targetSum);
  int right=pathSum(root->right,targetSum);
  return ans+left+right;
}

int main() { return 0; }

