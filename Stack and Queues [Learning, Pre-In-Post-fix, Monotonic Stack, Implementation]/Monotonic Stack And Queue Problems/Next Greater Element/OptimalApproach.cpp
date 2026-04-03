#include<bits/stdc++.h>
using namespace std;
vector<int> NextGreaterElement1_OP(vector<int>&a,int n){
    vector<int> ans(n);
    stack<int> stk;
    for(int i = n-1;i >=0 ; i--){
        while(!stk.empty()  &&  stk.top() <= a[i]){
            stk.pop();
        } 
        if(stk.empty()) ans[i] = -1; // No next greater element...
        else ans[i] = stk.top(); 
        stk.push(a[i]); // hoping that 'a[i]' will going to be our next greater Element...
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
    vector<int> ans = NextGreaterElement1_OP(a,n);
    
    for(auto itt : ans) cout<<itt<<" ";


    return 0;
}
