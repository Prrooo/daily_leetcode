// Given a root node reference of a BST and a key, delete the node with the
// given key in the BST. Return the root node reference (possibly updated) of
// the BST.
//
// Basically, the deletion can be divided into two stages:
//
// Search for a node to remove.
// If the node is found, delete the node.
//
// Example 1:
//
// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
// Explanation: Given key to delete is 3. So we find the node with value 3 and
// delete it. One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
// Please notice that another valid answer is [5,2,6,null,4,null,7] and it's
// also accepted.
//
// Example 2:
//
// Input: root = [5,3,6,2,4,null,7], key = 0
// Output: [5,3,6,2,4,null,7]
// Explanation: The tree does not contain a node with value = 0.
// Example 3:
//
// Input: root = [], key = 0
// Output: []

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
// --------------------------------------------------------------------------------------------

TreeNode *findMin(TreeNode *node) {
  while (node && node->left)
    node = node->left;
  return node;
}

TreeNode *deleteNode(TreeNode *root, int key) {
  if (!root)
    return nullptr;

  if (key < root->val) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->val) {
    root->right = deleteNode(root->right, key);
  } else {
    // Node found
    if (!root->left) {
      TreeNode *temp = root->right;
      delete root;
      return temp;
    } else if (!root->right) {
      TreeNode *temp = root->left;
      delete root;
      return temp;
    }

    // Node with two children
    TreeNode *minNode = findMin(root->right);
    root->val = minNode->val;
    root->right = deleteNode(root->right, minNode->val);
  }

  return root;
}


// not the best solution

// void solve(TreeNode *&root, TreeNode *preNode, int key) {
//   if (root == NULL)
//     return;
//   else if (root->val == key) {
//     if (root->left == NULL && root->right == NULL) {
//       if (preNode == root) {
//         root = NULL;
//         preNode = NULL;
//       } else if (preNode->left == root) {
//         preNode->left = NULL;
//       } else {
//         preNode->right = NULL;
//       }
//     } else if (root->left == NULL && root->right != NULL) {
//       if (preNode == root) {
//         root = root->right;
//       } else if (preNode->left == root) {
//         preNode->left = root->right;
//       } else {
//         preNode->right = root->right;
//       }
//     } else if (root->left != NULL && root->right == NULL) {
//       if (preNode == root) {
//         root = root->left;
//       } else if (preNode->left == root) {
//         preNode->left = root->left;
//       } else {
//         preNode->right = root->left;
//       }
//     } else {
//       TreeNode *temp = root->right;
//       while (temp->left != NULL) {
//         temp = temp->left;
//       }
//       temp->left = root->left;
//       if (preNode == root) {
//         root = root->right;
//       } else if (preNode->left == root) {
//         preNode->left = root->right;
//       } else {
//         preNode->right = root->right;
//       }
//     }
//     return;
//   }
//   preNode = root;
//   solve(root->left, preNode, key);
//   solve(root->right, preNode, key);
// }
//
// TreeNode *deleteNode(TreeNode *root, int key) {
//   if (root == NULL) {
//     return NULL;
//   }
//   TreeNode *preNode = root;
//   solve(root, preNode, key);
//   return root;
// }

int main() { return 0; }
