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
Node *inserting_node_at_Kth_place(Node *head, int el, int k)
{
  // when LL is empty
  if (head == NULL){
    // just add the new node and return it...
    if (k == 1)
    {
      return new Node(el);
    }
    // if k>1 then return null..
    else return nullptr;
  }
  // when LL is not empty & k = 1 then insert new node at head of LL..
  if (k == 1)
  {
    Node *temp = new Node(el, head);
    return temp;
  }

  // when k >= 2 ....
  int cnt = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    cnt++;
    if (cnt == k - 1)
    {
      Node *x = new Node(el, temp->next);
      temp->next = x;
      break;
    }
    temp = temp->next;
  }
  return head;
}
int main(){
  vector<int> a = {12,5,8,7};
  Node *head = convrt_arr2LL(a);
  int el;
  cout<<"enter the value of element :"<<endl;
  cin>>el;

  // inserting a node at kth place of LL....
  int k;
  cout << "enter the value of k:";
  cin >> k;
  head = inserting_node_at_Kth_place(head, el, k);
  print(head);

  return 0;                                                                                          
}
