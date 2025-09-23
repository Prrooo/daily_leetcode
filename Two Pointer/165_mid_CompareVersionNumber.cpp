// Given two version strings, version1 and version2, compare them. A version
// string consists of revisions separated by dots '.'. The value of the revision
// is its integer conversion ignoring leading zeros.
//
// To compare version strings, compare their revision values in left-to-right
// order. If one of the version strings has fewer revisions, treat the missing
// revision values as 0.
//
// Return the following:
//
//     If version1 < version2, return -1.
//     If version1 > version2, return 1.
//     Otherwise, return 0.
//
//
//
// Example 1:
//
// Input: version1 = "1.2", version2 = "1.10"
//
// Output: -1
//
// Explanation:
//
// version1's second revision is "2" and version2's second revision is "10": 2 <
// 10, so version1 < version2.
//
// Example 2:
//
// Input: version1 = "1.01", version2 = "1.001"
//
// Output: 0
//
// Explanation:
//
// Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
//
// Example 3:
//
// Input: version1 = "1.0", version2 = "1.0.0.0"
//
// Output: 0
//
// Explanation:
//
// version1 has less revisions, which means every missing revision are treated
// as "0".
//

#include <bits/stdc++.h>
using namespace std;

// work fine

class Solution {
public:
  int compareVersion(string v1, string v2) {
    int n = v1.size(), m = v2.size();
    int i = 0, j = 0;
    while (i < n || j < m) {
      int t1 = 0, t2 = 0;
      while (i < n && v1[i] != '.') {
        if (t1 == 0 && v1[i] == '0') {
          i++;
          continue;
        }
        int temp = v1[i++] - '0';
        t1 = t1 * 10 + temp;
      }
      while (j < m && v2[j] != '.') {
        if (t2 == 0 && v2[j] == '0') {
          j++;
          continue;
        }
        int temp = v2[j++] - '0';
        t2 = t2 * 10 + temp;
      }
      if (t1 > t2)
        return 1;
      else if (t2 > t1)
        return -1;
      i++, j++;
    }
    return 0;
  }
};

int main() { return 0; }
