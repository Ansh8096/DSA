#include<bits/stdc++.h>
using namespace std;
bool checkingForPowerOfTwo(int n){
    if (n <= 0) return false; // edge case...
    if ((n & (n - 1)) == 0)return true;
    else return false;
}
int main(){
    int N = 4;
    cout<<checkingForPowerOfTwo(N);
    return 0;
}
