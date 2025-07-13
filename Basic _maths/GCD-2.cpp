#include<bits/stdc++.h>
using namespace std;
void getGCD_HCF(int a, int b){
// 2nd method....
for(int i=min(a,b); i >=1 ;i--)
{
   if(a%i == 0 && b%i == 0)
   {
    cout<<"GCD of ("<<a<<","<<b<<") "<<"is "<<i<<endl;
    break;
   }
}
}
int main()
{
    int a,b;
    cout<<"enter values: "<<endl;
    cin>>a>>b;
    getGCD_HCF(a,b);
    return 0;
}
