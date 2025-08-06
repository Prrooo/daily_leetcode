#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums) {
  int count = 0, n = nums.size();
  for (int i = 0; i < n; i++) {
    if (i + 1 < n && nums[i] > nums[i + 1]) {
      if (count >= 1)
        return false;
      count++;
    }
  }
  if (nums[0] < nums[n - 1] && count >= 1)
    return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    nums.push_back(x);
  }
  cout << check(nums);
}
