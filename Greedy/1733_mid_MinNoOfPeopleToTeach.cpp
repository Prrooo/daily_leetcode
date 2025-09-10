#include <bits/stdc++.h>
using namespace std;

// best soluiton
// in this we maintain the list of sad user who can't talk to there friends and
// the teach the most speak language in the saduser to the other

class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>> &languages,
                       vector<vector<int>> &friendships) {
    unordered_set<int> sadUsers;

    for (auto &friends : friendships) {
      int u = friends[0] - 1;
      int v = friends[1] - 1;

      unordered_set<int> langSet(begin(languages[u]), end(languages[u]));
      bool canTalk = false;
      for (int lang : languages[v]) {
        if (langSet.count(lang)) {
          canTalk = true;
          break;
        }
      }

      if (!canTalk) {
        sadUsers.insert(u);
        sadUsers.insert(v);
      }
    }

    vector<int> language(n + 1, 0);
    int mostKnownLang = 0;

    for (int user : sadUsers) {
      for (int lang : languages[user]) {
        language[lang]++;
        mostKnownLang = max(mostKnownLang, language[lang]);
      }
    }

    return sadUsers.size() - mostKnownLang;
  }
};

// this is the solution that i comeup with but it contain some problem that i
// don't know which language to add and in which person should learn the new
// language

class Solution2 {
public:
  int minimumTeachings(int n, vector<vector<int>> &languages,
                       vector<vector<int>> &friendships) {
    int ans = 0;
    for (auto i : friendships) {
      vector<int> temp1(languages[i[0] - 1].begin(), languages[i[0] - 1].end()),
          temp2(languages[i[1] - 1].begin(), languages[i[1] - 1].end());
      sort(temp1.begin(), temp1.end());
      sort(temp2.begin(), temp2.end());
      int a = 0, b = 0, tz1 = temp1.size(), tz2 = temp2.size();
      bool valid = false;
      while (a < tz1 && b < tz2) {
        if (temp1[a] == temp2[b]) {
          valid = true;
          break;
        } else if (temp1[a] < temp2[b]) {
          a++;
        } else
          b++;
      }
      if (!valid) {
        ans++;
        languages[i[0] - 1].push_back(temp2[0]);
      }
    }
    return ans;
  }
};

int main() { return 0; }
