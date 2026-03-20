#include<bits/stdc++.h>
using namespace std;
int divideTwoIntegers_BR(int divident,int divisor){
    int sum = 0 , cnt = 0;
    while (sum + divisor <= divident)
    {
        sum += divisor;
        cnt++; 
    }
    return cnt;
}
int main(){
    cout<<divideTwoIntegers_BR(22,4);
    return 0;
}
