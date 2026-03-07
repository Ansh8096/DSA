#include<bits/stdc++.h>
using namespace std;
int toggleTheIthBit(int N ,int i){
    return (N^(1<<i));
}
int main(){
    int N = 5, i = 0;
    cout<<toggleTheIthBit(N,i);
    return 0;
}
