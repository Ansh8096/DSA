#include<bits/stdc++.h>
using namespace std;
static bool comparing(const vector<int>&a1,const vector<int>&a2){
    return a1[1]<a2[1];
}
int eraseOverlapIntervals_OP(vector<vector<int>>& intervals){
    sort(intervals.begin(),intervals.end(),comparing);
    int cnt = 1, n = intervals.size(), last = intervals[0][1];
    for (int i=1;i<n;i++){
        if(intervals[i][0] >= last){
            cnt++;
            last = intervals[i][1]; 
        }
    }
    return n-cnt;
}
int main(){

    vector<vector<int>> a = {{1,2}, {2,3}, {3,4}, {1,3}};
    cout<<"Result: "<<eraseOverlapIntervals_OP(a);

    return 0;
}
