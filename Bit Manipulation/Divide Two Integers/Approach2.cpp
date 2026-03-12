#include<bits/stdc++.h>
using namespace std;
int divideTwoIntegers_OP(int divident,int divisor){
    // Edge Case:----
    if (divident == divisor) return 1;
    bool sign = true; // for: +ve 

    if(divident >= 0 && divisor < 0) sign = false; // for: -ve... 
    if(divident < 0 && divisor > 0) sign = false; // for: -ve... 
  
    long n = abs(divident) , d = abs(divisor); // Taking positive value of 'divident' and 'divisor'...
    int ans = 0; 

    while (n >= d)
    {
        int cnt = 0; // initial power of 2...
        while (n >= (d<<cnt+1)){  //  '(d<<cnt+1)' == d * (2^(cnt+1))...
            cnt++;
        }

        ans += 1<<cnt; // storing the current (2^cnt)...
        n = n - (d*(1<<cnt)); // updating the divident value...
    }
    
    // edge case when ans exceeds the 'INT_MAX' value... 
    if(ans >= INT_MAX && sign == true) return INT_MAX;
    if(ans >= INT_MAX && sign == false) return INT_MIN;

    return (sign) ? ans : (-1 * ans);
}
int main(){
    cout<<divideTwoIntegers_OP(22,4);
    return 0;
}
