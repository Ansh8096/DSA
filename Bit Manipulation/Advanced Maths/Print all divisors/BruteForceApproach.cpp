#include<bits/stdc++.h>
using namespace std;
vector<int> PrintAllDivisors_BR(int n){
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if(n%i == 0){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){
    
    int n;
    cout<<"enter the value of n :"<<endl;
    cin>>n;

    vector<int> ans = PrintAllDivisors_BR(n);
    for (auto itt : ans) cout<<itt<<" ";

    return 0;
}
