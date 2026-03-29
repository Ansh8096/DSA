#include<bits/stdc++.h>
using namespace std;
class myStackWithGetMinFunc_BR{
    stack<pair<int,int>> stk;
    public:
    void Push(int x){
        if(stk.empty()) {
            stk.push({x,x});
        }
        else {
            int currMin = stk.top().second;
            stk.push({x,min(x,currMin)});
        }
    }

    int Pop(){
        if(stk.empty()) return -1; // edge case...
        int poped = stk.top().first;
        stk.pop();
        return poped;
    }

    int getMin(){
        return stk.top().second;
    }

    int Top(){
        if(stk.empty()) return -1; // edge case...
        return stk.top().first;
    }

    int Size(){
        return stk.size();
    }
};
int main(){

    myStackWithGetMinFunc_BR stk1;
    stk1.Push(12);
    stk1.Push(15);
    stk1.Push(10);
    cout << "Min. of the stack: " << stk1.getMin() << endl;
    cout << "Size of the stack before removing element: " << stk1.Size() << endl;
    cout << "The deleted element is: " << stk1.Pop() << endl;
    cout << "Top of the stack after removing element: " << stk1.Top() << endl;
    cout << "Min. of the stack : " << stk1.getMin();
    
    return 0;
}
