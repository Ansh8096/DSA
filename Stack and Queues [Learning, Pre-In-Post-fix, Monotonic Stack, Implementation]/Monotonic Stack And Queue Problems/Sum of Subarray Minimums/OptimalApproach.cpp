#include<bits/stdc++.h>
using namespace std;
vector<int> findNSE(vector<int>&a,int n){
    vector<int> nse(n);
    stack<int>stk;
    for (int i = n-1; i >= 0; i--)
    {
        while (!stk.empty() and a[stk.top()] >= a[i]) stk.pop();
        nse[i] = (stk.empty()) ? n : stk.top();
        stk.push(i);
    }
    return nse;
}
vector<int> findPSEE(vector<int>&a,int n){
    vector<int> psee(n);
    stack<int>stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() and a[stk.top()] > a[i]) stk.pop();
        psee[i] = (stk.empty()) ? -1 : stk.top();
        stk.push(i);
    }
    return psee;   
}
int sumOfMinOfSubArr_OP(vector<int>& a,int n){
    vector<int> nse = findNSE(a,n);
    vector<int> psee = findPSEE(a,n);

    int total = 0;
    int mod = (int)(1e9+7);
    for (int i = 0; i < n; i++)
    {
        int left = i-psee[i];
        int right = nse[i] - i;
        total = (total+(right*left*1LL*a[i])%mod)%mod;
    }
    return total;
}
int main(){

    int n;
    cout<<"Enter the value of n: "<<endl;
    cin >> n;

    vector<int> a(n);
    cout<<"Enter the values of the array: "<<endl;
    for(int i = 0; i<n ;i++) cin>>a[i];
    cout<<sumOfMinOfSubArr_OP(a,n);

    return 0;
}
