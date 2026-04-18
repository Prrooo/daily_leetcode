#include <bits/stdc++.h>
#include <climits>
using namespace std;

// optimal solution
// finding the nearest left and right element using a hashmap and next and pre
// vector we loop throught -n to n for the left array and 2*n-1 to =0 for the
// pre array

class Solution {
public:
  vector<int> solveQueries(vector<int> &nums, vector<int> &queries) {
    int n = nums.size();
    vector<int> left(n), right(n);
    unordered_map<int, int> pos;
    for (int i = -n; i < n; i++) {
      if (i >= 0) {
        left[i] = pos[nums[i]];
      }
      pos[nums[(i + n) % n]] = i;
    }
    pos.clear();
    for (int i = 2 * n - 1; i >= 0; i--) {
      if (i < n) {
        right[i] = pos[nums[i]];
      }
      pos[nums[i % n]] = i;
    }
    int m = queries.size();
    for (int i = 0; i < m; i++) {
      int x = queries[i];
      queries[i] = (x - left[x] == n) ? -1 : min(x - left[x], right[x] - x);
    }
    return queries;
  }
};

// brute force solution time complexity O(n * m) where n is the size of nums and
// m is the size of queries

class Solution1 {
public:
  int solve(vector<int> &nums, int n, int start) {
    int target = nums[start];
    int i = (start + 1) % n, j = (start - 1 + n) % n, count = 1;
    for (int a = 1; a < n; a++) {
      if (nums[i] == target || nums[j] == target)
        return count;
      count++;
      i = (i + 1) % n;
      j = (j - 1 + n) % n;
    }
    return -1;
  }

  vector<int> solveQueries(vector<int> &nums, vector<int> &queries) {
    int n = nums.size(), m = queries.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) {
      ans.push_back(solve(nums, n, queries[i]));
    }
    return ans;
  }
};

int main() { return 0; }
