#include<bits/stdc++.h>
using namespace std;
void problem1(int i,int n) 
{   // print name N times using recursion....
    if(i>n)
    {
      return;
    }
    cout<<"Shailu"<<endl;
    problem1(i+1,n);
}
int main(){
    int n;
    cout<<"enter the value "<<endl;
    cin>>n;
    
    problem1(0,n);
    return 0;
}
