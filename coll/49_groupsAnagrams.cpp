// problem
// Given an array of strings strs, group the
// anagrams
// together. You can return the answer in any order.

// Example 1 :

//    Input : strs =
//                [ "eat", "tea", "tan", "ate", "nat", "bat" ]
//
//              Output : [ ["bat"], [ "nat", "tan" ], [ "ate", "eat", "tea" ] ]
//
//                       Explanation :

//    There is no string in strs that can be rearranged to form "bat".The
//    strings
// "nat" and "tan" are anagrams as they can be rearranged to form each
//               other.The strings "ate",
//      "eat",
//    and "tea" are anagrams as they can be rearranged to form each other.
//
//
//    --------------------------------------------------------------------------------------------------------------------------

// Intuition:
// The intuition is to group words that are anagrams of each other together.
// Anagrams are words that have the same characters but in a different order.

// Explanation:
// Let's go through the code step by step using the example input
// ["eat","tea","tan","ate","nat","bat"] to understand how it works.

// Initializing Variables

// We start by initializing an empty unordered map called mp (short for map),
// which will store the groups of anagrams. Grouping Anagrams We iterate through
// each word in the input vector strs. Let's take the first word, "eat", as an
// example.

// Sorting the Word
// We create a string variable called word and assign it the value of the
// current word ("eat" in this case).

// Next, we sort the characters in word using the sort() function. After
// sorting, word becomes "aet".

// Grouping the Anagram
// We insert word as the key into the mp unordered map using mp[word], and we
// push the original word ("eat") into the vector associated with that key using
// mp[word].push_back(x), where x is the current word.

// Since "aet" is a unique sorted representation of all the anagrams, it serves
// as the key in the mp map, and the associated vector holds all the anagrams.

// For the given example, the mp map would look like this after processing all
// the words:

// {
// "aet": ["eat", "tea", "ate"],
//   "ant": ["tan", "nat"],
//   "abt": ["bat"]
// }
// Creating the Result
// We initialize an empty vector called ans (short for answer) to store the
// final result.

// We iterate through each key-value pair in the mp map using a range-based for
// loop. For each pair, we push the vector of anagrams (x.second) into the ans
// vector. For the given example, the ans vector would look like this:

// [
//   ["eat", "tea", "ate"],
//  ["tan", "nat"],
//  ["bat"]
// ]
// Returning the Result
// We return the ans vector, which contains the groups of anagrams.

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
  int n1 = s.size();
  int n2 = t.size();
  if (n1 != n2)
    return false;
  int arr[26] = {0};
  for (int i = 0; i < n1; i++) {
    arr[s[i] - 'a']++;
  }
  for (int i = 0; i < n2; i++) {
    arr[t[i] - 'a']--;
  }
  for (int i = 0; i < 26; i++) {
    if (arr[i] != 0) {
      return false;
    }
  }
  return true;
}

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  unordered_map<string, vector<string>> m;
  int n = strs.size();
  for (int i = 0; i < n; i++) {
    string word = strs[i];
    sort(word.begin(), word.end());
    m[word].push_back(strs[i]);
  }
  vector<vector<string>> ans;
  for (auto i : m) {
    ans.push_back(i.second);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<string> arr;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    arr.push_back(s);
  }
  vector<vector<string>> ans = groupAnagrams(arr);
  for (auto i : ans) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}
