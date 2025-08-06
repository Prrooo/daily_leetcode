// we have to print the character in the string with the count of it in the
// string approach we store the count in the arr[26] and then print the char and
// there count and skip until we get different character

#include <bits/stdc++.h>
using namespace std;

void printCharCount(string s) {
  int n = s.size();
  int arr[26] = {0};
  for (int i = 0; i < n; i++) {
    arr[s[i] - 'a']++;
  }
  for (int i = 0; i < n; i++) {
    cout << s[i] << arr[s[i] - 'a'];
    while (i + 1 < n && s[i] == s[i + 1]) {
      i++;
    }
  }
}

int main() {
  string s;
  cin >> s;
  printCharCount(s);
  return 0;
}
