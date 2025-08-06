#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
    vector<int> keyIndex;
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] == key) {
        keyIndex.push_back(i);
      }
    }
    int m = keyIndex.size();
    cout << m;
    for (int i = 0; i < n; i++) {
      if (nums[i] == key) {
        res.push_back(i);
      } else {
        for (int j = 0; j < m; j++) {
          if (abs(i - keyIndex[j]) <= k) {
            res.push_back(i);
            break;
          }
        }
      }
    }
    return res;
  }
};

int main() { return 0; }
