#include <bits/stdc++.h>
using namespace std;

long long numberOfPowerfulInt(long long start, long long finish, int limit,
                              string s) {
  if(finish<limit) return 0;
  return 0;
}

int main() {
  long long start,finish;
  int limit;
  string s;
  cin>>start>>finish>>limit>>s;
  cout<<numberOfPowerfulInt(start, finish, limit, s);
  return 0;
}
