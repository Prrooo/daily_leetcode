#include <bits/stdc++.h>
using namespace std;
// using vectors
string multiply(string num1, string num2) {
  if (num1 == "0" || num2 == "0")
    return "0";
  int n1 = num1.size(), n2 = num2.size();
  vector<int> ans(n1 + n2, 0);
  for (int i = n1 - 1; i >= 0; i--) {
    for (int j = n2 - 1; j >= 0; j--) {
      // we are doing i+j+1 to make sure we start from the end of the vector
      // example num1 length is 10 so last index will be on 9
      // and num2 lenght is 10 so last index will also be 9
      // but when we make the the vector of size num1.size()+num2.size() 10+10
      // its last index will be 19 which is 9+9+1 therefore we need to add 1
      ans[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
      ans[i + j] += ans[i + j + 1] / 10;
      ans[i + j + 1] %= 10;
    }
  }
  int i = 0;
  string result = "";
  while (ans[i] == 0)
    i++;
  while (i < ans.size()) {
    result += ans[i] + '0';
    i++;
  }
  return result;
}

// to fisible for large values hence not acceptable
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

/*string multiply(string num1, string num2) {*/
/*  int n1 = num1.size(), n2 = num2.size();*/
/*  int a = 0, b = 0, i = 0, j = 0;*/
/*  while (i < n1 || j < n2) {*/
/*    if (i < n1) {*/
/*      if (a == 0)*/
/*        a += num1[i]-'0';*/
/*      else {*/
/*        a = a * 10 + num1[i]-'0';*/
/*      }*/
/*      i++;*/
/*    }*/
/*    if (j < n2) {*/
/*      if (b == 0)*/
/*        b += num2[j]-'0';*/
/*      else {*/
/*        b = b * 10 + num2[j]-'0';*/
/*      }*/
/*      j++;*/
/*    }*/
/*  }*/
/*  long long mul=a*b;*/
/*  string ans="";*/
/*  if(mul==0) return "0";*/
/*  while(mul>0){*/
/*    char temp=mul%10+'0';*/
/*    ans=temp+ans; */
/*    mul/=10;*/
/*  }*/
/*  return ans;*/
/*}*/

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << multiply(s1, s2);
  return 0;
}
