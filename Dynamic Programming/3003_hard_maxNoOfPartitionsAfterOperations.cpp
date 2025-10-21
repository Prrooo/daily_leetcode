#include <bits/stdc++.h>
using namespace std;

// best solution

#define ll long long

class Solution {
  // Memoization cache: maps a compressed state (index, currentSet, canChange)
  // → result
  unordered_map<ll, int> cache;

  string s; // The input string
  int k;    // Maximum allowed distinct characters in a partition

  // Recursive helper function
  int findMaxPartitions(ll index, ll currentSet, bool canChange) {
    // Compress the state into a single key for memoization
    // - index is shifted left to make room for currentSet and canChange
    // bits
    ll key = (index << 27) | (currentSet << 1) | canChange;

    // If already computed, return the cached result
    if (cache.count(key)) {
      return cache[key];
    }

    // Base Case: if we’ve processed all characters, no more partitions to
    // make
    if (index == s.size()) {
      return 0;
    }

    // Get current character’s index (0 for 'a', 1 for 'b', …)
    int characterIndex = s[index] - 'a';

    // Add this character to the current character set (bitmask
    // representation)
    int currentSetUpdated = currentSet | (1 << characterIndex);

    // Count distinct characters in the current set
    int distinctCount = __builtin_popcount(currentSetUpdated);

    int res;

    // Case 1: If adding this character exceeds the allowed distinct limit
    // `k` → Start a new partition from this character
    if (distinctCount > k) {
      res = 1 + findMaxPartitions(index + 1, 1 << characterIndex, canChange);
    }
    // Case 2: Continue with the current partition
    else {
      res = findMaxPartitions(index + 1, currentSetUpdated, canChange);
    }

    // Case 3: If we still have the option to change one character
    // (canChange = true)
    if (canChange) {
      // Try changing the current character to any of the 26 possible
      // letters
      for (int newCharIndex = 0; newCharIndex < 26; newCharIndex++) {
        // Add this hypothetical character to the current set
        int newSet = currentSet | (1 << newCharIndex);
        int newDistinctCount = __builtin_popcount(newSet);

        // If the new character causes distinct count > k
        // → We must start a new partition
        if (newDistinctCount > k) {
          res = max(res,
                    1 + findMaxPartitions(index + 1, 1 << newCharIndex, false));
        }
        // Otherwise, continue within the same partition
        else {
          res = max(res, findMaxPartitions(index + 1, newSet, false));
        }
      }
    }

    // Store and return the result for this state
    return cache[key] = res;
  }

public:
  int maxPartitionsAfterOperations(string s, int k) {
    this->s = s;
    this->k = k;
    // Start recursion from index 0, empty set, and with change allowed
    // (true) +1 because the number of partitions = number of splits + 1
    return findMaxPartitions(0, 0, true) + 1;
  }
};

int main() { return 0; }
