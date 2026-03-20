#include<bits/stdc++.h>
using namespace std;
int countTheNoOfSetBits_2(int n){
    int count = 0;
    while (n != 0)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}
int main(){
    int N = 4;
    cout<<countTheNoOfSetBits_2(N);
    return 0;
}
