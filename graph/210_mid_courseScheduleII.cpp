#include <bits/stdc++.h>
using namespace std;

// There are a total of numCourses courses you have to take, labeled from 0 to
// numCourses - 1. You are given an array prerequisites where prerequisites[i] =
// [ai, bi] indicates that you must take course bi first if you want to take
// course ai.
//
//     For example, the pair [0, 1], indicates that to take course 0 you have to
//     first take course 1.
//
// Return the ordering of courses you should take to finish all courses. If
// there are many valid answers, return any of them. If it is impossible to
// finish all courses, return an empty array.
//
//
//
// Example 1:
//
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you
// should have finished course 0. So the correct course order is [0,1].
//
// Example 2:
//
// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you
// should have finished both courses 1 and 2. Both courses 1 and 2 should be
// taken after you finished course 0. So one correct course order is [0,1,2,3].
// Another correct ordering is [0,2,1,3].
//
// Example 3:
//
// Input: numCourses = 1, prerequisites = []
// Output: [0]
//

class Solution {
public:
  bool solve(int no, unordered_set<int> &res, unordered_set<int> &vis,
             unordered_map<int, vector<int>> &mp, vector<int> &ans) {
    if (vis.find(no) != vis.end())
      return false;

    vis.insert(no);
    for (auto i : mp[no]) {
      if (res.find(i) == res.end() && !solve(i, res, vis, mp, ans)) {
        return false;
      }
    }

    ans.push_back(no);
    res.insert(no);
    return true;
  }

  vector<int> findOrder(int numCourses, vector<vector<int>> &prereq) {
    int n = prereq.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      mp[prereq[i][0]].push_back(prereq[i][1]);
    }

    unordered_set<int> res;
    vector<int> ans;
    unordered_set<int> vis;
    for (int i = 0; i < numCourses; i++) {
      if (mp.find(i) == mp.end()) {
        ans.push_back(i);
        res.insert(i);
      }
    }

    for (int i = 0; i < numCourses; i++) {
      if (res.find(i) == res.end()) {
        if (!solve(i, res, vis, mp, ans)) {
          return {};
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
