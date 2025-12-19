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
Node *delete_the_node_by_value(Node *head, int val){
  if (head == nullptr) return head;
  // when the k = 1 , we just need to delete the head of the LL
  if (head->data == val){
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  Node *temp = head;
  Node *prev = nullptr; // it will store the prev node of temp.
  while (temp != nullptr){
    if (temp->data == val){ // means this is our kth node...
      prev->next = prev->next->next;
      delete temp;
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}
int main(){
  vector<int> a = {1,2,6,6,3};
  Node* head = convrt_arr2LL(a);
  
  // deletion node of LL by val...
  int val;
  cout<<"rnter the value of val:";
  cin>>val;
  head = delete_the_node_by_value(head,val);
  print(head);

  return 0;                                                                                          
}
