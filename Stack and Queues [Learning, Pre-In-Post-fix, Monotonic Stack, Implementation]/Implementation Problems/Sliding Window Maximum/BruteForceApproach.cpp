#include<bits/stdc++.h>
using namespace std;
vector<int> SlidingWindowMaximum_BR(vector<int>&a,int k){
    int i=0, j = k-1;
    vector<int> ans;
    int n = a.size();
    
    while ((j-i+1) == k  && j<n) // O(n-k)...
    {
        int maxi = 0;
        for (int idx = i; idx <= j; idx++) // O(k)...
        {
            maxi = max(maxi,a[idx]);
        }
        ans.push_back(maxi);
        i++; j++;
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
    
    vector<int> ans = SlidingWindowMaximum_BR(a,3);
    for(int i = 0; i<ans.size() ;i++) cout<<ans[i]<<" ";
    return 0;
}
