#include<bits/stdc++.h>
using namespace std;
int minSteps(vector<int>& a, int start, int end) {
    
    if(start == end) return 0;
    vector<int> dist(1000, INT_MAX);
    queue<pair<int, int>> q;
    dist[start] = 0;
    q.push({0,start});
    
    while(!q.empty()){
        int steps = q.front().first;
        int d = q.front().second;
        q.pop();
        
        for(int i=0;i<a.size();i++){
            int newVal = (d*a[i]) % 1000;
            if(steps + 1 < dist[newVal] ){
                if(newVal == end) return steps+1;
                dist[newVal] = steps + 1;
                q.push({dist[newVal], newVal});
            }
        }
    }
    
    return -1;
    
}
int main() {

    vector<int> a = {2, 5, 7};

    int start = 3;
    int end = 30;

    int ans = minSteps(a, start, end);

    cout << "Minimum steps: " << ans << endl;

    return 0;
}
