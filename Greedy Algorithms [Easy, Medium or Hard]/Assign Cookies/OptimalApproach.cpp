#include<bits/stdc++.h>
using namespace std;
int assignCookiesToChildren_OP(vector<int>& g, vector<int>& a){
    // t.c:O(nlogn + mlogm + n)...
    // s.c:O(1)...
    int n = g.size(), m = a.size(), l = 0, r = 0;
    sort(g.begin(),g.end()); sort(a.begin(),a.end());
    while (l<n && r <m){
        if(a[l] >= g[r]){
            l++;r++;
        }
        else l++;
    }
    return r;
} 
int main(){

    vector<int> g = {1,2,3};
    vector<int> a = {1,1};

    cout<<assignCookiesToChildren_OP(g,a);

    return 0;
}
