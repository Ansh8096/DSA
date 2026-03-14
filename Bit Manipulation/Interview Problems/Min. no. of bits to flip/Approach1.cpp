#include<bits/stdc++.h>
using namespace std;
int minimumNumberOfBitsToFlip_1(int start,int goal){
    int num = start ^ goal; // Variable to store bits that are different in both numbers...
    int cnt = 0; 
    for (int i = 0; i < 32; i++)
    {
        cnt += num & 1; // checking for set bit in num...
        num = num >> 1; // trimming our 'num' number... 
    }
    return cnt;
}
int main(){
    cout<<minimumNumberOfBitsToFlip_1(4,5);
    return 0;
}
