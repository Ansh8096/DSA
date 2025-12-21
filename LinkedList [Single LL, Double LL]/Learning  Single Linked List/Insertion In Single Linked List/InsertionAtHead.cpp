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
void print(Node *head){
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
}
Node* inserting_node_at_start(Node* head,int el){
  Node* temp = new Node (el,head);
  return temp;
}
int main(){
  vector<int> a = {12,5,8,7};
  Node *head = convrt_arr2LL(a);
  int el;
  cout<<"enter the value of element :"<<endl;
  cin>>el;

  // inserting a node at starting of LL....
  head = inserting_node_at_start(head,el);
  print(head);
  
  return 0;                                                                                          
}
