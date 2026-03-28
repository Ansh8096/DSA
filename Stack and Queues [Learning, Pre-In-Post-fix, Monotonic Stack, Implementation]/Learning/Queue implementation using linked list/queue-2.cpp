#include<bits/stdc++.h>
using namespace std;
// QUEUE IMPLEMENTATION USING LINKED LISTS:-------------------------->
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
class QUEUE{
    Node* start;
    Node* end;
    int currSize;

    public:
    QUEUE(){
        start = NULL;
        end = NULL;
        currSize = 0;
    }  

    void enqueue(int x){
        Node* temp = new Node(x);
        if(start == NULL){
            start = temp;
            end = temp;
        }
        else{
            end->next = temp;
            end = temp;
        }
        cout<<x<<" Inserted into Queue "<<endl;
        currSize++;
    }

    void dequeue(){
        if(start == NULL){
            cout << "Queue is Empty" << endl;
        }
        else {
            cout<<start->data <<" Removed From Queue"<<endl;
            Node* temp = start;
            start = start->next;
            delete temp;
            currSize--;
        }
    }

    int Top(){
        if(start == NULL) {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return start->data;
    }


    bool IsEmpty(){
    return (start == nullptr);
    }

    int Size(){
        return currSize;
    }

};
int main(){
    QUEUE Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);
    Q.dequeue();
    cout<<"The size of the Queue is: "<<Q.Size()<<endl;
    cout<<"The Peek element of the Queue is: "<<Q.Top()<<endl;    
    return 0;
}
