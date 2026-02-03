#include <bits/stdc++.h>
using namespace std;
class Node{
public:
  int data;
  Node *next;
  Node *random;

public:
  Node()
  {
    next = nullptr;
    random = nullptr;
    data = 0;
  }
  Node(int data1, Node *next1, Node *random1)
  {
    data = data1; // Initialize data with the provided value
    next = next1; // Initialize next with the provided value
    random = random1;
  }

public:
  Node(int data1)
  {
    data = data1;     // Initialize data with the provided value
    next = nullptr;   // Initialize next as null since it's the end of the list
    random = nullptr; // Initialize next as null since it's the end of the list
  }
};
void printClonedLinkedList(Node *head){
  while (head != nullptr)
  {
    cout << "Data: " << head->data;
    if (head->random != nullptr)
    {
      cout << ", Random: " << head->random->data;
    }
    else
    {
      cout << ", Random: nullptr";
    }
    cout << endl;
    // Move to the next node
    head = head->next;
  }
}
void insert_copy_nodes(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    // Create a new node with the same data
    Node *copyNode = new Node(temp->data);
    // Point the copy's next to
    // the original node's next
    copyNode->next = temp->next;
    // Point the original
    // node's next to the copy
    temp->next = copyNode;
    // Move to the next original node
    temp = temp->next->next;
  }
}
void copy_random_ptr(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    // Access the copied node
    Node *copyNode = temp->next;
    // If the original node has a random pointer
    // Point the copied node's random to the
    // corresponding copied random node
    if (temp->random)
      copyNode->random = temp->random->next;
    // Set the copied node's random to
    // null if the original random is null
    else
      copyNode->random = nullptr;
    temp = temp->next->next; // Move to the next original node
  }
}
Node *connecting_next_ptr(Node *head)
{
  Node *dummyNode = new Node(-1);
  Node *res = dummyNode;
  Node *temp = head;
  while (temp != NULL)
  {
    // Creating a new List by pointing to copied nodes
    res->next = temp->next;
    // Disconnect and revert back to the initial state of the original linked lis
    temp->next = temp->next->next;
    res = res->next;
    temp = temp->next; // Move to the next original node
  }
  // Return the copy of the list starting from the dummy node
  return dummyNode->next;
}
Node *Copy_LL_with_random_ptr_OP(Node *head)
{
  // If the original list
  // is empty, return null
  if (!head)
    return NULL;
  // Step 1: Insert copy of
  // nodes in between
  insert_copy_nodes(head);
  // Step 2: Connect random
  // pointers of copied nodes
  copy_random_ptr(head);
  // Step 3: Retrieve the deep
  // copy of the linked list
  return connecting_next_ptr(head);
}
int main(){
  // Example linked list: 7 -> 14 -> 21 -> 28
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    head = Copy_LL_with_random_ptr_OP(head);
    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

  return 0;                                                                                          
}
