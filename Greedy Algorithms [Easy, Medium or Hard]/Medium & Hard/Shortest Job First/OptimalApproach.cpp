#include<bits/stdc++.h>
using namespace std;
int shortestJobFirst_OP(vector<int>&burstTime,int n){
    sort(burstTime.begin(),burstTime.end());
    int time = 0, waitingTime = 0;
    for (int i = 0; i < n; i++)
    {
        if(i == 0) {
            time += burstTime[i];
            continue;
        }
        waitingTime += time;
        time += burstTime[i];
    }

    return (waitingTime/n);
}
int main(){

    vector<int> a = {4,3,7,1,2};
    cout<<shortestJobFirst_OP(a,a.size());
    
    return 0;
}
