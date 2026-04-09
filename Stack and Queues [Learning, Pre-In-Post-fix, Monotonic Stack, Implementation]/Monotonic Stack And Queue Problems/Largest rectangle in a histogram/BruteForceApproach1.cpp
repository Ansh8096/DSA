#include<bits/stdc++.h>
using namespace std;
int maximumAreaOfRectangleInHistogram_BR1(vector<int> &a,int n){
    // My BR...  T.C-O(n^2)
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int cntWidth = 1;
        for (int j = i+1; j < n; j++)
        {
            if(a[j]>=a[i]) cntWidth++;
            else break;
        }

        for (int k = i-1; k >= 0; k--)
        {
            if(a[k]>=a[i]) cntWidth++;
            else break;
        }
        
        res = max(res,a[i]*cntWidth);
    }
    return res;
}
int main(){

    int n;
    cout<<"Enter the value of n: "<<endl;
    cin >> n;

    vector<int> a(n);
    cout<<"Enter the values of the array: "<<endl;
    for(int i = 0; i<n ;i++) cin>>a[i];
    cout<<maximumAreaOfRectangleInHistogram_BR1(a,n);

    return 0;
}
