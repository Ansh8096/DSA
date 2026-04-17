#include<bits/stdc++.h>
using namespace std;
int maxPointsObtainedFromKCards_OP(vector<int>& a, int k) {
    int n = a.size();
    int maxSum = 0 , leftSum = 0 , rightSum = 0;
    for (int i = 0; i < k; i++) leftSum += a[i];

    maxSum = leftSum;

    int rightIdx = n-1;
    for(int i=k-1;i>=0;i--){
        leftSum -= a[i];
        rightSum += a[rightIdx];
        rightIdx--;
        maxSum = max(maxSum,leftSum+rightSum);
    }
    
    return maxSum;
}
int main(){

    int n1;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n1;

    vector<int>a(n1);
    cout<<"Enter the value of the array: "<<endl;
    for (int i = 0; i < n1; i++) cin>>a[i]; 
        
    cout<<maxPointsObtainedFromKCards_OP(a,4);

    return 0;
}
