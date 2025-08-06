#include <bits/stdc++.h>
using namespace std;

// total brute force solution time complexity O(n*3);

// long long countGood(vector<int> &nums, int k) {
//   int count = 0, n = nums.size(), TotalPair = 0;
//   // unordered_map<int,int> mp;
//   for (int i = 0; i < n; i++) {
//     count = 0;
//     for (int j = i + 1; j < n; j++) {
//       for (int k = i; k < j; k++) {
//         if (nums[j] == nums[k])
//           count++;
//       }
//       if (count >= k)
//         TotalPair++;
//       // mp[nums[j]]++;
//       // if (mp[nums[j]] >1)
//       //     count++;
//     }
//     // if(count>=k) TotalPair++;
//     // mp.clear();
//   }
//   return TotalPair;
// }


int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << countGood(arr, k);
  return 0;
}
