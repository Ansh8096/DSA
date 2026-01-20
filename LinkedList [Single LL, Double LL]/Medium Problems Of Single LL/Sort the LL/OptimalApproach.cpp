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
Node *merge_of_2_srtd_LL(Node *Nd1, Node *Nd2){
  Node *dummyNode = new Node(-1); // dummy node for starting our LL..
  Node *temp = dummyNode;         // temp to create a LL by linking...
  while (Nd1 != NULL && Nd2 != NULL)
  {
    if (Nd1->data < Nd2->data)
    {
      temp->next = Nd1;  //  creates a link..
      temp = temp->next; // moving temp ahead...
      Nd1 = Nd1->next;   // moving Nd1 ahead...
    }
    else
    {
      temp->next = Nd2;  //  creates a link..
      temp = temp->next; // moving temp ahead...
      Nd2 = Nd2->next;   // moving Nd1 ahead...
    }
  }
  // if any Node is left...
  while (Nd1 != NULL)
  {
    temp->next = Nd1;
    temp = temp->next;
    Nd1 = Nd1->next;
  }
  // if any Node is left...
  while (Nd2 != NULL)
  {
    temp->next = Nd2;
    temp = temp->next;
    Nd2 = Nd2->next;
  }
  // returning out this LL head...

  Node *new_head = dummyNode->next;
  free(dummyNode);
  return new_head;
}
Node *find_middle_for_sortLL(Node *head){
  Node *slow = head;
  Node *fast = head->next; // this will help us getting the m1 ehen n is even...
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow; // our middle
}
Node *sort_LL_OP(Node *head){
  // Edge case:
  if (head == NULL || head->next == NULL) return head;
  Node *Middle = find_middle_for_sortLL(head);
  Node *leftHead = head;
  Node *rightHead = Middle->next;
  Middle->next = nullptr;                         // creates a seperate LL...
  leftHead = sort_LL_OP(leftHead);                // updating leftHead val...
  rightHead = sort_LL_OP(rightHead);              // updating leftHead val...
  return merge_of_2_srtd_LL(leftHead, rightHead); // returning the new head after sorting...
}
int main(){
  vector<int> a = {0,7,2,9,4,5,6};
  Node *head = convrt_arr2LL(a);

  head = sort_LL_OP(head);
  print(head);
  return 0;                                                                                          
}
