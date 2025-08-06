#include <bits/stdc++.h>
using namespace std;

// vector<int> pivotArray(vector<int> &nums, int pivot) {
//   int n = nums.size();
//   int i = 0, l = 0, g = n - 1;
//   if (n == 1) {
//     return nums;
//   }
//   while (i <= g) {
//     if (nums[i] == pivot)
//       i++;
//     else if (nums[i] < pivot) {
//       int j = i;
//       while (j > l) {
//         int temp = nums[j - 1];
//         nums[j - 1] = nums[j];
//         nums[j] = temp;
//         j--;
//       }
//       i++;
//       l++;
//     } else if (nums[i] > pivot) {
//       int j = i;
//       int tp = nums[i];
//       while (j < n - 1) {
//         nums[j] = nums[j + 1];
//         j++;
//       }
//       nums[n - 1] = tp;
//       g--;
//     }
//   }
//   return nums;
// }

vector<int> pivotArray(vector<int> &nums, int pivot) {
  int n = nums.size();
  int l = 0, e = 0;
  if (n == 1) {
    return nums;
  }
  for (int i = 0; i < n; i++) {
    if (nums[i] == pivot) {
      int j=i;
      while(j>e){
        int temp=nums[j-1];
        nums[j-1]=nums[j];
        nums[j]=temp;
        j--;
      }
      e++;
    } else if (nums[i] < pivot) {
      int j = i;
      while (j > l) {
        int temp = nums[j - 1];
        nums[j - 1] = nums[j];
        nums[j] = temp;
        j--;
      }
      l++;
      e++;
    }
  }
  return nums;
}

int main() {
  int n, p;
  cin >> n >> p;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  vector<int> result = pivotArray(arr, p);
  for(auto i : result){
    cout<<i<<" ";
  }
  return 0;
}
