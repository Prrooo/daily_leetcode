#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int val;
  Node *next;
  Node(int data) {
    int val = data;
    next = NULL;
  }
};

class MyLinkedList {
public:
  Node *head;
  MyLinkedList() { head = NULL; }
  int get(int k) {
    Node *temp = head;
    int i = 0;
    while (i < k && temp != NULL) {
      temp = temp->next;
      i++;
    }
    if (i == k)
      return temp->val;
    return -1;
  }

  void addAtHead(int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
  }

  void addAtTail(int val) {
    Node *temp = head;
    Node *newNode = new Node(val);
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  void addAtIndex(int index, int val) {
    if (index == 0) {
      addAtHead(val);
      return;
    }
    Node *temp = head;
    int i = 0;
    while (i < index && temp != NULL) {
      temp = temp->next;
      i++;
    }
    Node *newNode = new Node(val);
    newNode->next = temp->next;
  }

  void deleteAtIndex(int index) {
    int i = 0;
    Node *temp = head;
    while (i < index - 1 && temp != NULL) {
      temp = temp->next;
      i++;
    }
    temp->next = temp->next->next;
  }
};

int main() { return 0; }
