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
Node* deleting_tail_of_DLL(Node*head){
  // edge case:- when the DLL is empty OR when the DLL has only one node...
  if(head == NULL || head->next == nullptr) return NULL;
  Node* temp = head;
  while(temp->next != nullptr){
    temp = temp->next;
  }
  Node* prev = temp->back;
  temp->back = nullptr;
  prev->next = nullptr;
  free(temp);
  return head;
}
int main(){
  vector<int> a = {12,5,8,7};
  Node *head = convrt_arr_2_DLL(a);

  // deleting tail of DLl...
  head = deleting_tail_of_DLL(head);
  print(head);

  return 0;                                                                                          
}
