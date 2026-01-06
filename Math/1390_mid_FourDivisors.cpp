#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int solve(int n) {
    int count = 1, sum = n;
    for (int i = 1; i <= n / 2; i++) {
      if (n % i == 0) {
        sum += i;
        count++;
      }
      if (count > 4)
        return 0;
    }
    return count == 4 ? sum : 0;
  }

  int sumFourDivisors(vector<int> &nums) {
    int n = nums.size(), count = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      if (mp.find(nums[i]) != mp.end()) {
        count = count + mp[nums[i]];
        continue;
      }
      int temp = solve(nums[i]);
      mp[nums[i]] = temp;
      count += temp;
    }
    return count;
  }
};

int main() { return 0; }
