#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> PrimeFactorizationsForQueries_OP(vector<int> &Queries){
    vector<int> spf(100000+1);
    for(int i=0;i<=100000;i++) spf[i] = i;

    for (int i = 2; i*i <= 100000; i++){
        if(spf[i] == i){
            for(int j = i*i; j <= 100000; j += i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
    
    // Getting Prime factors for every query using 'spf' table:
    int n = 0; 
    vector<vector<int>> ans;
    for (int i = 0; i < Queries.size(); i++){
        n = Queries[i];
        vector<int> tempAns;
        while (n != 1){
          tempAns.push_back(spf[n]);
          n = n/spf[n];  
        }
        ans.push_back(tempAns);
    }
    
    return ans;
}
int main(){
    vector<int> a = {10,20,30,40};
    vector<vector<int>> ans = PrimeFactorizationsForQueries_OP(a);
    // for printing:--
    for(auto itt:ans){
        for(auto itr : itt){
            cout<<itr<<" ";
        }
        cout<<endl;
    }
    return 0;
}
