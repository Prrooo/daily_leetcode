#include <bits/stdc++.h>
using namespace std;

// best solution

int countCompleteSubarrays(vector<int> &nums) {
  int k=unordered_set<int>(nums.begin(),nums.end()).size();
  unordered_map<int,int> mp;
  int left=0,ans=0,n=nums.size();
  for(int i=0;i<n;i++){
    mp[nums[i]]++;
    while(mp.size()==k){
      ans+=n-i;
      mp[nums[left]]--;
      if(mp[nums[left]]==0) mp.erase(nums[left]);
      left++;
    }
  }
  return ans;
}

// time complexity O(n*2) space complexity O(n*n) not ideal

// int countCompleteSubarrays(vector<int> &nums) {
//   set<int> st;
//   int n = nums.size();
//   for (int i = 0; i < n; i++) {
//     st.insert(nums[i]);
//   }
//   int unIndex = st.size(), count = 0;
//   for (int i = 0; i < n; i++) {
//     set<int> temp;
//     for (int j = i; j < n; j++) {
//       temp.insert(nums[j]);
//       if (temp.size() == unIndex)
//         count++;
//     }
//   }
//   return count;
// }

int main() { return 0; }
