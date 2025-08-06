// Koko loves to eat bananas. There are n piles of bananas, the ith pile has
// piles[i] bananas. The guards have gone and will come back in h hours.
//
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she
// chooses some pile of bananas and eats k bananas from that pile. If the pile
// has less than k bananas, she eats all of them instead and will not eat any
// more bananas during this hour.
//
// Koko likes to eat slowly but still wants to finish eating all the bananas
// before the guards return.
//
// Return the minimum integer k such that she can eat all the bananas within h
// hours.
//
// Example 1:
//
// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:
//
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:
//
// Input: piles = [30,11,23,4,20], h = 6
// Output: 23
//

#include <bits/stdc++.h>
using namespace std;

// my solution
bool isValid(vector<int> &piles, int h, int mid, int n) {
  if (mid == 0)
    return false;
  long long tempHour = 0;
  for (int i = 0; i < n; i++) {
    if (piles[i] % mid == 0) {
      tempHour += piles[i] / mid;
    } else {
      tempHour += piles[i] / mid;
      tempHour++;
    }
  }
  if (tempHour > h)
    return false;
  return true;
}

int minEatingSpeed(vector<int> &piles, int h) {
  int n = piles.size();
  int maxEle = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (piles[i] > maxEle) {
      maxEle = piles[i];
    }
  }
  int left = 0, right = maxEle;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (isValid(piles, h, mid, n)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return right;
}

int main() {
  int n, h;
  cin >> n >> h;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << minEatingSpeed(arr, h);
  return 0;
}
