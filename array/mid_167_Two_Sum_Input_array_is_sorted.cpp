#include <bits/stdc++.h>
using namespace std;

// best solution with O(n) time complexity
//

vector<int> twoSum(vector<int> &numbers, int target) {
  int left = 0, right = numbers.size() - 1;
  while (left < right) {
    if ((numbers[left] + numbers[right]) == target) {
      return {left + 1, right + 1};
    } else if ((numbers[left] + numbers[right]) > target) {
      right--;
    } else
      left++;
  }
  return {};
}

// one way to solve this but take nlog(n) time no the best

int bSearch(vector<int> &numbers, int number, int left, int right, int target) {
  if (right < 0)
    return -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if ((number + numbers[mid]) == target)
      return mid;
    else if ((number + numbers[mid]) > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

vector<int> twoSum1(vector<int> &numbers, int target) {
  int right = 0, n = numbers.size();
  while (right < n) {
    int ans = bSearch(numbers, numbers[right], 0, right - 1, target);
    if (ans != -1) {
      return {ans, right};
    }
  }
  return {};
}

int main() { return 0; }
