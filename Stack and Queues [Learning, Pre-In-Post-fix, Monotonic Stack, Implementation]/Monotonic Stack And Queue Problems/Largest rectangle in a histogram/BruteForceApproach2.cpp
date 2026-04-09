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
int maximumAreaOfRectangleInHistogram_BR2(vector<int> &a,int n){
    vector<int> nse = findNSE(a,n);
    vector<int> pse = findPSEE(a,n);
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        res = max(res,a[i]*(nse[i]-pse[i]-1));
    }
    return res;
}
int main(){

    int n;
    cout<<"Enter the value of n: "<<endl;
    cin >> n;

    vector<int> a(n);
    cout<<"Enter the values of the array: "<<endl;
    for(int i = 0; i<n ;i++) cin>>a[i];
    cout<<maximumAreaOfRectangleInHistogram_BR2(a,n);

    return 0;
}
