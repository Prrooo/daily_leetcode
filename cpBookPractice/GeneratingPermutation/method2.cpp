// refere book page no 49 for details

// about next_permutation function

// It takes two iterators, first and last, defining the range [first, last) to
// be permuted. It modifies the elements in this range in-place to form the next
// lexicographically greater permutation. If such a permutation exists, the
// function returns true. If the current permutation is already the largest
// possible (i.e., the elements are in descending order), it rearranges the
// elements to the smallest possible permutation (ascending order) and returns
// false.

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;

  do {
    for (auto i : arr) {
      cout << i << " ";
    }
    cout << endl;
  } while (next_permutation(arr.begin(), arr.end()));

  return 0;
}
