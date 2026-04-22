#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

// using tries
// better solution
// ahahahahahha

class TrieNode {
public:
  vector<TrieNode *> child;
  bool isEnd;
  TrieNode() {
    child = vector<TrieNode *>(26, nullptr);
    isEnd = false;
  }
};

class Solution {
public:
  TrieNode *root = new TrieNode();

  void insert(string word) {
    TrieNode *temp = root;
    for (auto i : word) {
      char idx = i - 'a';
      if (!temp->child[idx]) {
        temp->child[idx] = new TrieNode();
      }
      temp = temp->child[idx];
    }
    temp->isEnd = true;
  }

  bool dfs(string &word, TrieNode *root, int idx, int count) {
    if (count > 2)
      return false;
    if (!root)
      return false;

    if (idx == word.size())
      return root->isEnd;

    char ele = word[idx] - 'a';

    if (root->child[ele]) {
      if (dfs(word, root->child[ele], idx + 1, count))
        return true;
    }
    if (count < 2) {
      for (int i = 0; i < 26; i++) {
        if (i == ele)
          continue;
        else {
          if (dfs(word, root->child[i], idx + 1, count + 1))
            return true;
        }
      }
    }
    return false;
  }

  vector<string> twoEditWords(vector<string> &queries,
                              vector<string> &dictionary) {
    int n = queries.size();
    for (auto i : dictionary) {
      insert(i);
    }
    vector<string> ans;

    for (auto i : queries) {
      if (dfs(i, root, 0, 0)) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};

// brute force solution
// but works fine pass all test cases

class Solution1 {
public:
  bool solve(string a, string b, int n) {
    int i = 0, count = 0;
    while (i < n) {
      if (a[i] != b[i]) {
        count++;
      }
      if (count > 2)
        return false;
      i++;
    }
    return true;
  }

  vector<string> twoEditWords(vector<string> &queries,
                              vector<string> &dictionary) {
    int n = queries.size(), m = dictionary.size(), sz = queries[0].size();
    vector<string> ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (solve(queries[i], dictionary[j], sz)) {
          ans.push_back(queries[i]);
          break;
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
