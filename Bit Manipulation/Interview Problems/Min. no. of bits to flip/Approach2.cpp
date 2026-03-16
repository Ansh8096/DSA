#include<bits/stdc++.h>
using namespace std;
int minimumNumberOfBitsToFlip_2(int start,int goal){
    int num = start ^ goal;
    int cnt = 0;
    while (num >= 1)
    {
        // 'num & 1' checks for odd no.
        cnt += (num & 1); // counting the set bits only.
        num = num >> 1; // trimming the num.
    }
    return cnt;
}
int main(){
    cout<<minimumNumberOfBitsToFlip_2(4,5);
    return 0;
}
