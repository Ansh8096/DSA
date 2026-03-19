#include<bits/stdc++.h>
using namespace std;
vector<int> singleNumber3_OP(vector<int>& a){
    int Xor = 0;
    for (int i = 0; i < a.size(); i++) Xor ^= a[i];

    // '(Xor & (Xor - 1))' it will clear the rightMost set bit ,  after that it '^ Xor' it will help me to regain that set Bit... 
    int rightMostSetBit =(Xor & (Xor - 1)) ^ Xor;

    int b1 = 0 , b2 = 0;
    for (int i = 0; i < a.size(); i++)
    {
        // differentiating the elements in the array on the basis of last set bit 
        if(a[i] & rightMostSetBit) {
            b1 ^= a[i];
        }
        else b2 ^= a[i];
    }
    vector<int> ans = {b1,b2};
    return ans;
    
}
int main(){
    
    int n;
    cout<<"enter the value of n :"<<endl;
    cin>>n;

    vector<int> a(n);
    cout<<"Enter the values in the array : "<<endl;
    for (int i = 0; i < n; i++) cin>>a[i];
    
    vector<int> ans = singleNumber3_OP(a);
    for(auto itt : ans){
        cout<<itt<<" ";
    }
    
    return 0;
}
