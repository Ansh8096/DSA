#include<bits/stdc++.h>
using namespace std;
int maximumAreaOfRectangleInHistogram_OP(vector<int> &a,int n){
    int maxArea = INT_MIN;
    stack<int> stk;
    // finding the pse and in the one go only...
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && a[i]<a[stk.top()])
        {
            int element = a[stk.top()]; stk.pop();
            int nse = i;
            int pse = (stk.empty())?-1:stk.top(); 
            maxArea = max(maxArea,element *(nse-pse-1));
        }
        stk.push(i);
    }

    // again traversing only to find the area of rectangle of a[i] that are left, if our stack is not empty... 
    while (!stk.empty())
    {
        int element = a[stk.top()]; stk.pop();
        int nse = n;
        int pse = (stk.empty())?-1:stk.top(); 
        maxArea = max(maxArea,element *(nse-pse-1));
    }

    return maxArea;
}
int main(){

    int n;
    cout<<"Enter the value of n: "<<endl;
    cin >> n;

    vector<int> a(n);
    cout<<"Enter the values of the array: "<<endl;
    for(int i = 0; i<n ;i++) cin>>a[i];
    cout<<maximumAreaOfRectangleInHistogram_OP(a,n);

    return 0;
}
