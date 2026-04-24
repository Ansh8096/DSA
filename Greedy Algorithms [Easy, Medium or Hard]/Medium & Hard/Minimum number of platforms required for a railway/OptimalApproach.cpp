#include<bits/stdc++.h>
using namespace std;
int miniNumberOfPlatforms_OP(vector<int>&a,vector<int>&d){
    sort(a.begin(),a.end());
    sort(d.begin(),d.end());
    int maxCnt = 0, cnt = 0, i = 0, j = 0;
    while (i<a.size())
    {
        if(a[i] < d[j]){
            i++;cnt++;
            maxCnt = max(maxCnt,cnt);
        }
        else{
            j++;cnt--;
        }
    }
    return maxCnt;
}
int main(){

    vector<int> a = {900, 1235, 1100};
    vector<int> d = {1000, 1240, 1200};
    cout<<miniNumberOfPlatforms_OP(a, d);

    return 0;
}
