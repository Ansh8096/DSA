#include<bits/stdc++.h>
using namespace std;
int subarraysWithSmallerOrequalKdifferentIntegers(vector<int>&a,int k){
    if (k<0) return 0;
    int cnt = 0 , l = 0 , r = 0;
    map<int,int> mpp;

    int n = a.size(); 
    while (r<n){
        mpp[a[r]]++;
        while(mpp.size() > k){
            mpp[a[l]]--;
            if(mpp[a[l]] == 0){
                mpp.erase(a[l]);
            }
            l++;
        }
        cnt += r-l+1;
        r++;
    }
    
    return cnt;
}
int subarraysWithKDifferentIntegers_OP(vector<int>&a , int k){
    return subarraysWithSmallerOrequalKdifferentIntegers(a,k) - subarraysWithSmallerOrequalKdifferentIntegers(a,k-1);
}
int main(){

    int n1;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n1;

    vector<int>a(n1);
    cout<<"Enter the value of the array: "<<endl;
    for (int i = 0; i < n1; i++) cin>>a[i];

    cout<<subarraysWithKDifferentIntegers_OP(a,2);

    return 0;
}
