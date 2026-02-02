#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    int n = letters.size();
    if (target >= letters[n - 1])
      return letters[0];
    char ans = 'z';
    bool check = false;
    for (int i = 0; i < n; i++) {
      if (letters[i] > target) {
        ans = min(ans, letters[i]);
      }
    }
    return ans;
  }
};

int main() { return 0; }
