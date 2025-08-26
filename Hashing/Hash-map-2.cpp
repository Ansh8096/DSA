#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"enter the string ";
    cin>>s;

    map<char,int> mpc;
    for (int i = 0; i < s.length(); i++)
    {
       mpc[s[i]]++;
    }
    
    cout<<"enter how many time you want to run query "<<endl;
    int q;
    cin>>q;
    while (q--)
    {
        char ch;
        cin>>ch;
        cout<<ch<<" is repeated "<< mpc[ch]<<" times in the string"<<endl;
    }
    
    // for printing the map
    cout<<"\nthis is how map looks like "<<endl;
    for (auto itt:mpc)
    {
        cout<<itt.first<<"->"<<itt.second<<endl;
    }

    return 0;
}
