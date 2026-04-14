#include<bits/stdc++.h>
using namespace std;
int fruitIntoBaskets_OP2(vector<int> &a){
    int maxLen = 0 , l = 0 , r = 0;
    map<int,int> mpp;
    while(r<a.size()){
        mpp[a[r]]++;
        if(mpp.size() > 2){
            mpp[a[l]]--;
            if(mpp[a[l]] == 0){
                mpp.erase(a[l]);
            }
            l++;
        }  
        if(mpp.size() <= 2)maxLen = max(maxLen,r-l+1);
        r++;
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
    
    cout<<fruitIntoBaskets_OP2(a);

    return 0;
}
