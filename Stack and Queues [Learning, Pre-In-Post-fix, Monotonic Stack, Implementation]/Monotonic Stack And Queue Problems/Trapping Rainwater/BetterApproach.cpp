#include<bits/stdc++.h>
using namespace std;
int trappingRainwater_BT(vector<int>& a,int n){
    // Getting suffixMax for every a[i]...
    int suffixMax[n];
    suffixMax[n-1] = a[n-1];
    for (int i = n-2; i >=0; i--)
    {
        suffixMax[i] = max(a[i],suffixMax[i+1]);
    }
    
    int prefixMax = a[0]; // Getting initial prefixMax...
    // calculating water trapped...
    int totalWaterTRapped = 0;
    for (int i = 1; i < n-1; i++){
        prefixMax = max(a[i],prefixMax);  // Getting prefixMax for every a[i]...
        int leftMax = prefixMax;
        int rightMax = suffixMax[i];
        if(a[i] < leftMax and a[i] < rightMax){
            totalWaterTRapped += min(leftMax,rightMax) - a[i];
        }
    }
    return totalWaterTRapped;   
}
int main(){

    int n;
    cout<<"Enter the value of n: "<<endl;
    cin >> n;

    vector<int> a(n);
    cout<<"Enter the values of the array: "<<endl;
    for(int i = 0; i<n ;i++) cin>>a[i];
    cout<<trappingRainwater_BT(a,n);

    return 0;
}
