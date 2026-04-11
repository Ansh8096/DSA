#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    stack<pair<int,int>> stk;
    int idx = -1;
    StockSpanner() {
        idx = -1;
        stack<pair<int,int>> newStk;
        stk = newStk;
    }
    
    int next(int price) {
        idx++;
        while(!stk.empty() && stk.top().first <= price){
            stk.pop();
        }
        int ans = idx - ((stk.empty()) ? -1 : stk.top().second);
        stk.push({price,idx});
        return ans;
    }
};
int main(){
    
    return 0;
}
