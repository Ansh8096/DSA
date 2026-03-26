#include<bits/stdc++.h>
using namespace std;
vector<int> getPrimeFactors(int n){
    vector<int> ans;
    for (int i = 2; i*i <= n; i++)
    {
        if(n % i == 0){
            while (n%i == 0){
                ans.push_back(i);
                n = n/i;
            }
        }
    }
    if(n != 1) ans.push_back(n);
    return ans;
}
vector<vector<int>> PrimeFactorizationsForQueries_BR(vector<int> &Queries){
    vector<vector<int>> ans;
    for (int i = 0; i < Queries.size() ; i++){
        vector<int> subAns = getPrimeFactors(Queries[i]); 
        ans.push_back(subAns);
    }
    return ans;
}
int main(){
    vector<int> a = {10,20,30,40};
    vector<vector<int>> ans = PrimeFactorizationsForQueries_BR(a);
    // for printing:--
    for(auto itt:ans){
        for(auto itr : itt){
            cout<<itr<<" ";
        }
        cout<<endl;
    }
    return 0;
}
