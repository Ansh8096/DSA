#include<bits/stdc++.h>
using namespace std;
void getGCD_HCF(int a, int b){
// 1st Method.... 
int gcd = 1;
for(int i=1;i<=min(a,b);i++)
{
    if(a%i ==0 && b%i ==0 )
    {
        gcd=i;
    }
}
    cout<<"GCD of ("<<a<<","<<b<<") "<<"is "<<gcd<<endl;
}
int main(){
    int a,b;
    cout<<"enter values: "<<endl;
    cin>>a>>b;
    getGCD_HCF(a,b);
    return 0;
}
