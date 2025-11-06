#include <bits/stdc++.h>
using namespace std;

// look for better solution

// not the best solution but different solution for sure

class Solution {
public:
  vector<int> findXSum(vector<int> &nums, int k, int x) {
    int n = nums.size();
    vector<pair<int, int>> check(51, {0, 0});
    vector<int> res;
    int i = 0, j = 0;
    while (i < n && j < n) {
      while ((j - i) < k) {
        check[nums[j]].first++;
        check[nums[j]].second = nums[j];
        j++;
      }

      vector<pair<int, int>> temp = check;

      sort(temp.begin(), temp.end(), greater<pair<int, int>>());

      int it = 0, sum = 0;
      while (it < x && it < 51) {
        sum += (temp[it].first * temp[it].second);
        it++;
      }

      res.push_back(sum);

      check[nums[i]].first--;
      i++;
    }
    return res;
  }
};

int main() { return 0; }
