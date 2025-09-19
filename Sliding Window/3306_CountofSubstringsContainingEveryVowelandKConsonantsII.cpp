#include <bits/stdc++.h>
using namespace std;

int whatChar(char a) {
  if (a == 'a')
    return 0;
  else if (a == 'e')
    return 1;
  else if (a == 'i')
    return 2;
  else if (a == 'o')
    return 3;
  else if (a == 'u')
    return 4;
  return -5;
}

long long countOfSubstrings(string word, int k) {
  int count = 0;
  int i = 0, j = 0, n = word.size();
  vector<int> vCo(6, 0);
  while (i < n) {
    if (word[i] == 'a' && vCo[0] == 0) {
      vCo[0]++;
    } else if (word[i] == 'e' && vCo[1] == 0) {
      vCo[1]++;
    } else if (word[i] == 'i' && vCo[2] == 0) {
      vCo[2]++;
    } else if (word[i] == 'o' && vCo[3] == 0) {
      vCo[3]++;
    } else if (word[i] == 'u' && vCo[4] == 0) {
      vCo[4]++;
    } else if (whatChar(word[i]) == -1 && vCo[5] < k) {
      vCo[5]++;
    } else {
      count++;
      i++;
    }
  }
}

int main() {
  string s;
  int n;
  cin >> s >> n;
  cout << countOfSubstrings(s, n);
  return 0;
}
