#include <bits/stdc++.h>
using namespace std;
class Node{
public:
  int data;
  Node *next;

public:
  Node(int data1, Node *next1)
  {
    data = data1; // Initialize data with the provided 
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
Node *reverse_SLL_OP1(Node *head)
{
  Node *temp = head;
  Node *prev = NULL;
  Node *front = NULL;
  while (temp != NULL)
  {
    // 'front' to preserve the reference
    front = temp->next;
    // Reverse the direction of the
    // current node's 'next' pointer
    // to point to 'prev'
    temp->next = prev;
    // Move 'prev' to the current
    // node for the next iteration
    prev = temp;
    // Move 'temp' to the 'front' node
    // advancing the traversal
    temp = front;
  }
  // Return the new head of
  // the reversed linked list
  return prev;
}
bool chk_for_palindrome_of_LL_OP(Node* head){
  // Check if the linked list is empty
  // or has only one node
  if (head == NULL || head->next == NULL) {
      
     // It's a palindrome by definition
    return true; 
  }
  // Initialize two pointers, slow and fast,
  // to find the middle of the linked list   
  Node* slow = head;
  Node* fast = head;
  // Traverse the linked list to find the
  // middle using slow and fast pointers
  while (fast->next != NULL && fast->next->next != NULL)
  {
    // Move slow pointer one step at a time
    slow = slow->next;
    // Move fast pointer two steps at a time
    fast = fast->next->next;
  }
  // Reverse the second half of the
  // linked list starting from the middle
  Node* new_head = reverse_SLL_OP1(slow->next);
  // Pointer to the first half
  Node* first = head;
  // Pointer to the reversed second half
  Node* second = new_head;
  while(second != NULL){
    // Compare data values of 
    // nodes from both halves
    
    // If values do not match,
    // the list is not a palindrome
    if(second->data != first->data){
       // Reverse the second half 
       // back to its original state
      reverse_SLL_OP1(new_head);
       // Not a palindrome
      return false;  
    }
    // Move the first pointer
    first = first->next;
    // Move the second pointer
    second = second->next;
  }
  // Reverse the second half
  // back to its original state
  reverse_SLL_OP1(new_head);
  // The linked list is a palindrome
  return true;
}
int main(){
  vector<int> a = {1,0,1};
  Node *head = convrt_arr2LL(a);
  cout<<chk_for_palindrome_of_LL_OP(head);

  return 0;                                                                                          
}
