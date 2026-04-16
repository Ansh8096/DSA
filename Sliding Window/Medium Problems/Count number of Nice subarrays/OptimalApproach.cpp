#include<bits/stdc++.h>
using namespace std;
int SubarrayWithEqualAndSmallerToGoal_2(vector<int>&a,int k){
    int l = 0 , r = 0 , cnt = 0 , currSum = 0; 
    if(k<0) return 0;
    while (r < a.size()){
        currSum += (a[r]%2);
        while(currSum > k){
            currSum -= (a[l]%2);
            l++;
        }

        cnt += r-l+1;
        r++;
    }
    return cnt; 
}
int numberOfNiceSubarrays(vector<int>& nums, int k) {
    return SubarrayWithEqualAndSmallerToGoal_2(nums,k) - SubarrayWithEqualAndSmallerToGoal_2(nums,k-1);
}
int main(){
        
    int n1;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n1;

    vector<int>a(n1);
    cout<<"Enter the value of the array: "<<endl;
    for (int i = 0; i < n1; i++) cin>>a[i]; 

    cout<<numberOfNiceSubarrays(a,3);

    return 0;
}
