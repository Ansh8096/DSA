#include<bits/stdc++.h>
using namespace std;
bool checkIfIthBitIsSetOrNotByRightShift(int N,int i){
    // 'N' getting right shift by 'i' times...
    if(((N>>i) & 1) != 0){ // means the 'ith' bit is set...
        return true;
    }
    else return false;
}
int main(){
    int N = 5, i = 1;
    cout << checkIfIthBitIsSetOrNotByRightShift(N, i);
    return 0;
}
