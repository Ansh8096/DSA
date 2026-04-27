#include<bits/stdc++.h>
using namespace std;
int candy_BR(vector<int>& a) {
    int n = a.size();
    vector<int> left(n), right(n);
    left[0] = 1; right[n-1] = 1;
    for(int i = 1;i<n;i++){
        if(a[i] > a[i-1]){
            left[i] = left[i-1]+1;
        }
        else{
            left[i] = 1;
        }
    }
    
    
    for(int i = n-2;i>=0;i--){
        if(a[i] > a[i+1]){
            right[i] = right[i+1]+1;
        }
        else{
            right[i] = 1;
        }
    }

    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        maxSum += max(left[i],right[i]);
    }
    
    return maxSum;
}
int main(){

    vector<int> a = {1,0,2};
    cout<<candy_BR(a);
    
    return 0;
}
