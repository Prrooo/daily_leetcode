#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int closestTarget(vector<string> &words, string target, int startIndex) {
    int n = words.size();
    int i = startIndex, j = startIndex;
    int count = 0;
    for (int a = 0; a < n; a++) {
      if (words[i] == target || words[j] == target)
        return count;
      i = (i + 1) % n;
      j = (j - 1 + n) % n;
      count++;
    }
    return -1;
  }
};

int main() { return 0; }
