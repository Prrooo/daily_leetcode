#include <bits/stdc++.h>
using namespace std;

string largestGoodInteger(string num) {
  int n = num.size();
  if (n <= 2)
    return "";

  vector<int> arr(10, 0);
  int i = 0;
  for (int j = 0; j < n; j++) {
    while (num[i] == num[j] && j < n) {
      j++;
    }
    if ((j - i) >= 3) {
      arr[num[i] - '0']++;
    }
    i = j;
  }
  for (int i = 9; i >= 0; i--) {
    if (arr[i] >= 1) {
      string test = "";
      test.push_back(i + '0');
      test.push_back(i + '0');
      test.push_back(i + '0');
      return test;
    }
  }
  return "";
}

int main() { return 0; }
