#include<bits/stdc++.h>
using namespace std;
vector<int> AsteroidCollision_OP(vector<int>& a,int n){
    vector<int> stk;
    for (int i = 0; i < n; i++)
    {
        // when there is positive a[i] just add it to stk...
        if(a[i] > 0) stk.push_back(a[i]);
        else{
            // poping elements from stk because collision happening... 
            while(!stk.empty() && stk.back() < abs(a[i]) && stk.back() > 0){
                stk.pop_back();
            } 

            // when both the the asteroids will get destroyed...
            if (!stk.empty() && stk.back() == abs(a[i])) stk.pop_back();
            // When there is -ve a[i], it will be get into stk in these cases...
            else if (stk.empty() or stk.back() < 0) stk.push_back(a[i]);
        }
    }
    return stk;
}
int main(){

    int n;
    cout<<"Enter the value of n: "<<endl;
    cin >> n;

    vector<int> a(n);
    cout<<"Enter the values of the array: "<<endl;
    for(int i = 0; i<n ;i++) cin>>a[i];
    vector<int> ans =  AsteroidCollision_OP(a,n);
    
    cout << "The state of asteroids after collisions is: ";
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }  

    return 0;
}
