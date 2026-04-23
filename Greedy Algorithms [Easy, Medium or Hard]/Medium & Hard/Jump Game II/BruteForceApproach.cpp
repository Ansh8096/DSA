#include<bits/stdc++.h>
using namespace std;
int calculateJumps(vector<int>&a,int idx,int jumps){
    if(idx >= a.size()-1) return jumps; 
    int mini = INT_MAX;
    for (int i = 1; i <= a[idx]; i++)
    {
        mini = min(mini,calculateJumps(a,idx+i,jumps+1));
    }
    return mini;
}
int Jump2_BR(vector<int>& a) {
    return calculateJumps(a,0,0);
}
int main(){

    vector<int> a = {2, 3, 1, 1, 4};
    
    cout<<Jump2_BR(a);

    return 0;
}
