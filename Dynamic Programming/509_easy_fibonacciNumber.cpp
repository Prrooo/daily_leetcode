#include <bits/stdc++.h>
using namespace std;

// the best solution is using only 2 variable to stor the previous two element
// which is require to calculate the next element
// therefore the timecomplexity is O(n)
// but the space compleixty drop down to only O(1)

class bestFibo {
public:
  int fibo(int n) {
    if (n <= 1)
      return n;
    int pre1 = 1, pre2 = 0, curr = 0;
    for (int i = 2; i <= n; i++) {
      curr = pre1 + pre2;
      pre2 = pre1;
      pre1 = curr;
    }
    return curr;
  }
};

// better solution then recurssion because in this we don't need recurssion
// stack therefore the time complexity is still O(n) but the space complexity
// drop down to the O(n)

class solveTabulation {
public:
  int fibo(int n) {
    if (n <= 1)
      return n;
    vector<int> dp(n + 1, -1);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};

// using recurssion
// time complexity O(n)
// space complexity O(n+n) one n is the dp and the other is the recurssion stack

class solveRecurssion {
public:
  int solve(int n, vector<int> &dp) {
    if (n <= 1)
      return n;
    if (dp[n] != -1)
      return dp[n];
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
  }

  int fibonacci(int n) {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
  }
};

int main() {
  int n;
  cin >> n;
  solveRecurssion *obj = new solveRecurssion();
  solveTabulation *tabSolve = new solveTabulation();
  cout << obj->fibonacci(n) << endl;
  cout << tabSolve->fibo(n);
  return 0;
}
