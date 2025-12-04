#include <bits/stdc++.h>
using namespace std;

// There are n cars on an infinitely long road. The cars are numbered from 0 to
// n - 1 from left to right and each car is present at a unique point.
//
// You are given a 0-indexed string directions of length n. directions[i] can be
// either 'L', 'R', or 'S' denoting whether the ith car is moving towards the
// left, towards the right, or staying at its current point respectively. Each
// moving car has the same speed.
//
// The number of collisions can be calculated as follows:
//
//     When two cars moving in opposite directions collide with each other, the
//     number of collisions increases by 2. When a moving car collides with a
//     stationary car, the number of collisions increases by 1.
//
// After a collision, the cars involved can no longer move and will stay at the
// point where they collided. Other than that, cars cannot change their state or
// direction of motion.
//
// Return the total number of collisions that will happen on the road.
//
//
//
// Example 1:
//
// Input: directions = "RLRSLL"
// Output: 5
// Explanation:
// The collisions that will happen on the road are:
// - Cars 0 and 1 will collide with each other. Since they are moving in
// opposite directions, the number of collisions becomes 0 + 2 = 2.
// - Cars 2 and 3 will collide with each other. Since car 3 is stationary, the
// number of collisions becomes 2 + 1 = 3.
// - Cars 3 and 4 will collide with each other. Since car 3 is stationary, the
// number of collisions becomes 3 + 1 = 4.
// - Cars 4 and 5 will collide with each other. After car 4 collides with car 3,
// it will stay at the point of collision and get hit by car 5. The number of
// collisions becomes 4 + 1 = 5. Thus, the total number of collisions that will
// happen on the road is 5.

class Solution {
public:
  int countCollisions(string d) {
    int ans = 0, count = 1;
    char dir = d[0];
    for (int i = 1; i < d.size(); i++) {
      char curr = d[i];
      bool check = false;
      if (dir == 'R') {
        if (curr == 'L') {
          ans += 2;
          ans = ans + count - 1;
          check = true;
        } else if (curr == 'S') {
          ans += count;
          check = true;
        }
      } else if (dir == 'S') {
        if (curr == 'L') {
          ans += count;
          check = true;
        }
      }
      if (dir == curr && curr != 'S')
        count++;
      else
        count = 1;
      if (check)
        dir = 'S';
      else
        dir = curr;
    }
    return ans;
  }
};

int main() { return 0; }
