#include<bits/stdc++.h>
using namespace std;
int singleNumber2_BT1(vector<int>& a){
    int ans = 0 , n = a.size();
    // Traversing and checking for bit in 'int'...
    for (int bitIndex = 0; bitIndex <= 31 ; bitIndex++){
        int cnt = 0;
        // Checking for set bit in the all the elements of the array...
        for (int i = 0; i < n; i++){
            // If the set bit is there then only increase the count...
            // '1<<bitIndex' will place the 1 where we are checking for the set bit in the a[i]...  
            if(a[i] & (1<<bitIndex)) cnt++; 
        }
        // If the count of set bit is not multiple of 3,means that bit will be set bit in our 'ans'...  
        if(cnt % 3 == 1){
            // We are making that bit set in our 'ans' which is initially zero...
            ans = (ans | (1<<bitIndex));
        }
    }
    return ans;
}
int main(){
    
    int n;
    cout<<"enter the value of n :"<<endl;
    cin>>n;

    vector<int> a(n);
    cout<<"Enter the values in the array : "<<endl;
    for (int i = 0; i < n; i++) cin>>a[i];

    cout<<singleNumber2_BT1(a);
    return 0;
}
