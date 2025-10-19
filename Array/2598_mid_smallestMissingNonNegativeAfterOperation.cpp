#include <bits/stdc++.h>
using namespace std;

// how this work is first we make every element +ve
// store there mode value in map
// next we check if the temp can be made by the given values in mp
// be comparing the mode value of temp to the values in mp

class Solution {
public:
  int findSmallestInteger(vector<int> &nums, int value) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      // making every element +ve
      if (nums[i] < 0) {
        int val = nums[i] % value;
        nums[i] = val + value;
      }
      // storing mode value
      mp[nums[i] % value]++;
    }
    int temp = 0;
    // checking if the temp can be made or not
    while (mp[temp % value] > 0) {
      mp[temp % value]--;
      temp++;
    }
    return temp;
  }
};

int main() { return 0; }
