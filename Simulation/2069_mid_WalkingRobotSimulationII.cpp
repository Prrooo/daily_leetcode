#include <bits/stdc++.h>
using namespace std;

// good solution
class Robot {
  int w, h, p;
  int curr;
  bool moved;
  std::vector<int> pos_res;

public:
  Robot(int width, int height)
      : w(width), h(height), curr(0), moved(false), pos_res(2) {
    p = (w + h - 2) << 1;
  }

  // Используем inline для исключения затрат на вызов функции
  inline void step(int num) {
    moved = true;
    curr = (curr + num) % p;
  }

  inline std::vector<int> getPos() {
    if (curr < w) {
      pos_res[0] = curr;
      pos_res[1] = 0;
    } else if (curr < w + h - 1) {
      pos_res[0] = w - 1;
      pos_res[1] = curr - w + 1;
    } else if (curr < (w << 1) + h - 2) {
      pos_res[0] = (w << 1) + h - 3 - curr;
      pos_res[1] = h - 1;
    } else {
      pos_res[0] = 0;
      pos_res[1] = p - curr;
    }
    return pos_res;
  }

  inline std::string getDir() {
    if (!moved)
      return "East";
    if (curr == 0)
      return "South";
    if (curr < w)
      return "East";
    if (curr < w + h - 1)
      return "North";
    if (curr < (w << 1) + h - 2)
      return "West";
    return "South";
  }
};

// work but not the best solution

class Robot1 {
public:
  int dir, x, y, n, m, total;
  vector<string> dirSyl = {"East", "North", "West", "South"};
  Robot1(int width, int height) {
    dir = 0, x = 0, y = 0, n = height, m = width;
    total = height * 2 + width * 2 - 4;
  }

  void step(int num) {
    if (num != 0 && num % total == 0) {
      num = total;
    } else {
      num = num % total;
    }
    while (num > 0) {
      if (dir == 0) {
        if (y + num < m) {
          y += num;
          num = 0;
        } else {
          num = num - m + y + 1;
          dir = 1;
          y = m - 1;
        }
      } else if (dir == 1) {
        if (x + num < n) {
          x += num;
          num = 0;
        } else {
          num = num - n + x + 1;
          dir = 2;
          x = n - 1;
        }
      } else if (dir == 2) {
        if (y - num >= 0) {
          y -= num;
          num = 0;
        } else {
          num = num - y;
          dir = 3;
          y = 0;
        }
      } else {
        if (x - num >= 0) {
          x -= num;
          num = 0;
        } else {
          num = num - x;
          dir = 0;
          x = 0;
        }
      }
    }
  }

  vector<int> getPos() { return {y, x}; }

  string getDir() { return dirSyl[dir]; }
};

int main() { return 0; }
