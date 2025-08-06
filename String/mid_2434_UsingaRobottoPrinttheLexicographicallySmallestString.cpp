#include <bits/stdc++.h>
using namespace std;

string robotWithString(string s) {
  vector<int> charCount(27,0);
  int n=s.size();
  for(int i=0;i<n;i++){
    charCount[s[i]-'a']++;
  }
  string ans="";
  for(int i=0;i<27;i++){
    while(charCount[i]>0){
      ans.push_back(i+'a');
      charCount[i]--;
    }
  }
  return ans;
}

int main() { return 0; }
