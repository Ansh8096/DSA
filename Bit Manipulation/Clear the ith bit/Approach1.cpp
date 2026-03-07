#include<bits/stdc++.h>
using namespace std;
int clearTheIthBit(int N,int i){
   return (N&(~(1<<i)));
}
int main(){
    int N = 5, i = 0;
    cout<<clearTheIthBit(N,i);
    return 0;
}
