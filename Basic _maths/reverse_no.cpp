#include<bits/stdc++.h>
using namespace std;
int explain_reverse_number(int n){
    int Revn=0;
    while (n!=0) // if we use '(n>0)' it will not work for the negative numbers..
    {
        int lastdigit=n%10;
        if((Revn>INT_MAX/10)||(Revn<INT_MIN/10)) // this to be used so that the integer should be in the 32bit size..
        {
            return 0;
        } 
        n=n/10;
        Revn=(Revn*10)+lastdigit;
    } 
    cout<<Revn;  
}
int main(){
    int a;
    cout<<"enter the value: "<<endl;
    cin>>a;
    explain_reverse_number(a);
    return 0;
}
