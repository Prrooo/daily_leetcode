// Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen
// numbers sum to target. You may return the combinations in any order.
//
// The same number may be chosen from candidates an unlimited number of times.
// Two combinations are unique if the frequency of at least one of the chosen
// numbers is different.
//
// The test cases are generated such that the number of unique combinations that
// sum up to target is less than 150 combinations for the given input.
//
//
//
// Example 1:
//
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
// times. 7 is a candidate, and 7 = 7. These are the only two combinations.
// Example 2:
//
// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:
//
// Input: candidates = [2], target = 1
// Output: []
//
// Constraints:

#include <bits/stdc++.h>
using namespace std;

// best solution

void solve(vector<int> &cand, set<vector<int>> &ans, vector<vector<int>> &res,
           vector<int> temp, int target, int n) {
  if (n >= cand.size() || target < 0)
    return;
  if (target == 0) {
    if (ans.find(temp) == ans.end()) {
      res.push_back(temp);
      ans.insert(temp);
    }
    return;
  }
  temp.push_back(cand[n]);
  solve(cand, ans, res, temp, target - cand[n], n + 1);
  solve(cand, ans, res, temp, target - cand[n], n);
  temp.pop_back();
  solve(cand, ans, res, temp, target, n + 1);
}

vector<vector<int>> combinationSum(vector<int> &cand, int target) {
  set<vector<int>> ans;
  vector<vector<int>> res;
  solve(cand, ans, res, {}, target, 0);
  return res;
}

// not best solution

// void solve(vector<int> &cand, set<vector<int>> &ans, vector<int> temp,
//            int target, int sum, int n) {
//   for (int i = 0; i < n; i++) {
//     if (sum + cand[i] == target) {
//       temp.push_back(cand[i]);
//       vector<int> temp2 = temp;
//       sort(temp2.begin(), temp2.end());
//       ans.insert(temp2);
//       temp.pop_back();
//     } else if (sum + cand[i] < target) {
//       temp.push_back(cand[i]);
//       solve(cand, ans, temp, target, sum + cand[i], n);
//       temp.pop_back();
//     }
//   }
// }
//
// vector<vector<int>> combinationSum(vector<int> &cand, int target) {
//   set<vector<int>> ans;
//   solve(cand, ans, {}, target, 0, cand.size());
//   vector<vector<int>> res;
//   for (auto i : ans) {
//     res.push_back(i);
//   }
//   return res;
// }

int main() { return 0; }
