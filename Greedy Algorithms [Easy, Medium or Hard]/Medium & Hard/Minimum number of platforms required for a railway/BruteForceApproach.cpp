#include<bits/stdc++.h>
using namespace std;
int miniNumberOfPlatforms_BR(vector<int>&a,vector<int>&d){
    int maxCnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int cnt = 1;
        // start j from i+1 (not from 0), becauz we want to count each intersection point one time only...
        for (int j = i+1; j < a.size(); j++)
        {
            if((a[i] >= a[j] and d[j] >= a[i])  
            or (a[j] >= a[i] and a[j] <= d[i])){
                cnt++;
            }
        }
        maxCnt = max(maxCnt,cnt);
    }
    return maxCnt;
}
int main(){

    vector<int> a = {900, 1235, 1100};
    vector<int> d = {1000, 1240, 1200};
    cout<<miniNumberOfPlatforms_BR(a, d);

    return 0;
}
