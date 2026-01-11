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
Node* starting_node_of_LL_OP(Node* head){
  Node* slow = head;
  Node* fast = head;
  // Phase 1: Detect the loop
  while(fast != NULL && fast->next != NULL){
    // Move slow one step
    slow = slow->next;
    // Move fast two steps
    fast = fast->next->next;
    // If slow and fast meet,
    // a loop is detected
    if(slow == fast){
      // Reset the slow pointer
      // to the head of the list
      slow = head;
      // Phase 2: Find the first node of the loop
      while(slow != fast){
        // Move slow and fast one step
        // at a time
        slow = slow->next;
        fast = fast->next;
        // When slow and fast meet again,
        // it's the first node of the loop
      }
      // Return the first node of the loop
      return slow;
    }
  }
  // If no loop is found, return NULL
  return NULL;
}
int main(){

  // we need to create each node of Linked list seperately to create a cycle...
  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);
  Node* fourth = new Node(4);
  Node* fifth = new Node(13);
  Node* sixth = new Node(6);
  Node* seventh = new Node(7);
  Node* eight = new Node(8);
  Node* ninth = new Node(9);
    
  // linking these nodes...
  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;
  sixth->next = seventh;
  seventh->next = eight;
  eight->next = ninth;
    
  // creates a loop:
  ninth->next = third; 

  Node* ans = starting_node_of_LL_OP(head);
  cout<<ans->data;
  return 0;                                                                                          
}
