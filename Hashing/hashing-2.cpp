#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"enter the string ";
    cin>>s;
    
    // precompute:--->
    // int hash[26]={0}; // if there are only lowercaseor uppercase present in the string...
    int hash1[256]={0}; // if there are Upper_Caes also present int the string...
    // int hash[1000000]={0}; //(array range inside main is upto 10^6)
    
    for (int i = 0; i < s.size(); i++)
    {
        // hash[s[i] - 'a']++;  // (s[i] - 'a') gets typecasted in integer for index of hash ... 
        hash1[s[i]]++;
    }
    
    cout<<"enter how many time you want to run query "<<endl;
    int q;
    cin>>q;
    cout<<"check for the appearance of characters you want in your string..."<<endl;
    while (q--) // if we set q=5 loop will run for 5 times... 
    {
    char ch;
    cin>>ch;
    // fetching
    // cout<<ch<<" is repeated "<< hash[ch -'a']<<" times in the string"<<endl;
    cout<<ch<<" is repeated "<< hash1[ch]<<" times in the string"<<endl;
    }
    return 0;
}
