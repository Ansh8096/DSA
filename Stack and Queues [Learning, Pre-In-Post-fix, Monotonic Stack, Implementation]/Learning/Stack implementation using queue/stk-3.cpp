#include<bits/stdc++.h>
using namespace std;
// STACK IMPLEMENTATION USING QUEUE:-------------------------->
class MyStack {
public:
    queue<int> q;
    public:
    MyStack() {
       
    }
    
    void Push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 1; i < size; i++) // we need to run loop from 1 to avoid reversing the last pushed element in the stack...
        {
            q.push(q.front());
            q.pop();
        }
            
    }
    int Pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    
    int Top() {
        return q.front();
    }
    
    bool Empty() {
        return q.empty();
    }

    int Size(){
        return q.size();
    }
};
int main(){
    MyStack s;
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);
    cout << "Top of the stack: " << s.Top() << endl;
    cout << "Size of the stack before removing element: " << s.Size() << endl;
    cout << "The deleted element is: " << s.Pop() << endl;
    cout << "Top of the stack after removing element: " << s.Top() << endl;
    cout << "Size of the stack after removing element: " << s.Size();
    return 0;
}
