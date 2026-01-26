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
void print(Node *head){
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
}
Node *convrt_arr_2_DLL(vector<int> &a){
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
Node *remove_dup_from_DLL_1Approach(Node *head){
  Node *temp = head;
  while (temp != NULL && temp->next != NULL)
  {
    Node *nextNode = temp->next;
    while (nextNode != NULL && nextNode->data == temp->data)
    {
      Node *dup = nextNode;
      nextNode = nextNode->next;
      free(dup);
    }
    temp->next = nextNode;
    if (nextNode != NULL) nextNode->back = temp;
    temp = temp->next;
  }
  return head;
}
int main(){
  vector<int> a = {1,1,1,2,3,3,4};
  Node *head = convrt_arr_2_DLL(a);

  head = remove_dup_from_DLL_1Approach(head);
  print(head);
  return 0;                                                                                          
}
