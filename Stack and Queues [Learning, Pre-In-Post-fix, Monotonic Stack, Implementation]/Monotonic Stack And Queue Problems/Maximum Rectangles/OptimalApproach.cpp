#include<bits/stdc++.h>
using namespace std;
int maxAreaOfRectInHistogram(vector<int> &a,int n){
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
int maximalRectangle_OP(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    // prefixSum to find a[i],for its use in finding area of histogram... 
    vector<vector<int>> prefixSum(n,vector<int>(m));
    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if(matrix[i][j] == '1') sum ++;
            else  sum = 0;
            prefixSum[i][j] = sum;
        }
    }
    
    // Getting the max. possible area...
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        res = max(res,maxAreaOfRectInHistogram(prefixSum[i],m));
    }
    return res;
}
int main(){

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'}, 
        {'1', '0', '1', '1', '1'}, 
        {'1', '1', '1', '1', '1'}, 
        {'1', '0', '0', '1', '0'}
    };
    cout<<maximalRectangle_OP(matrix);
    
    return 0;
}
