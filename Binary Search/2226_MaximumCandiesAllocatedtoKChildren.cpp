// You are given a 0-indexed integer array candies. Each element in the array
// denotes a pile of candies of size candies[i]. You can divide each pile into
// any number of sub piles, but you cannot merge two piles together.
//
// You are also given an integer k. You should allocate piles of candies to k
// children such that each child gets the same number of candies. Each child can
// be allocated candies from only one pile of candies and some piles of candies
// may go unused.
//
// Return the maximum number of candies each child can get.
//
//
//
// Example 1:
//
// Input: candies = [5,8,6], k = 3
// Output: 5
// Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and
// candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of
// sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children.
// It can be proven that each child cannot receive more than 5 candies. Example
// 2:
//
// Input: candies = [2,5], k = 11
// Output: 0
// Explanation: There are 11 children but only 7 candies in total, so it is
// impossible to ensure each child receives at least one candy. Thus, each child
// gets no candy and the answer is 0.

#include <bits/stdc++.h>
#include <climits>
using namespace std;

int maximumCandies(vector<int> &candies, long long k) {
  long long low = 1, high = *max_element(candies.begin(), candies.end());
  int result = 0;
  while (low <= high) {
    long long mid = low + (high - low) / 2;
    long long child_count = 0;
    // checking the total no. of group that can be formed using mid
    for (auto i : candies) {
      child_count += i / mid;
    }
    if (child_count >= k) {
      result = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return result;
}

int main() {
  long long k;
  int n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << maximumCandies(arr, k);
  return 0;
}
