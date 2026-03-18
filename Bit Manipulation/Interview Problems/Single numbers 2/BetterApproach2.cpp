#include<bits/stdc++.h>
using namespace std;
int singleNumber2_BT2(vector<int>& a){
    int n = a.size();
    sort(a.begin(),a.end()); 
    for (int i = 1; i < n; i = i+3)
    {
        // Single element is found...
        if(a[i] != a[i-1]) return a[i-1];
    }
    // single is the last element in the array...
    return a[n-1];
}
int main(){
    
    int n;
    cout<<"enter the value of n :"<<endl;
    cin>>n;

    vector<int> a(n);
    cout<<"Enter the values in the array : "<<endl;
    for (int i = 0; i < n; i++) cin>>a[i];

    cout<<singleNumber2_BT2(a);
    return 0;
}
