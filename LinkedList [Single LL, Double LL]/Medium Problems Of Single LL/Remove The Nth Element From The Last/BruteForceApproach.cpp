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
Node* remove_Nth_node_from_last_BR(Node* head,int N){
  int cnt = 0 ;
  Node* temp = head;
  while (temp!=NULL)
  {
    cnt++;
    temp = temp->next;
  }
  if(cnt==N) {
    Node* New_head = head->next;
    free(head);
    return New_head;
  }
  int res = cnt-N; 
  temp = head; 
  while (temp != NULL)
  {
    res--;
    if(res == 0) break;
    temp=temp->next;
  }
  Node* del_node = temp->next;
  temp->next = temp->next->next;
  free(del_node);
  return head;
} 
int main(){

  vector<int> a = {0,1,2,3,4,5,6};
  Node *head = convrt_arr2LL(a);

  int N;
  cout<<"Enter the value of N"<<endl;
  cin>>N;

  head = remove_Nth_node_from_last_BR(head,N);
  print(head);
  return 0;                                                                                          
}
