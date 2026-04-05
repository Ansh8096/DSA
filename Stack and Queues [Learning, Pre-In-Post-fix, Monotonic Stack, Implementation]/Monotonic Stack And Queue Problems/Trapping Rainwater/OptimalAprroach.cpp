#include<bits/stdc++.h>
using namespace std;
int trappingRainwater_OP(vector<int>& a,int n){
    int totalWater = 0 , leftMax = 0 , rightMax = 0;
    int left = 0 , right = n-1;
    while(left < right){
        if(a[left] <= a[right]){
            // the water can be clogged here...
            if(a[left] < leftMax){
                totalWater += leftMax - a[left];
            }
            else leftMax = a[left];
            left++;
        }
        else{
            // the water can be clogged here...
            if(a[right] < rightMax){
                totalWater += rightMax - a[right]; 
            }
            else rightMax = a[right];
            right --;
        }
    }
    return totalWater;
}
int main(){

    int n;
    cout<<"Enter the value of n: "<<endl;
    cin >> n;

    vector<int> a(n);
    cout<<"Enter the values of the array: "<<endl;
    for(int i = 0; i<n ;i++) cin>>a[i];
    cout<<trappingRainwater_OP(a,n);

    return 0;
}
