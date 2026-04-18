#include<bits/stdc++.h>
using namespace std;
int subarraysWithKDifferentIntegers_BR(vector<int>&a,int k){
    int cnt = 0;
    int n = a.size(); 
    for (int i = 0; i < n; i++)
    {
        map<int,int> mpp;
        for (int j = i; j < n; j++){
            mpp[a[j]]++;
            if(mpp.size() == k) cnt++;
            if(mpp.size() > k) break;
        }
    }
    return cnt;
}
int main(){

    int n1;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n1;

    vector<int>a(n1);
    cout<<"Enter the value of the array: "<<endl;
    for (int i = 0; i < n1; i++) cin>>a[i];

    cout<<subarraysWithKDifferentIntegers_BR(a,2);

    return 0;
}
