#include <bits/stdc++.h>
using namespace std;
int count_inversions_BR(int a1[], int n){
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (a1[i] > a1[j]) cnt++;
    }
  }
  return cnt;
}
int main(){
  int n1;
  cout<<"Enter the size of the array: "<<endl;
  cin>>n1;
  int a1[n1];
  cout<<"Enter the value of the array: "<<endl;
  for (int i = 0; i < n1; i++) cin>>a1[i];  
  
  cout<<count_inversions_BR(a1,n1);

  return 0;
}
