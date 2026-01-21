#include <bits/stdc++.h>
using namespace std;
class Node{
public:
  int data;
  Node *next;

public:
  Node(int data1, Node *next1)
  {
    data = data1; // Initialize data with the provided value
    next = next1; // Initialize next with the provided
  }

public:
  Node(int data1)
  {
    data = data1;   // Initialize data with the provided value
    next = nullptr; // Initialize next as null since it's the end of the list
  }
};
Node* convrt_arr2LL(vector<int>&a){
  Node* head = new Node(a[0]); // head node of our LL
  Node* mover = head;    // starting mover ptr from head node ptr
  for (int i = 1; i < a.size(); i++)
  {
    Node* temp = new Node(a[i]); // creating temp. node for every a[i]..
    mover->next = temp;   // updating the mover ptr
    // implement mover_ptr for creating a LL...
    mover = temp; // OR (mover = mover->next) 
  }
  // returning the head Node of our LL...
  return head;
}
int collisionPoint(Node *t1, Node *t2, int d){
  // moving the greater LL d times...
  while (d)
  {
    d--;
    t2 = t2->next;
  }
  // traversing till we got the intersection point...
  while (t1 != t2)
  {
    t1 = t1->next;
    t2 = t2->next;
  }
  // retuning the data of the intersection point...
  return t1->data;
}
int intersection_of_point_Y_in_LL_BT(Node *head1, Node *head2){
  Node *t1 = head1;
  Node *t2 = head2;
  int N1 = 0, N2 = 0;
  while (t1 != NULL)
  {
    N1++;
    t1 = t1->next;
  }

  while (t2 != NULL)
  {
    N2++;
    t2 = t2->next;
  }

  // when N2 is greater...
  if (N1 < N2) return collisionPoint(head1, head2, N2 - N1);
  else return collisionPoint(head2, head1, N1 - N2);
}
int main(){
  // creating Nodes for LL-1...
  Node *head = new Node(3);
  Node *second1 = new Node(1);
  Node *third1 = new Node(4);
  Node *fourth1 = new Node(6);
  Node *fifth1 = new Node(2);

  // creating linking for LL-1...
  head->next = second1;
  second1->next = third1;
  third1->next = fourth1;
  fourth1->next = fifth1;

  // creating Nodes for LL-2...
  Node *head2 = new Node(1);
  Node *second2 = new Node(2);
  Node *third2 = new Node(4);
  Node *fourth2 = new Node(5);

  // creating linking for LL-1...
  head2->next = second2;
  second2->next = third2;
  third2->next = fourth2;
  fourth2->next = third1;

  cout << intersection_of_point_Y_in_LL_BT(head, head2);
  return 0;                                                                                          
}
