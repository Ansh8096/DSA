#include <bits/stdc++.h>
using namespace std;
class Node{
public:
  int data;
  Node *next;
  Node *child;

public:
  Node()
  {
    next = nullptr;
    child = nullptr;
    data = 0;
  }
  Node(int data1, Node *next1, Node *child1)
  {
    data = data1; // Initialize data with the provided value
    next = next1; // Initialize next with the provided
    child = child1;
  }

public:
  Node(int data1)
  {
    data = data1;    // Initialize data with the provided value
    next = nullptr;  // Initialize next as null since it's the end of the list
    child = nullptr; // Initialize next as null since it's the end of the list
  }
};
void print(Node *head){
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->child;
  }
  cout << endl;
}
void printOriginalLinkedList(Node *head, int depth){
  // Print the linked list
  // in a grid-like structure
  while (head != nullptr)
  {
    cout << head->data;
    // If child exists, recursively
    // print it with indentation
    if (head->child)
    {
      cout << " -> ";
      printOriginalLinkedList(head->child, depth + 1);
    }
    // Add vertical bars
    // for each level in the grid
    if (head->next)
    {
      cout << endl;
      for (int i = 0; i < depth; ++i)
      {
        cout << "| ";
      }
    }
    head = head->next;
  }
}
Node *convert_arr_to_LL(vector<int> &a){
  if (a.size() == 0) return NULL;
  Node *head = new Node(a[0]);
  Node *temp = head;
  for (int i = 1; i < a.size(); i++)
  {
    Node *new_node = new Node(a[i]);
    temp->child = new_node;
    temp = temp->child;
  }
  return head;
}
Node *Flatten_LL_BR(Node *head){
  Node *temp = head;
  vector<int> a;
  while (temp != NULL)
  {
    Node *t2 = temp;
    while (t2 != NULL)
    {
      a.push_back(t2->data);
      t2 = t2->child;
    }
    temp = temp->next;
  }
  sort(a.begin(), a.end());
  return convert_arr_to_LL(a);
}
int main(){
  Node *head = new Node(5);
  head->child = new Node(14);

  head->next = new Node(10);
  head->next->child = new Node(4);

  head->next->next = new Node(12);
  head->next->next->child = new Node(20);
  head->next->next->child->child = new Node(13);

  head->next->next->next = new Node(7);
  head->next->next->next->child = new Node(17);

  cout << "Original linked list " << endl;
  printOriginalLinkedList(head, 0);
  cout << "\nlinked list after flatening: " << endl;
  head = Flatten_LL_BR(head);
  print(head);

  return 0;                                                                                          
}
