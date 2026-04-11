#include<bits/stdc++.h>
using namespace std;
vector<int> SlidingWindowMaximum_OP(vector<int>&a,int k){
    vector<int> ans;
    deque<int> dq;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && dq.front() <= i-k)
        {
            dq.pop_front();
        }

        while (!dq.empty()  && a[dq.back()] <= a[i])
        {
            dq.pop_back();
        }
        
        dq.push_back(i);

        if(i >= k-1) ans.push_back(a[dq.front()]);
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
    
    vector<int> ans = SlidingWindowMaximum_OP(a,3);
    for(int i = 0; i<ans.size() ;i++) cout<<ans[i]<<" ";
    return 0;
}
