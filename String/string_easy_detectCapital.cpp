#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool detectCapitalUse(string word) {
    int n = word.size();
    if (n == 1)
      return true;
    int check = 0;
    for (int i = 1; i < n; i++) {
      if (check == 0 && word[i] >= 97 && word[i] <= 122) {
        check = -1;
      } else if (check == 0 && word[i] >= 65 && word[i] <= 90) {
        check = 1;
      } else if ((check == 1 && word[i] >= 97 && word[i] <= 122) ||
                 (check == -1 && word[i] >= 65 && word[i] <= 90)) {
        return false;
      }
    }
    if (check == -1)
      return true;
    if (word[0] >= 97 && word[0] <= 122)
      return false;
    return true;
  }
};

int main() { return 0; }
