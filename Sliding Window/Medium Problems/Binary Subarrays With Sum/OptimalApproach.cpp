#include<bits/stdc++.h>
using namespace std;
int binarySubarrayWithEqualAndSmallerToGoal(vector<int>&a,int k){
    int l = 0 , r = 0 , cnt = 0 , currSum = 0; 
    if(k<0) return 0;
    while (r < a.size()){
        currSum += a[r];
        while(currSum > k){
            currSum -= a[l];
            l++;
        }
        cnt += r-l+1;
        r++;
    }
    return cnt; 
}
int numSubarraysWithSum_OP(vector<int>& nums, int goal) {
    return binarySubarrayWithEqualAndSmallerToGoal(nums,goal) - binarySubarrayWithEqualAndSmallerToGoal(nums,goal-1);
}
int main(){
        
    int n1;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n1;

    vector<int>a(n1);
    cout<<"Enter the value of the array: "<<endl;
    for (int i = 0; i < n1; i++) cin>>a[i]; 

    cout<<numSubarraysWithSum_OP(a,2);

    return 0;
}
