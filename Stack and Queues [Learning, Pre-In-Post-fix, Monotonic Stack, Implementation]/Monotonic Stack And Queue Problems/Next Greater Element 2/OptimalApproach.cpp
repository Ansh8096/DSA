#include<bits/stdc++.h>
using namespace std;
vector<int> NextGreaterElement2_OP(vector<int>&a,int n){
    vector<int> ans(n); 
    stack<int> stk;
    for(int i = 2*n-1;i >= 0 ; i--){ // O(2n)...
        while (!stk.empty() && stk.top() <= a[i%n]){ // O(2n)...
            stk.pop();
        }
        if(i<n){
            ans[i] = (stk.empty())? -1 : stk.top();
        }
        stk.push(a[i%n]);
        
    }
    return ans;
}
int main(){

    int n;
    cout<<"Enter the value of n: "<<endl;
    cin >> n;

    vector<int> a(n);
    cout<<"Enter the values of the array: "<<endl;
    for(int i = 0; i<n ;i++) cin>>a[i];
    vector<int> ans = NextGreaterElement2_OP(a,n);
    
    for(auto itt : ans) cout<<itt<<" ";


    return 0;
}
