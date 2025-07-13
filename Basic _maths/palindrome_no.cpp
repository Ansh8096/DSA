#include<bits/stdc++.h>
using namespace std;
void explain_palindrome_no(int n){
    int revno=0;
    int dup=n; // we have create the duplicate of n here becauz, n will change inside the while loop..
    while (n>0)
    {
    int lastdigit=n%10;
    revno=(revno*10)+lastdigit;
    n=n/10; // this operation changes the value of n...
    }
    cout<<revno<<endl;

    if (revno==dup)// we have used duplicate of n i.e dup becauz, n changes... 
    {
        cout<<"true";
    }
    else cout<<"false";

}
int main(){
    int a;
    cout<<"enter the value: "<<endl;
    cin>>a;
    explain_palindrome_no(a);
    return 0;
}
