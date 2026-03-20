#include<bits/stdc++.h>
using namespace std;
int setsTheIthBitTo1(int N,int i){
    int ans = (N|(1<<i));
    return ans;
}
int main(){
    int N = 5, i = 1;
    cout << setsTheIthBitTo1(N,i);
    return 0;
}
