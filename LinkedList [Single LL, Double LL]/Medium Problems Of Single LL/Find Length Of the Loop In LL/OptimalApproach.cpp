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
int finding_length(Node *slow, Node *fast)
{
  // Function to return the lenght of loop when slow and fast are on the same node

  int cnt = 1; // count to keep track of nodes encountered in loop
  // move fast by one step
  fast = fast->next;
  // traverse fast till it
  // reaches back to slow
  while (slow != fast)
  {
    // at each node increase count by 1 and move fast forward by one step
    cnt++;
    fast = fast->next;
  }
  // loop terminates when fast reaches
  // slow again and the count is returned
  return cnt;
}
int Length_of_the_loop_in_LL_OP(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  // Step 1: Traverse the list to detect a loop
  while (fast != NULL && fast->next != NULL)
  {
    // Move slow one step
    slow = slow->next;
    // Move fast two steps
    fast = fast->next->next;
    // Step 2: If the slow and fast pointers
    // meet, there is a loop
    if (slow == fast)
    {
      // return the number of nodes
      // in the loop
      return finding_length(slow, fast);
    }
  }
  return 0; // if there is no loop in the LL
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

  cout<<Length_of_the_loop_in_LL_OP(head);
  return 0;                                                                                          
}
