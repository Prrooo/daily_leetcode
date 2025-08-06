#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int LSTtoNo(Node *head, int ans) {
  if (head == NULL)
    return -1;
  int nextData=LSTtoNo(head->next, ans);
  if(nextData==-1) return head->data;
  return ans*10 + LSTtoNo(head->next, ans);
}

Node* NoToLST(int no){
  if(no<=0) return NULL;
  Node* temp=new Node(-1);
  temp->next=NoToLST(no/10);
  temp->data=no%10;
  return temp;
}

Node *multiplyLL(Node *head1, Node *head2) {
  int m = -1,n=-1;
  m=LSTtoNo(head1, m);
  n=LSTtoNo(head2,n);
  int res=m*n;
  return NoToLST(res);
}

int main() { return 0; }
