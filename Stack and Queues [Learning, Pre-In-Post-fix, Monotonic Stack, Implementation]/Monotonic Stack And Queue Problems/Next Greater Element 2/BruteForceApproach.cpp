#include<bits/stdc++.h>
using namespace std;
vector<int> NextGreaterElement2_BR(vector<int>&a,int n){
    vector<int> ans(n);
    for(int i = 0;i <n ; i++){
        for (int j = i+1; j < i+n-1; j++)
        {
            int idx = j%n;
            if(a[idx] > a[i]){
                ans[i] = a[idx];
                break;
            }
            else ans[i] = -1;
        }
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
    vector<int> ans = NextGreaterElement2_BR(a,n);
    
    for(auto itt : ans) cout<<itt<<" ";


    return 0;
}
