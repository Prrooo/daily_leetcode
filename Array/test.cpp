#include <bits/stdc++.h>
using namespace std;

class node {
public:
  int data;
  node *left;
  node *right;
  node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

void solveTemp(node *root, vector<int> &res) {
  if (root == NULL)
    return;
  else if (root->left == NULL && root->right == NULL) {
    res.push_back(root->data);
    return;
  }
  solveTemp(root->left, res);
  res.push_back(root->data);
  solveTemp(root->right, res);
}

int solve(vector<vector<int>> &matrix, int n, vector<int> &arr, int m) {
  queue<node *> qu;
  node *root = new node(matrix[0][0]);
  int i = 0;
  qu.push(root);
  while (!qu.empty() && i < n) {
    node *temp = qu.front();
    if (temp->data == matrix[i][0]) {
      node *newNode = new node(matrix[i][1]);
      if (temp->left == NULL) {
        temp->left = newNode;
      } else {
        temp->right = newNode;
      }
      i++;
      qu.push(newNode);
    } else {
      qu.pop();
    }
  }

  vector<int> res;
  solveTemp(root, res);

  int index = res[m - 1];

  return arr[index];
}

int main() {
  vector<vector<int>> matrix = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};

  vector<int> arr = {10, 20, 30, 40, 50, 60};

  cout << solve(matrix, 6, arr, 3);
  return 0;
}
