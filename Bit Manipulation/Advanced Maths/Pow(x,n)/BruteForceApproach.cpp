#include<bits/stdc++.h>
using namespace std;
double powerExponentiation_OP(double x , int n){
    int sign = 0; // for +ve...
    if(n < 0) {
        sign = 1; // for -ve...
        n = -1*n;
    }

    double ans = 1; 
    while (n!=0)
    {
        // n is even:
        if((n&1) == 0){
            x = x*x;
            n = n>>1;
        }
        // n is odd:
        else{
            ans *= x;
            n = n-1;
        }
    }
    
    if(sign == 1) return (1.0 / ans);
    else return ans;

}
int main(){

    cout<<powerExponentiation_OP(2.0000,2);

    return 0;
}
