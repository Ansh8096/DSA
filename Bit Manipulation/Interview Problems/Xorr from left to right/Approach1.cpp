#include<bits/stdc++.h>
using namespace std;
int xorUptoN_OP(int n){
    if(n % 4 == 1) return 1;
    else if (n % 4 == 2) return n+1;
    else if (n % 4 == 3) return 0;
    else return n;
}
int xorFromLeftToRight(int L,int R){
    return (xorUptoN_OP(L-1)) ^ (xorUptoN_OP(R));
}
int main(){
    
    cout<<xorFromLeftToRight(5,7);
    return 0;
}
