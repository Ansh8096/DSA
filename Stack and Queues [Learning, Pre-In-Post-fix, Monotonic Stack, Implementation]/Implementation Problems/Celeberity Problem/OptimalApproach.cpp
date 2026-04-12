#include<bits/stdc++.h>
using namespace std;
int celebrityProblem_OP(vector<vector<int>>& matrix){
    int top = 0 , down = matrix.size()-1;
    while (top <down)
    {
        if(matrix[top][down] == 1){
            top++;
        }
        else if(matrix[down][top] == 1){
            down--;
        }
        else{
            top++; down--;
        }
    }

    if(top>down) return -1;
    // else (top==down)...
    // Verifying our celebrity...
    for(int i=0;i<matrix.size();i++){
        if(i == top) continue; // skipping the diagnol...
        if(matrix[top][i] == 0 && matrix[i][top] == 1){
        }
        else return -1; // it is not a celebrity...
    }
    return top; // celebrity verified...
}
int main(){

    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0}
    };

    cout<<celebrityProblem_OP(M); 

    return 0;
}
