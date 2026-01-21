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
void print(Node *head)
{
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
}
int intersection_of_point_Y_in_LL_BR(Node *head1, Node *head2)
{
  map<Node *, int> mpp;
  Node *temp = head1;
  // traversing the 1st LL....
  while (temp != NULL)
  {
    mpp[temp] = 1;
    temp = temp->next;
  }
  // traversing the 2nd LL....
  temp = head2;
  while (temp != NULL)
  {
    // when we find the intersection point...
    if (mpp.find(temp) != mpp.end())
    {
      return temp->data;
    }
    temp = temp->next;
  }
  // when it is not present...
  return -1;
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

  cout << intersection_of_point_Y_in_LL_BR(head, head2);
  return 0;                                                                                          
}
