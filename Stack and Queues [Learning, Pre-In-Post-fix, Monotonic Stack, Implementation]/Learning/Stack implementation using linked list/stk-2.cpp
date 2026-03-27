#include<bits/stdc++.h>
using namespace std;
// STACK IMPLEMENTATION USING LINKED LISTS:-------------------------->
class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1,Node* next1){
        data = data1;  // Initialize data with the provided value
        next = next1;  // Initialize next with the provided
    }

    public:
    Node(int data1){
        data = data1;    // Initialize data with the provided value
        next = nullptr; // Initialize next as null since it's the end of the list
    }
};
class STACK{
    
    Node* top;
    int currSize;
    public:

    STACK(){
        top = NULL;
        currSize = 0;
    }

    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        cout << "Element pushed" << "\n";
        currSize++;
    }

    int pop(){
        if(top == NULL){
            return -1;
        }
        int topData = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        currSize--;
        return topData;
    }

    int Size(){
        return currSize;
    }

    int TOP(){
        if(currSize == 0){
            return -1;
        }
        return top->data;
    }

    bool IsEmpty() {
    return (top == NULL);
    }

    void printStack(){
        Node* temp = top;
        while (temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    
};
int main(){
    STACK stk;
    stk.push(10);
    cout << "Element popped: " << stk.pop() << "\n";
    cout << "Stack size: " << stk.Size() << "\n";
    cout <<"Stack empty or not? "<<stk.IsEmpty()<<"\n";
    cout << "stack's top element: " << stk.TOP() << "\n";
    return 0;
}
