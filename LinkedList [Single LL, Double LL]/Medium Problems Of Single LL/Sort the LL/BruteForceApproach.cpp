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
Node *sort_LL_BR(Node *head){
  Node *temp = head;
  vector<int> a;
  // storing data in arr...
  while (temp != NULL)
  {
    a.push_back(temp->data);
    temp = temp->next;
  }

  // sorting the data..
  sort(a.begin(), a.end());

  int i = 0;
  temp = head;
  // putting the sorted data back in the LL...
  while (temp != NULL)
  {
    temp->data = a[i];
    i++;
    temp = temp->next;
  }
  return head;
}
int main(){
  vector<int> a = {0,7,2,9,4,5,6};
  Node *head = convrt_arr2LL(a);

  head = sort_LL_BR(head);
  print(head);
  return 0;                                                                                          
}
