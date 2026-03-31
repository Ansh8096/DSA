#include<bits/stdc++.h>
using namespace std;
class myStackWithGetMinFunc_OP{
    stack<int> stk; int currMin = INT_MAX;
    public:
    void Push1(int val){
        if(stk.empty()){
            stk.push(val);
            currMin = val;
        }
        else if(val > currMin) stk.push(val);
        else{
            stk.push(2*val - currMin);
            currMin = val;
        }
    }

    int Pop1(){
        if(stk.empty()) return -1; // edge case...
        int x = stk.top();
        stk.pop();

        if (x>currMin) {
            return x;
        }
        else{
            int poped = currMin;
            currMin = 2*currMin - x;
            return poped;
        }
    }

    int getMin1(){
        return currMin;
    }

    int Top1(){
        if(stk.empty()) return -1; // edge case...
        if(stk.top() > currMin) return stk.top();
        else return currMin;
    }

    int Size1(){
        return stk.size();
    }
};
int main(){

    myStackWithGetMinFunc_OP stk1;
    stk1.Push1(12);
    stk1.Push1(15);
    stk1.Push1(10);
    cout << "Min. of the stack: " << stk1.getMin1() << endl;
    cout << "Size of the stack before removing element: " << stk1.Size1() << endl;
    cout << "The deleted element is: " << stk1.Pop1() << endl;
    cout << "Top of the stack after removing element: " << stk1.Top1() << endl;
    cout << "Min. of the stack : " << stk1.getMin1();

    return 0;
}
