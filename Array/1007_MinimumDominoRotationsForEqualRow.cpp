// In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom
// halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 -
// one on each half of the tile.)
//
// We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
//
// Return the minimum number of rotations so that all the values in tops are the
// same, or all the values in bottoms are the same.
//
// If it cannot be done, return -1.
//
//
//
// Example 1:
//
//
// Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
// Output: 2
// Explanation:
// The first figure represents the dominoes as given by tops and bottoms: before
// we do any rotations. If we rotate the second and fourth dominoes, we can make
// every value in the top row equal to 2, as indicated by the second figure.
// Example 2:
//
// Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
// Output: -1
// Explanation:
// In this case, it is not possible to rotate the dominoes to make one row of
// values equal.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, vector<int> &other, int topNo, int n) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] != topNo) {
      if (topNo != other[i]) {
        return -1;
      }
      ans++;
    }
  }
  return ans;
}

int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
  vector<int> topCount(7, 0);
  vector<int> bottomCount(7, 0);
  int n = tops.size(), m = bottoms.size(), topMax = INT_MIN,
      bottomMax = INT_MIN, topNo = -1, botNo = -1;
  for (int i = 0; i < n; i++) {
    topCount[tops[i]]++;
    bottomCount[bottoms[i]]++;
  }
  for (int i = 0; i < 7; i++) {
    if (topMax < topCount[i]) {
      topMax = topCount[i];
      topNo = i;
    }
    if (bottomMax < bottomCount[i]) {
      bottomMax = bottomCount[i];
      botNo = i;
    }
  }
  int check = 0;
  if (topMax > bottomMax) {
    check = solve(tops, bottoms, topNo, n);
    return check == -1 ? solve(bottoms, tops, botNo, n) : check;
  }
  check = solve(bottoms, tops, botNo, n);
  return check == -1 ? solve(tops, bottoms, topNo, n) : check;
}

int main() { return 0; }
