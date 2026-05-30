#include <bits/stdc++.h>
using namespace std;

// one solution to solve this problem

class Solution {
public:
  void merge(vector<int> &nums, int left, int mid, int right) {
    int first = left, second = mid + 1;
    vector<int> sortedArray;
    while (first <= mid && second <= right) {
      if (nums[first] < nums[second]) {
        sortedArray.push_back(nums[first++]);
      } else {
        sortedArray.push_back(nums[second++]);
      }
    }
    while (first <= mid) {
      sortedArray.push_back(nums[first++]);
    }
    while (second <= right) {
      sortedArray.push_back(nums[second++]);
    }
    int temp = 0;
    for (int i = left; i <= right; i++) {
      nums[i] = sortedArray[temp++];
    }
  }

  void manualSort(vector<int> &nums, int left, int right) {
    if (left < right) {
      int mid = left + (right - left) / 2;
      manualSort(nums, left, mid);
      manualSort(nums, mid + 1, right);
      merge(nums, left, mid, right);
    }
  }

  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    manualSort(nums, 0, n - 1);
    return nums;
  }
};

int main() { return 0; }
