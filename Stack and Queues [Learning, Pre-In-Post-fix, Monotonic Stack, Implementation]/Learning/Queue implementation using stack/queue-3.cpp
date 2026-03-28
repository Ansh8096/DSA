#include<bits/stdc++.h>
using namespace std;
// QUEUE IMPLEMENTATION USING STACK:-------------------------->
class MyQueue_BR {
    stack<int> st1 , st2;    
    public:
    void Push(int x) {
        while (st1.size() != 0)
        {
            st2.push(st1.top());
            st1.pop();
        }
        cout << "The element pushed is " << x << endl;
        st1.push(x);
        while (st2.size() != 0)
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int Pop() {
        int n = st1.top();
        st1.pop();
        return n;   
    }
    
    int Top() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }

    int Size(){
        return st1.size();
    }
};
class MyQueue_OP {
    stack<int> st1 , st2;    
    public:
    void Push(int x) {
        cout << "The element pushed is " << x << endl;
        st1.push(x);
    }
    
    int Pop(){

    if (st2.empty()){
        while (st1.size() != 0){
        st2.push(st1.top());
        st1.pop();
        }
    }
    
    int n = st2.top();
    st2.pop();
    return n;
    }
    
    int Top(){
    if (st2.empty()){
        while (st1.size() != 0){
        st2.push(st1.top());
        st1.pop();
        }
    }
    return st2.top();
    }
    
    bool empty() {
        return (st1.empty() && st2.empty());
    }

    int Size(){
        return st1.size() + st2.size();
    }
};
int main(){
    // MyQueue_BR q;
    // q.Push(3);
    // q.Push(4);
    // cout << "The element poped is " << q.Pop() << endl;
    // q.Push(5);
    // cout << "The top of the queue is " << q.Top() << endl;
    // cout << "The size of the queue is " << q.Size() << endl;

    MyQueue_OP q;
    q.Push(3);
    q.Push(4);
    cout << "The element poped is " << q.Pop() << endl;
    q.Push(5);
    cout << "The top of the queue is " << q.Top() << endl;
    cout << "The size of the queue is " << q.Size() << endl;
    return 0;
}
