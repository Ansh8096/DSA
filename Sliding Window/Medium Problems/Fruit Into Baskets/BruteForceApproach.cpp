#include<bits/stdc++.h>
using namespace std;
int fruitIntoBaskets_BR(vector<int> &a){
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++){
        set<int> st;
        int len = 0;
        for (int j = i; j < a.size(); j++){
           st.insert(a[j]);
           if(st.size()>2) break;
           len++;
        }
        maxLen = max(maxLen,len);
    }
    return maxLen;
}
int main(){
        
    int n1;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n1;

    vector<int>a(n1);
    cout<<"Enter the value of the array: "<<endl;
    for (int i = 0; i < n1; i++) cin>>a[i]; 
    
    cout<<fruitIntoBaskets_BR(a);

    return 0;
}
