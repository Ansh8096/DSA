#include<bits/stdc++.h>
using namespace std;
int consecutiveMaxOnes3_BR(vector<int>&a,int k){
    int n = a.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++){
        int zeroes = 0;
        for (int j=i;j<n;j++){
            if(a[j] == 0) zeroes++;
            if(zeroes <= k){
                maxLen = max(maxLen,j-i+1);
            }
            else break;
        }
    }
    return maxLen;
}
int main(){
        
    int n1;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n1;

    vector<int>a(n1);
    cout<<"Enter the value of the array: "<<endl;
    for (int i = 0; i < n1; i++) cin>>a[i]; 
    
    cout<<consecutiveMaxOnes3_BR(a,2);
    
    return 0;
}
