#include<bits/stdc++.h>
using namespace std;
int candy_BT(vector<int>& a) {
    int n = a.size();
    vector<int> left(n);
    left[0] = 1;
    for(int i = 1;i<n;i++){
        if(a[i] > a[i-1]){
            left[i] = left[i-1]+1;
        }
        else{
            left[i] = 1;
        }
    }

    int maxSum = left[n-1];
    for(int i = n-2;i>=0;i--){
        if(a[i] > a[i+1]){
            left[i] = max(left[i],left[i+1]+1);
        }
        maxSum += left[i];
    }
    return maxSum;
}
int main(){

    vector<int> a = {1,0,2};
    cout<<candy_BT(a);
    
    return 0;
}
