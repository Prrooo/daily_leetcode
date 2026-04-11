#include <bits/stdc++.h>
using namespace std;

// little optimized solution using hash map
// we can also use two arrays of size 26 to store the count of characters at
// even and odd indices instead of hash map time complexity: O(n) space
// complexity: O(1) since we are using hash map of size 26 at max
class Solution1 {
public:
  bool checkStrings(string s1, string s2) {
    int n = s1.size();
    unordered_map<char, int> ev_count;
    unordered_map<char, int> od_count;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        ev_count[s1[i]]++;
      } else {
        od_count[s1[i]]++;
      }
    }

    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (ev_count.find(s2[i]) == ev_count.end())
          return false;
        else {
          ev_count[s2[i]]--;
          if (ev_count[s2[i]] == 0) {
            ev_count.erase(s2[i]);
          }
        }
      } else {
        if (od_count.find(s2[i]) == od_count.end())
          return false;
        else {
          od_count[s2[i]]--;
          if (od_count[s2[i]] == 0) {
            od_count.erase(s2[i]);
          }
        }
      }
    }
    return ev_count.size() == 0 && od_count.size() == 0;
  }
};

// brute force solution

class Solution {
public:
  int next_index(string &s, char target, int index, int n) {
    for (int i = index; i < n; i += 2) {
      if (s[i] == target)
        return i;
    }
    return -1;
  }

  bool checkStrings(string s1, string s2) {
    int n = s1.size();
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        int index = next_index(s1, s2[i], i + 2, n);
        if (index != -1) {
          s1[index] = s1[i];
          s1[i] = s2[i];
        } else {
          return false;
        }
      }
    }
    return true;
  }
};

int main() { return 0; }
