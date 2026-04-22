#include<bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int>& a) {
    int five = 0, ten = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 5) five++; 
        else if (a[i] == 10) {
            if (five > 0) {
                five--;
                ten++;
            } else return false;
        }
        else if (a[i] == 20) {
            if (five>0 && ten>0) {
                five--;
                ten--;
            } else if (five >= 3) {
                five -= 3;
            } else return false;
        }
    }
    return true;
}
int main(){

    vector<int> a = {5,5,5,10,20};
    cout<<lemonadeChange(a);

    return 0;
}
