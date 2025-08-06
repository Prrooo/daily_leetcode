#include <bits/stdc++.h>
using namespace std;

// 2pointer solution
// time complexity O(n)
// space complexity O(1)

bool isVowel(char ch) {
  return ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' ||
         ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U';
}

string reverseVowels(string s) {
  int n = s.size();
  int left = 0, right = n - 1;
  while (left < right) {
    if (isVowel(s[left]) && isVowel(s[right])) {
      char temp = s[left];
      s[left] = s[right];
      s[right] = temp;
      left++;
      right--;
    } else if (isVowel(s[left]) && !isVowel(s[right])) {
      right--;
    } else if (!isVowel(s[left]) && isVowel(s[right])) {
      left++;
    } else {
      right--;
      left++;
    }
  }
  return s;
}

// time complexity O(n)
// space complexity O(n)

// string reverseVowels(string s) {
//   int n = s.size();
//   vector<int> arr;
//   for (int i = 0; i < n; i++) {
//     if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
//         s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
//         s[i] == 'u' || s[i] == 'U') {
//       arr.push_back(s[i]);
//     }
//   }
//   int j = arr.size() - 1;
//   for (int i = 0; i < n; i++) {
//     if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
//         s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
//         s[i] == 'u' || s[i] == 'U') {
//       s[i] = arr[j--];
//     }
//   }
//   return s;
// }

int main() {
  string s;
  cin >> s;
  cout << reverseVowels(s);
  return 0;
}
