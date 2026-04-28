#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insertIntervals_OP(vector<vector<int>>& a, vector<int>& newInterval) {
    vector<vector<int>> res;
    int i = 0, n = a.size();
    while (i<n && a[i][1] < newInterval[0])
    {
        res.push_back(a[i]);
        i++;
    }

    while (i<n && a[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0],a[i][0]); // comparing 'newInterval[0]' will very helpful while merging overlaping intervals...
        newInterval[1] = max(newInterval[1],a[i][1]); // comparing 'newInterval[1]' will very helpful while merging overlaping intervals...
        i++;
    }
    res.push_back(newInterval);

    while (i<n)
    {
        res.push_back(a[i]);
        i++;
    }
    
    return res;
}
int main(){

    vector<vector<int>> a = {{1,3}, {6,9}};
    vector<int> newInterval = {2,5};

    vector<vector<int>> result = insertIntervals_OP(a, newInterval);

    cout << "Result: ";
    for(auto &it : result) {
        cout << "[" << it[0] << "," << it[1] << "] ";
    }
    cout << endl;

    return 0;
}
