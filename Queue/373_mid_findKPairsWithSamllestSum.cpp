// You are given two integer arrays nums1 and nums2 sorted in non-decreasing
// order and an integer k.
//
// Define a pair (u, v) which consists of one element from the first array and
// one element from the second array.
//
// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
//
//
//
// Example 1:
//
// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence:
// [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
//
// Example 2:
//
// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [[1,1],[1,1]]
// Explanation: The first 2 pairs are returned from the sequence:
// [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
//

#include <bits/stdc++.h>
using namespace std;

// best solution

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &n1, vector<int> &n2, int k) {
    int n = n1.size(), m = n2.size();
    set<pair<int, int>> vis;
    vector<vector<int>> res;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pt;

    pt.push({n1[0] + n2[0], {0, 0}});

    while (k > 0 && !pt.empty()) {
      int i = pt.top().second.first, j = pt.top().second.second;
      res.push_back({n1[i], n2[j]});
      pt.pop();
      k--;
      if (i + 1 < n && vis.find({i + 1, j}) == vis.end()) {
        pt.push({n1[i + 1] + n2[j], {i + 1, j}});
        vis.insert({i + 1, j});
      }
      if (j + 1 < m && vis.find({i, j + 1}) == vis.end()) {
        vis.insert({i, j + 1});
        pt.push({n1[i] + n2[j + 1], {i, j + 1}});
      }
    }

    return res;
  }
};

int main() { return 0; }
