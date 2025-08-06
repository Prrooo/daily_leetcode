#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
  int size;
  deque<int> qu;
  unordered_map<int,int> mp;
  void putFirst(int key){
    stack<int> st;
    int first;
    while(!qu.empty()){
      if(qu.front()!=key){
        st.push(qu.front());
        qu.pop_front();
      }
      else{
        break;
      }
    }
    first=qu.front();
    qu.pop_front();
    while(!st.empty()){
      qu.push_back(st.top());
      st.pop();
    }
    qu.push_back(first);
  }

  LRUCache(int capacity) {
    size=capacity;
  }

  int get(int key) {
    if(mp.find(key)!=mp.end()){
      putFirst(key);
      return mp[key];
    }
    return -1;
  }

  void put(int key, int value) {
    if(mp.size()>=size){
      mp.erase(qu.front());
    }
    mp[key]=value;
    qu.push_back(key);
  }
};

int main() { return 0; }
