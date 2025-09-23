// You are given an array nums consisting of positive integers.
//
// Return the total frequencies of elements in nums such that those elements all
// have the maximum frequency.
//
// The frequency of an element is the number of occurrences of that element in
// the array.
//
//
//
// Example 1:
//
// Input: nums = [1,2,2,3,1,4]
// Output: 4
// Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum
// frequency in the array. So the number of elements in the array with maximum
// frequency is 4.
//
// Example 2:
//
// Input: nums = [1,2,3,4,5]
// Output: 5
// Explanation: All elements of the array have a frequency of 1 which is the
// maximum. So the number of elements in the array with maximum frequency is 5.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int noEle = 1, maxFre = 1, temp = 1;
    int curr = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (curr == nums[i]) {
        temp++;
      } else {
        temp = 1;
        curr = nums[i];
      }
      if (temp > maxFre) {
        noEle = 1;
        maxFre = temp;
      } else if (temp == maxFre) {
        noEle++;
      }
    }
    return maxFre * noEle;
  }
};

int main() { return 0; }
