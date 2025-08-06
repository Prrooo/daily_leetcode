// You have a long flowerbed in which some of the plots are planted, and some
// are not. However, flowers cannot be planted in adjacent plots.
//
// Given an integer array flowerbed containing 0's and 1's, where 0 means empty
// and 1 means not empty, and an integer n, return true if n new flowers can be
// planted in the flowerbed without violating the no-adjacent-flowers rule and
// false otherwise.
//
//
//
// Example 1:
//
// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: true

#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
  // 1 0 0 0 0 0 1
  int arrSize = flowerbed.size();
  if (arrSize == 1)
  {
    if (flowerbed[0] == 0 && n == 1 || n == 0)
      return true;
    else
      return false;
  }
  for (int i = 0; i < arrSize; i++)
  {
    if (n == 0)
      return true;
    if (flowerbed[i] == 1)
      continue;
    if (i - 1 >= 0 && i + 1 < arrSize && flowerbed[i - 1] != 1 &&
        flowerbed[i + 1] != 1)
    {
      n--;
      flowerbed[i] = 1;
    }
    else if (i + 1 >= arrSize && flowerbed[i - 1] != 1)
    {
      flowerbed[i] = 1;
      n--;
    }
    else if (i - 1 < 0 && flowerbed[i + 1] != 1)
    {
      flowerbed[i] = 1;
      n--;
    }
  }
  if (n != 0)
    return false;
  return true;
}

int main()
{
  int n, noPlant;
  cin >> n >> noPlant;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  cout << canPlaceFlowers(arr, noPlant);
  return 0;
}
