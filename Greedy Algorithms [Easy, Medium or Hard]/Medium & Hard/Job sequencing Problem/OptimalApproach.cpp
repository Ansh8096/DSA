#include<bits/stdc++.h>
using namespace std;
class Job1{
    public:
    int id;
    int deadline;
    int profit;
};
bool compare(const Job1& val1, const Job1& val2){
    return val1.profit > val2.profit;
}
pair<int,int> jobSequencingPb_OP(Job1 a[],int n){
    sort(a,a+n,compare);
    int maxProfit = 0, maxDeadline = a[0].deadline, cnt = 0;

    for (int i = 0;i < n; i++)
    {
        maxDeadline = max(maxDeadline,a[i].deadline);
    }

    vector<int>hashArr(maxDeadline+1,-1);

    for (int i = 0; i < n; i++)
    {
        int j = a[i].deadline;
        while(j>0){
            if(hashArr[j] == -1){
                hashArr[j] = i;
                maxProfit += a[i].profit;
                cnt++;
                break;
            }
            j--;
        }
    }
    return {cnt, maxProfit};
}
int main(){

    int n = 4;
    // Define jobs with id, deadline, and profit
    Job1 arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};
    pair < int, int > ans = jobSequencingPb_OP(arr, n);
    cout << ans.first << " " << ans.second << endl;
    
    return 0;
}
