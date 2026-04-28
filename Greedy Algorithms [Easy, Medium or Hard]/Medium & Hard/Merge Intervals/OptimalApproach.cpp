#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeIntervals_OP(vector<vector<int>>&arr) {
    int n= arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else {
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;  
}
int main(){

    vector<vector<int>> a = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result = mergeIntervals_OP(a);

    cout << "Result: ";
    for(auto &it : result) {
        cout << "[" << it[0] << "," << it[1] << "] ";
    }
    cout << endl;

    return 0;
}
