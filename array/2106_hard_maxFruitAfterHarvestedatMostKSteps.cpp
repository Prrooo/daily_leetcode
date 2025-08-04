//
// 🧠 # Intuition
//
// Imagine you're standing on a long straight road, and you see fruit baskets
// placed at different positions — some ahead of you and some behind.
//
// You can walk a total of at most k steps, no matter which direction you go. At
// each position you visit, you collect all the fruits there.
//
// So, the real question is:
// ➡️ What is the best set of positions to visit within k steps to collect the
// most fruits?
//
// Since the positions are already sorted, we can treat them like a number line.
// This gives us the idea of using a sliding window to explore different ranges
// of positions.
//
// We try all ranges where the minimum number of steps needed to cover them is
// within k, and track which range gives us the highest fruit total.
//
// The key trick is to calculate the steps cleverly for each window using math
// and only consider valid windows — this avoids checking unnecessary paths. 🚶
// # Approach
//
//     We use two pointers, left and right, to represent a window of fruit
//     positions we're currently looking at.
//
//     For each window, we calculate:
//         How many total fruits are inside this range (by adding them up).
//         The minimum number of steps it would take to visit all positions from
//         the starting point.
//             There are two ways:
//                 Go left first, then all the way to the right:
//                 (startPos - left) + (right - left)
//                 Go right first, then swing back to the left:
//                 (right - startPos) + (right - left)
//             We choose the cheapest option (fewer steps).
//
//     If the total steps required is more than k, it means the window is too
//     far—so we shrink it by moving the left pointer forward.
//
//     While doing this, we keep track of the maximum fruits collected across
//     all valid windows.
//
// ✅ This method is efficient because:
//
//     We only scan the array once.
//     We adjust the window size instead of checking every possible path.
//     It balances step limits and fruit collection smartly.
//
// ⏱️ # Complexity
//
//     Time Complexity: O(n)
//     We use a sliding window approach. Each fruit is added and removed from
//     the window at most once, making the entire traversal linear.
//
//     Space Complexity: O(1)
//     We only use a few variables (sum, max, left, right), and don't use any
//     extra data structures, so the space remains constant.
//
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minDist(int left, int right, int startPos) {
    return min(abs(right - startPos) + (right - left),
               abs(startPos - left) + (right - left));
  }

  int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
    int left = 0, sum = 0, ans = 0;
    for (int right = 0; right < fruits.size(); right++) {
      sum += fruits[right][1];
      while (left <= right &&
             minDist(fruits[left][0], fruits[right][0], startPos) > k) {
        sum -= fruits[left][1];
        left++;
      }
      ans = max(ans, sum);
    }
    return ans;
  }
};

int main() { return 0; }
