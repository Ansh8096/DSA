#include<bits/stdc++.h>
using namespace std;
void swappingTwoNumbers_OP(int &a,int &b){
// Function to swap two numbers using XOR bit manipulation:---

    // Step 1: XOR a and b, store in a
    a = a ^ b;
    // Step 2: XOR new a with b, result is original a → store in b
    b = a ^ b;
    // Step 3: XOR new a with new b, result is original b → store in a
    a = a ^ b;
}
int main(){

    int a = 5, b = 6;
    swappingTwoNumbers_OP(a,b);
    cout<<a<<" "<<b<<" "<<endl;

    return 0;
}
