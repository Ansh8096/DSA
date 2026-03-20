#include<bits/stdc++.h>
using namespace std;
int convertBinary2Decimal(string s){
    int len = s.length();
    int powerOf2 = 1; // This will keep the track of power 2...
    int ans = 0;
    for (int i = len-1; i >= 0; i--)
    {
        // if 's[i] == 1',then only it will be adding value to our answer... 
        if(s[i] == '1') {
           ans += powerOf2; // we are simply adding it to 'ans', we don't need to multiply 's[i]' (beacuse s[i] == 1)... 
        }
        powerOf2 *= 2;
    }
    return ans;
}
int main(){
    string str;
    cout << "enter the value of str: " << endl;
    cin >> str;

    cout << convertBinary2Decimal(str);

    return 0;
}
