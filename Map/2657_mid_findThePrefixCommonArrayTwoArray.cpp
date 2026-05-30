#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    int n = A.size();
    unordered_map<int, int> firstMp;
    unordered_map<int, int> secondMp;
    vector<int> res;
    for (int i = 0; i < n; i++) {
      firstMp[A[i]]++;
      secondMp[B[i]]++;
      int count = 0;
      for (auto i : firstMp) {
        if (secondMp.find(i.first) != secondMp.end()) {
          count += min(i.second, secondMp[i.first]);
        }
      }
      res.push_back(count);
    }
    return res;
  }
};

// better solution

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<int> res(n);
    vector<int> feq(n + 1, 0);
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (++feq[A[i]] == 2)
        count++;
      if (++feq[B[i]] == 2)
        count++;
      res[i] = count;
    }
    return res;
  }
};

int main() { return 0; }
