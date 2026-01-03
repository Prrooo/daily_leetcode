#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<char, string> mp;
  for (int i = 0; i < n; i++) {
    char a;
    string b;
    cin >> a >> b;
    mp[a] = b;
  }

  cout << "input the element to search ";
  char search;
  cin >> search;

  cout << mp[search];

  return 0;
}
