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
    next = next1; // Initialize next with the provided
    back = back1; // Initialize back with the provided
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
void deleting_the_given_node_in_DLL(Node *node){
  Node *prev = node->back;
  Node *front = node->next;
  // when the given node is null
  if (front == NULL)
  {
    prev->next = nullptr;
    node->back = nullptr;
    delete node;
    return;
  }
  // when the given node is b/w DLL...
  else
  {
    prev->next = front;
    front->back = prev;
    node->next = node->back = nullptr;
    delete node;
  }
}
int main(){
  vector<int> a = {12,5,8,7};
  Node *head = convrt_arr_2_DLL(a);

  deleting_the_given_node_in_DLL(head->next->next->next);
  print(head);
  return 0;                                                                                          
}
