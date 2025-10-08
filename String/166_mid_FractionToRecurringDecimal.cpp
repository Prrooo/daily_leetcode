#include <bits/stdc++.h>
#include <string>
#include <utility>
using namespace std;

// not solve

bool solve(string res, string temp, int index, int n) {
  int i = index, j = 0;
  while (i < n && j < temp.size()) {
    if (temp[j] == res[i]) {
      i++, j++;
    } else
      return false;
  }
  return true;
}

pair<bool, string> findDublicate(string res, int i, int n) {
  string temp = "";
  bool check = false;
  temp += res[i];
  for (int j = i + 1; j < n; j++) {
    if (temp[0] == res[j]) {
      if (solve(res, temp, j, n)) {
        check = true;
        break;
      }
    } else {
      temp += res[j];
    }
  }
  return make_pair(check, temp);
}

int removeLast(string res) {
  int i = res.size() - 1;
  while (i >= 0) {
    if (res[i] == '0')
      i--;
    else
      break;
  }
  if (i == res.size() - 1)
    return -1;
  return i + 1;
}

string fractionToDecimal(int num, int den) {
  if (num % den == 0)
    return to_string(num / den);
  string ans = "", res = to_string((long double)num / den);
  int n = res.size();
  bool check = false;

  int i = 0;
  while (i < n && res[i] != '.') {
    ans += res[i];
    i++;
  }

  ans += '.';
  i++;

  pair<bool, string> temp = findDublicate(res, i, n);
  if (temp.first == true) {
    ans += '(';
    ans += temp.second;
    ans += ')';
  } else {
    ans += temp.second;
    int index = removeLast(ans);
    if (index != -1) {
      ans.erase(index, ans.size() - 1);
    }
  }

  return ans;
}

int main() {
  // fractionToDecimal(1, 2);
  return 0;
}
