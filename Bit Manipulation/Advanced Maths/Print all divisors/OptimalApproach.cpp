#include<bits/stdc++.h>
using namespace std;
vector<int> PrintAllDivisors_OP(int n){
    vector<int> ans;
    for (int i = 1; i*i <= n;i++)
    {
        if(n%i == 0){
            ans.push_back(i);
            if((n/i) != i){
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}
int main(){
    
    int n;
    cout<<"enter the value of n :"<<endl;
    cin>>n;

    vector<int> ans = PrintAllDivisors_OP(n);
    for (auto itt : ans) cout<<itt<<" ";

    return 0;
}
