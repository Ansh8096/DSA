#include<bits/stdc++.h>
using namespace std;
string CheckIfNoIsPrimeOrNot_OP(int n){
    int cnt = 0;
    for (int i = 1; i*i <= n; i++)
    {
        if(n%i == 0){
            cnt++;
            if(i != n/i) {
                cnt++;
            }
        }
        if(cnt > 2) break; 
    }
    if(cnt == 2) return "Yes it is prime no...";
    else return "No it is not Prime no...";
}
vector<int> printingAllPrimeFactors_BT1(int n){
    vector<int> ans;
    for (int i = 2; i*i <= n; i++)
    {
        if(n%i == 0){
            if(CheckIfNoIsPrimeOrNot_OP(i) == "Yes it is prime no..." ){
                ans.push_back(i);
            }
                if(i != n/i){
                   if(CheckIfNoIsPrimeOrNot_OP(n/i) == "Yes it is prime no..." ){
                    ans.push_back(n/i);
                } 
            }
        }
    }
    return ans;
}
int main(){
    
    int n;
    cout<<"enter the value of n :"<<endl;
    cin>>n;

    vector<int> ans = printingAllPrimeFactors_BT1(n);
    for (auto itt : ans) cout<<itt<<" ";
    
    return 0;
}
