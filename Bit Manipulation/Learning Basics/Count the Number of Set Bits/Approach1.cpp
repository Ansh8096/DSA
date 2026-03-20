#include<bits/stdc++.h>
using namespace std;
int countTheNoOfSetBits_1(int n){
    int count = 0;
    while (n != 1)
    {
        // if the remainder is 1, then only increment the count...
        
        // if(n%2 != 0) count++;

        // faster version...
        // if(n&1 != 0) count++; // it is a wqy to check for odd ...
        count += n&1; // or...
        n = n>>1;
    }
    count += n; // for the last bit...
    return count;
}
int main(){
    int N = 5;
    cout<<countTheNoOfSetBits_1(N);
    return 0;
}
