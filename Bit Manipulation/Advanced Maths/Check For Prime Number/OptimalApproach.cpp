#include<bits/stdc++.h>
using namespace std;
string CheckIfNoIsPrimeOrNot_OP(int n){
    int cnt = 0;
    for (int i = 1; i*i <= n; i++)
    {
        if(n%i == 0){
            cnt++;
            if(i != n/i) {
                cnt++;
            }
        }
        if(cnt > 2) break; 
    }
    if(cnt == 2) return "Yes it is prime no...";
    else return "No it is not Prime no...";
}
int main(){
    
    cout<<CheckIfNoIsPrimeOrNot_OP(25);

    return 0;
}
