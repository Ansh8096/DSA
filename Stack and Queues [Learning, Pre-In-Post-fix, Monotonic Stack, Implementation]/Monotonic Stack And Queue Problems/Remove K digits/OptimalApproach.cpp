#include<bits/stdc++.h>
using namespace std;
string reverseTheString(string str){
    int st = 0 , end = str.length()-1;
    while(st<end){
        swap(str[st],str[end]);
        st++; end--;
    }
    return str;
}
string removeKdigitsFromStringToGEtMinimumNumber(string str,int k){
    // edge case...
    if(k==str.length()) return "0"; 
    stack<char> stk;
    // placing smaller ones at start...
    // Removing all the k larger ones...
    for (int i = 0; i < str.length(); i++)
    {
        while (!stk.empty() && k>0 && (stk.top() - '0') > (str[i] - '0')){
            stk.pop();
            k--;
        }
        stk.push(str[i]); 
    }

    // Edge case: (when k is not equal to zero , means there was all small elements at start)...
    while(!stk.empty() && k>0){
        stk.pop(); 
        k--;
    }

    // check...
    if(stk.empty()) return "0";

    // storing our answer...
    string res = "";
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }

    // removing if our res will have '0' at the start...
    while (!res.empty() && res.back() == '0') res.pop_back();
    res = reverseTheString(res); // reversing to get the correct answer...

    // check...
    if(res.empty()) return "0"; 
    return res;
}
int main(){

    int n;
    cout<<"Enter the value of n: "<<endl;
    cin >> n;

    vector<int> a(n);
    cout<<"Enter the values of the array: "<<endl;
    for(int i = 0; i<n ;i++) cin>>a[i];
    cout<<removeKdigitsFromStringToGEtMinimumNumber("1432219",3);

    return 0;
}
