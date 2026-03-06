#include<bits/stdc++.h>
using namespace std;
bool checkIfIthBitIsSetOrNotByLeftShift(int N,int i){
    // '1' getting left shift by 'i' times...
    if((N&(1<<i)) != 0){ // means the 'ith' bit is set...
        return true;
    }
    else return false;
}
int main(){

    int N = 5, i = 1;
    cout << checkIfIthBitIsSetOrNotByLeftShift(N, i);

    return 0;
}
