#include<bits/stdc++.h>
using namespace std;
int singleNumber2_OP(vector<int>& a){
    int ones = 0, twos = 0;
    for (int i = 0; i < a.size(); i++)
    {
        // it will add the a[i] in ones if it is not in twos and ones is '0' (initially)...
        // it will also set ones to 0 , if the a[i] is same as ones... 
        ones = (ones ^ a[i]) & (~twos);

        // it will add the a[i] in twos if it is not in ones and twos is '0' (initially)...
        // it will also set twos to 0 , if the a[i] is same as twos... 
        twos = (twos ^ a[i]) & (~ones);
    }
    // answer..
    return ones;
}
int main(){
    
    int n;
    cout<<"enter the value of n :"<<endl;
    cin>>n;

    vector<int> a(n);
    cout<<"Enter the values in the array : "<<endl;
    for (int i = 0; i < n; i++) cin>>a[i];

    cout<<singleNumber2_OP(a);
    return 0;
}
