#include <bits/stdc++.h>
using namespace std;
double mdn_of_two_sortd_arr_BR(vector<int> &a1, int n1, vector<int> &a2, int n2){
  int i = 0, j = 0;
  vector<int> a3;
  while (i < n1 && j < n2)
  {
    if (a1[i] < a2[j]) a3.push_back(a1[i++]);
    else a3.push_back(a2[j++]);
  }
  
  while (i < n1) a3.push_back(a1[i++]);
  while (j < n2) a3.push_back(a2[j++]);

  int n = a3.size();
  if (n % 2 == 1) return (a3[n / 2]);
  else{
    double first = (double)(a3[n / 2]);
    double second = (double)(a3[(n / 2) - 1]);
    return (double)((first + second) / 2);
  }
}
int main(){

  int n;
  cout<<"Enter the value n: "<<endl;
  cin>>n;

  vector<int> a(n);
  cout<<"Enter the values of the array:"<<endl;
  for(int i=0;i<n;i++) cin>>a[i];

  int n1;
  cout<<"Enter the value n: "<<endl;
  cin>>n1;

  vector<int> a1(n1);
  cout<<"Enter the values of the array:"<<endl;
  for(int i=0;i<n1;i++) cin>>a1[i];
    
  cout<<mdn_of_two_sortd_arr_BR(a,n,a1,n1);
  return 0;
}
