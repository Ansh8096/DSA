#include<bits/stdc++.h>
using namespace std;
bool Jump1_OP(vector<int>& a) {
    int maxIdx = 0;
    for (int i = 0; i < a.size(); i++){
        if(i>maxIdx) return false;
        maxIdx = max(maxIdx,i+a[i]);
    }
    return true;
}
int main(){

    vector<int> a = {2, 3, 1, 1, 4};
    
    cout<<Jump1_OP(a);

    return 0;
}
