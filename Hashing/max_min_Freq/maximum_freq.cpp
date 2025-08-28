#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of array ";
    cin>>n;
    int arr[n];
    cout<<"enter the value of array ";
    for (int i = 0; i < n; i++) cin>>arr[i];
    
    // precompute:-
    map<int,int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++ ;
    }
    
    // TO FIND THE HIGHEST FREQUENCY ELEMENT IN THE HASHING...
    int hcf=0; 
    int ans=-1;
    
    for (auto it : mpp)
    {
        if(it.second > hcf)   
        {
       hcf = it.second;
       ans = it.first;   // the highest freq. element gets store in it at the end of the loop ...
    }
}
    cout<<"Highest frequency element in the array is : "<<ans<<". with frequency is: "<<hcf<<endl;
    return 0;
}
