#include<bits/stdc++.h>
using namespace std;
vector<int> printingAllPrimeFactors_OP(int n){
    vector<int> ans;
    for (int i = 2; i*i <= n ; i++)
    {
        if(n%i == 0){
            ans.push_back(i);
            while(n%i == 0) n = n/i;
        }
    }
    if(n!=1) ans.push_back(n);
    return ans;
}
int main(){
    
    int n;
    cout<<"enter the value of n :"<<endl;
    cin>>n;

    vector<int> ans = printingAllPrimeFactors_OP(n);
    for (auto itt : ans) cout<<itt<<" ";
    
    return 0;
}
