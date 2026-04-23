#include<bits/stdc++.h>
using namespace std;
class Job{
    public:
    int st;
    int end;
    int pos;
};
static bool comp(Job a, Job b){
    return a.end<b.end;
}
int nMeetingsInOneRoom(vector<int>start,vector<int>end){
    int n = start.size();
    Job a[n];
    for(int i=0;i<end.size();i++){
        a[i].st = start[i];
        a[i].end = end[i];
        a[i].pos = i+1;
    }

    sort(a+0,a+n,comp);

    vector<int>res;
    int cnt = 1, freeTime = a[0].end;
    res.push_back(a[0].pos);
    for(int i=1;i<n;i++){
        if(a[i].st > freeTime){
            freeTime = a[i].end;
            res.push_back(a[i].pos);
            cnt++;
        }
    }
    return cnt++;
    
}
int maxMeetings(vector<int>& start, vector<int>& end) {
    return nMeetingsInOneRoom(start,end);        
}
int main(){

    vector<int> st = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout<<maxMeetings(st, end);
    
    return 0;
}
