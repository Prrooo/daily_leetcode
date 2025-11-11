// https://www.youtube.com/watch?v=CAvYhc74Eio
// for explaing difference array

#include <bits/stdc++.h>
using namespace std;

// best solution using binary search and difference array

class Solution {
public:
  long long maxPower(vector<int> &stations, int r, int k) {
    int n = stations.size();
    vector<long long> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      int left = max(0, i - r);
      int right = min(n, i + r + 1);
      cnt[left] += stations[i];
      cnt[right] -= stations[i];
    }

    auto check = [&](long long val) -> bool {
      vector<long long> diff = cnt;
      long long sum = 0;
      long long remaining = k;

      for (int i = 0; i < n; i++) {
        sum += diff[i];
        if (sum < val) {
          long long add = val - sum;
          if (remaining < add) {
            return false;
          }
          remaining -= add;
          int end = min(n, i + 2 * r + 1);
          diff[end] -= add;
          sum += add;
        }
      }
      return true;
    };

    long long lo = *min_element(stations.begin(), stations.end());
    long long hi = accumulate(stations.begin(), stations.end(), 0LL) + k;
    long long res = 0;
    while (lo <= hi) {
      long long mid = lo + (hi - lo) / 2;
      if (check(mid)) {
        res = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return res;
  }
};

// brute force solution
// error TLE

class Solution1 {
public:
  bool check(long long mid, vector<long long> pw, int k, int r, int n) {
    for (int i = 0; i < n; i++) {
      if (pw[i] < mid) {
        int rem = mid - pw[i];
        if (rem > k)
          return false;
        k -= rem;
        int end = min(n - 1, i + 2 * r);
        for (int j = i; j <= end; j++) {
          pw[j] += rem;
        }
      }
    }
    return true;
  }

  long long maxPower(vector<int> &stations, int r, int k) {
    int n = stations.size();
    vector<long long> pw(n, 0);
    for (int i = 0; i < n; i++) {
      int start = max(0, i - r), end = min(n - 1, i + r);
      while (start <= end) {
        pw[start] += stations[i];
        start++;
      }
    }

    auto result = minmax_element(pw.begin(), pw.end());
    long long left = ranges::min(stations);
    long long right = accumulate(stations.begin(), stations.end(), 0LL) + k;
    long long ans = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (check(mid, pw, k, r, n)) {
        ans = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return ans;
  }
};

int main() { return 0; }
