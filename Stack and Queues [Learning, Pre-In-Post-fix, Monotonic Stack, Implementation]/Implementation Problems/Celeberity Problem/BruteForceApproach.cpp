#include<bits/stdc++.h>
using namespace std;
int celebrityProblem_BR(vector<vector<int>>& matrix){
    int n = matrix.size();
    vector<int> iKnow(n);
    vector<int> knowMe(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 1) {
                knowMe[j]++;
                iKnow[i]++;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if(knowMe[i] == n-1 && iKnow[i] == 0) {
            return i;
        }
    }
    
    return -1;
}
int main(){
    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0}
    };
    cout<<celebrityProblem_BR(M); 

    return 0;
}
