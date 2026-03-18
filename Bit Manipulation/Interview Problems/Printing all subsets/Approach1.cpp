#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> printingAllSubsets(vector<int>& arr){
    int n = arr.size();
    vector<vector<int>> ans;
    for (int i = 0; i < (1 << n); i++) // '1<<n' == 2^n ...
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            // checking which bit is non-zero...
            if((i & (1 << j)) != 0) {
                temp.push_back(arr[j]); // then adding the element from arr corresponding to that non-zero bit....
            }
        }
        ans.push_back(temp); // storing list into list...
    }
    return ans;
}
int main(){
    
    int n;
    cout<<"enter the value of n :"<<endl;
    cin>>n;

    vector<int> a(n);
    cout<<"Enter the values in the array : "<<endl;
    for (int i = 0; i < n; i++) cin>>a[i];

    vector<vector<int>> ans = printingAllSubsets(a);
    // For printing:--->
    for (auto  itt : ans)
    {
        for(auto itr : itt){
            cout<< itr << " ";
        }
        cout<<endl;
    }

    return 0;
}
