#include<bits/stdc++.h>
using namespace std;
int removeTheLastSetBit(int N){
    return (N & (N-1));
}
int main(){
    int N = 5;
    cout<<removeTheLastSetBit(N);
    return 0;
}
