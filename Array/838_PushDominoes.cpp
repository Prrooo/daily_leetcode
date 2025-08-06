#include <bits/stdc++.h>
using namespace std;

string pushDominoes(string doi) {
  int n = doi.size();
  int left = 0, right = 0;
  while (left < n) {
    right = left + 1;
    while (right < n && doi[right] == '.') {
      right++;
    }
    if (doi[left] == '.' && doi[right] == 'L') {
      while (left < right) {
        doi[left] = doi[right];
        left++;
      }
    } else if (doi[left] == doi[right]) {
      while (left < right) {
        doi[left] = doi[right];
        left++;
      }
    } else if (doi[left] == 'R' && right >= n) {
      left++;
      while (left < right) {
        doi[left] = doi[left - 1];
        left++;
      }
    } else if (doi[left] == 'R' && doi[right] == 'L') {
      int temp = right;
      left++, right--;
      while (left < right) {
        doi[left] = doi[left - 1];
        doi[right] = doi[right + 1];
        left++, right--;
      }
      left = right = temp;
    }
    left = right;
  }
  return doi;
}

int main() {
  string doi;
  cin >> doi;
  cout << pushDominoes(doi);
  return 0;
}
