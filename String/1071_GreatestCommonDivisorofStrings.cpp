#include <bits/stdc++.h>
using namespace std;

// 1. How to verify if there exists any divisible string?
//
// Suppose there exists a divisible string base, we can write str1 and str2 in
// the form of multiples of base. Take the following picture as an example.
//
// img
//
// Since both strings contains multiples of the identical segment base, their
// concatenation must be consistent, regardless of the order (str1 + str2 = str2
// + str1).
//
// img
//
// Therefore, we need to check if two concatenations made by str1 and str2 in
// both orders are the same. If they are not consistent, it means there is no
// divisible strings and we should return "" as required. Otherwise, there
// exists a GCD string of str1 and str2.
//
// 2. If there are divisible strings, what is the length of the GCD string?
//
// We focus on the substring gcdBase whose length equals the greatest common
// divisor of the lengths of str1 and str2 (take the above picture as an
// example, the lengths of str1 and str2 are 9 and 6, so we focus on the
// substring of length 3, which is gcdBase = ABC). We will show that if there
// exists divisible strings, then the gcdBase must be the GCD string.

// most effective solution
// -------------------------------------------------------------------------------------------

string gcdOfStrings(string str1, string str2) {
  if (str1 + str2 != str2 + str1) {
    return "";
  }
  int gcdLen = gcd(str1.size(), str2.size());
  return str1.substr(0, gcdLen);
}

// my solution brute force solution
// ----------------------------------------------------------------------------------------------
//

string joinWords(string s, int n) {
  string result = "";
  for (int i = 0; i < n; i++) {
    result += s;
  }
  return result;
}

bool isValid(string str1, string str2, int k) {
  int n1 = str1.size(), n2 = str2.size();
  if (n1 % k > 0 || n2 % k > 0) {
    return false;
  }
  string base = str1.substr(0, k);
  int len1 = n1 / k, len2 = n2 / k;
  return joinWords(base, len1) == str1 && joinWords(base, len2) == str2;
}

string gcdOfStrings(string str1, string str2) {
  int n1 = str1.size(), n2 = str2.size();
  for (int i = min(n1, n2); i > 0; i--) {
    if (isValid(str1, str2, i)) {
      return str1.substr(0, i);
    }
  }
  return "";
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << gcdOfStrings(s1, s2);
  return 0;
}
