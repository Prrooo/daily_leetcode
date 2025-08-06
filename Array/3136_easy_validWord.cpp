#include <bits/stdc++.h>
using namespace std;

bool isValid(string word) {
  int n = word.size();
  if (n < 3)
    return false;
  bool vowel = false, consonant = false;
  for (int i = 0; i < n; i++) {
    if (word[i] >= 48 && word[i] <= 57)
      continue;
    else if ((word[i] >= 65 && word[i] <= 90) ||
             (word[i] >= 97 && word[i] <= 122)) {
      if (word[i] == 'a' || word[i] == 'A' || word[i] == 'e' ||
          word[i] == 'E' || word[i] == 'i' || word[i] == 'I' ||
          word[i] == 'o' || word[i] == 'O' || word[i] == 'u' || word[i] == 'U')
        vowel = true;
      else
        consonant = true;
    } else
      return false;
  }
  if (vowel && consonant)
    return true;
  return false;
}

int main() { return 0; }
