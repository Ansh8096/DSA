#include <bits/stdc++.h>
using namespace std;
int single_el_in_sortd_arr_BR(vector<int> &a, int n){
  int el = 0;
  if (n == 1) return a[0]; // when the array has only one element....

  for (int i = 1; i < n - 1; i++)
  {
    if (a[i - 1] != a[i] && a[i] != a[i + 1])
    {
      el = a[i];
    }
  }
  return el;
}
int main(){
  int n1;
  cout<<"Enter the size of the array: "<<endl;
  cin>>n1;

  vector<int>a(n1);
  cout<<"Enter the value of the array: "<<endl;
  for (int i = 0; i < n1; i++) cin>>a[i]; 

  cout<<single_el_in_sortd_arr_BR(a,n1);
  return 0;
}
