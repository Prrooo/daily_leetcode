#include <bits/stdc++.h>
using namespace std;

// optimal approach

class Solution {
public:
  vector<string> validateCoupons(vector<string> &code,
                                 vector<string> &businessLine,
                                 vector<bool> &isActive) {
    int n = code.size();
    vector<string> ans;
    vector<string> categ = {"electronics", "grocery", "pharmacy", "restaurant"};
    unordered_map<string, vector<string>> mp;
    for (int i = 0; i < n; i++) {
      if (!isActive[i])
        continue;
      if (businessLine[i] != categ[0] && businessLine[i] != categ[1] &&
          businessLine[i] != categ[2] && businessLine[i] != categ[3])
        continue;
      int f = 1;
      if (code[i].size() == 0)
        continue;
      for (int j = 0; j < code[i].size(); j++) {
        if (!((code[i][j] == '_') ||
              (code[i][j] - 'a' < 26 && code[i][j] - 'a' >= 0) ||
              (code[i][j] - 'A' < 26 && code[i][j] - 'A' >= 0) ||
              (code[i][j] - '0' <= 9 && code[i][j] - '0' >= 0))) {
          f = -1;
          break;
        }
      }
      if (f == -1)
        continue;
      mp[businessLine[i]].push_back(code[i]);
    }
    for (int i = 0; i < 4; i++) {
      auto it = mp.find(categ[i]);
      if (it == mp.end())
        continue;
      sort(it->second.begin(), it->second.end());
      for (int j = 0; j < it->second.size(); j++) {
        ans.push_back(it->second[j]);
      }
    }
    return ans;
  }
};

// my way work but not optimal code wise

class Solution1 {
public:
  bool isValid(string s) {
    int n = s.size();
    if (n == 0)
      return false;
    for (int i = 0; i < n; i++) {
      int temp = s[i] - '0';
      if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90) ||
          (temp >= 0 && temp <= 9) || s[i] == '_') {
        continue;
      } else {
        return false;
      }
    }
    return true;
  }

  vector<string> validateCoupons(vector<string> &code, vector<string> &buss,
                                 vector<bool> &isAct) {
    int n = code.size();
    vector<string> ele, gro, phar, res, ans;
    for (int i = 0; i < n; i++) {
      if (isValid(code[i]) && isAct[i] == true) {
        if (buss[i] == "electronics") {
          ele.push_back(code[i]);
        } else if (buss[i] == "grocery") {
          gro.push_back(code[i]);
        } else if (buss[i] == "pharmacy") {
          phar.push_back(code[i]);
        } else if (buss[i] == "restaurant") {
          res.push_back(code[i]);
        }
      }
    }
    sort(ele.begin(), ele.end());
    sort(gro.begin(), gro.end());
    sort(phar.begin(), phar.end());
    sort(res.begin(), res.end());
    for (int i = 0; i < ele.size(); i++) {
      ans.push_back(ele[i]);
    }
    for (int i = 0; i < gro.size(); i++) {
      ans.push_back(gro[i]);
    }
    for (int i = 0; i < phar.size(); i++) {
      ans.push_back(phar[i]);
    }
    for (int i = 0; i < res.size(); i++) {
      ans.push_back(res[i]);
    }
    return ans;
  }
};

int main() { return 0; }
