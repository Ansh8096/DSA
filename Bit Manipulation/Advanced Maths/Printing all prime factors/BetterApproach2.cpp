#include<bits/stdc++.h>
using namespace std;
vector<int> printingAllPrimeFactors_BT2(int n){
    vector<int> ans;
    for (int i = 2; i <= n ; i++)
    {
        if(n%i == 0){
            ans.push_back(i);
            while(n%i == 0) n = n/i;
        }
    }
    return ans;
}
int main(){
    
    int n;
    cout<<"enter the value of n :"<<endl;
    cin>>n;

    vector<int> ans = printingAllPrimeFactors_BT2(n);
    for (auto itt : ans) cout<<itt<<" ";
    
    return 0;
}
