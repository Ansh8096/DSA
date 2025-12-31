#include <bits/stdc++.h>
using namespace std;
class Node{
public:
  int data;
  Node *next;
  Node *back;

public:
  Node(int data1, Node *next1, Node *back1)
  {
    data = data1; // Initialize data with the provided value
    next = next1; // Initialize next with the provided value
    back = back1; // Initialize back with the provided value
  }

public:
  Node(int data1)
  {
    data = data1;   // Initialize data with the provided value
    next = nullptr; // Initialize next as null since it's the end of the list
    back = nullptr; // Initialize next as null since it's the start of the list
  }
};
void print(Node *head)
{

  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
}
Node *convrt_arr_2_DLL(vector<int> &a)
{
  Node *head = new Node(a[0]);
  Node *prev = head;
  for (int i = 1; i < a.size(); i++)
  {
    Node *temp = new Node(a[i], nullptr, prev);
    prev->next = temp;
    prev = prev->next;
  }
  return head;
}
Node* reverse_the_DLL_OP(Node* head){
  // if head is empty or there is only one element
  // we can directly just return the head
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  // Initialize a pointer to
  // the previous node
  Node* last = NULL; 
  // Initialize a pointer to
  // the current node
  Node* currnt = head;
  // Traverse the linked list
  while (currnt != NULL){
    // Store a reference to
    // the previous node
    last = currnt->back;
    // Swap the previous and
    // next pointers
    currnt->back = currnt->next;
    // This step reverses the links
    currnt->next = last;
    // Move to the next node
    // in the original list
    currnt = currnt->back;
  }
  // The final node in the original list
  // becomes the new head after reversal
  return (last->back);
}
int main(){
  vector<int> a = {12,5,8,7};
  Node *head = convrt_arr_2_DLL(a);
  
  // reversing the DLL...
  head = reverse_the_DLL_OP(head);
  print(head);

  return 0;                                                                                          
}
