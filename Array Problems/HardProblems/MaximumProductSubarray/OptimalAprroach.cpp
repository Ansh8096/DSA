#include <bits/stdc++.h>
using namespace std;
int max_subarr_product_OP(vector<int> &a, int n){
  int pre = 1, suf = 1;
  int ans = INT_MIN;
  for (int i = 0; i < n; i++){
    if (pre == 0) pre = 1;
    if (suf == 0) suf = 1;

    pre = pre * a[i];
    suf = suf * a[n - i - 1];
    ans = max(ans, max(pre, suf));
  }
  return ans;
}
int main(){
  int n1;
  cout<<"Enter the size of the array: "<<endl;
  cin>>n1;
  vector<int>a(n1);
  cout<<"Enter the value of the array: "<<endl;
  for (int i = 0; i < n1; i++) cin>>a[i];  
  
  cout<<max_subarr_product_OP(a,n1);

  return 0;
}
