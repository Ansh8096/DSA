#include<bits/stdc++.h>
using namespace std;
string reversingStr(string s){
    int start = 0 , end = s.length()-1;
    while (start <= end)
    {
        swap(s[start],s[end]);
        start++,end--;
    }
    return s;
}
string convertDecimal2Binary(int n){
    string res = "";
    while (n != 1)
    {
        if(n%2 == 1) res += "1"; // adding remainder...
        else res += "0"; // adding remainder...
        n = n/2;
    }
    res += "1"; // this is for the last remainder, which we get by n/2...
    return reversingStr(res);
}
int main(){
    int n;
    cout<<"enter the value of n :"<<endl;
    cin>>n;

    cout<<convertDecimal2Binary(n); 
    
    return 0;
}
