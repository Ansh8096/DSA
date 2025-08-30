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
    
    // TO FIND THE LOWEST FREQUENCY ELEMENT IN THE HASHING...
    int Lf=INT_MAX; 
    int ans=0;
    
    for (auto it : mpp)
    {
        if(it.second < Lf)
        {
       Lf = it.second;
       ans = it.first;  
    }
    }
    cout<<"Lowest frequency element in the array is : "<<ans<<". with frequency : "<<Lf<<endl;
    return 0;
}
