// You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].
//
// Implement the SmallestInfiniteSet class:
//
// SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain
// all positive integers. int popSmallest() Removes and returns the smallest
// integer contained in the infinite set. void addBack(int num) Adds a positive
// integer num back into the infinite set, if it is not already in the infinite
// set.
//
//
// Example 1:
//
// Input
// ["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest",
// "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
// [[], [2], [], [], [], [1], [], [], []]
// Output
// [null, null, 1, 2, 3, null, 1, 4, 5]
//
// Explanation
// SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
// smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change
// is made. smallestInfiniteSet.popSmallest(); // return 1, since 1 is the
// smallest number, and remove it from the set.
// smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
// smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
// smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
// smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the
// set and
//                                    // is the smallest number, and remove it
//                                    from the set.
// smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
// smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.
//

#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
public:
  int top;
  set<int> st;
  SmallestInfiniteSet() { top = 1; }

  int popSmallest() {
    int toRe;
    if (st.empty()) {
      toRe = top;
      top++;
    } else if (!st.empty() && *st.rbegin() > top) {
      toRe = top;
      top++;
    } else {
      toRe = *st.begin();
      st.erase(toRe);
    }
    return toRe;
  }

  void addBack(int num) {
    if (num >= top || st.find(num) != st.end()) {
      return;
    }
    st.insert(num);
  }
};

int main() { return 0; }
