#include<bits/stdc++.h>
using namespace std;
void problem2(int i,int n){ 
    // print from 1 to N  using recursion...
    if(i>n)
    {
      return;
    }
    cout<<i<<endl;
    problem2(i+1,n);
}
int main(){
    int n;
    cout<<"enter the value"<<endl;
    cin>>n;
    problem2(0,n);
    return 0;
}
