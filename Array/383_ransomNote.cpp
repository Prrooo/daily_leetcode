#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
  unordered_map<char, int> mp;
  for (int i = 0; i < magazine.size(); i++) {
    mp[magazine[i]]++;
  }
  for (int i = 0; i < ransomNote.size(); i++) {
    if (mp.find(ransomNote[i]) == mp.end())
      return false;
    else {
      if (mp[ransomNote[i]] <= 0)
        return false;
    }
    mp[ransomNote[i]]--;
  }
  return true;
}

int main() { return 0; }
