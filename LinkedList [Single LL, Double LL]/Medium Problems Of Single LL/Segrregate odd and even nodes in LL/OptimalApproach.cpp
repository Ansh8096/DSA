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
Node *Seggarate_odd_and_even_OP(Node *head)
{
  if (head == NULL || head->next == NULL) return head;
  // creating Heads of Odd and Even LinkedLists
  Node *odd = head;
  Node *even = head->next;
  Node *even_head = head->next;
  while (even != NULL && even->next != NULL)
  {
    // creating links of all the odd nodes together and even nodes together..
    odd->next = odd->next->next;
    even->next = even->next->next;

    // this is for traversal
    odd = odd->next;   // moving odd to the next odd
    even = even->next; // moving even to the next even
  }
  odd->next = even_head; // linking last odd note to the even head (to get our answer)
  return head;
}
int main(){

  vector<int> a = {0,1,2,0,0,1,0,2};
  Node *head = convrt_arr2LL(a);
  head = Seggarate_odd_and_even_OP(head);
  print(head);

  return 0;                                                                                          
}
