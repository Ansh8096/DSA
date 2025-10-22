#include <bits/stdc++.h>
using namespace std;
pair<int, int> missing_and_repeating_OP(int a1[], int n){
  // Find Sn and S2n:-
  long long Sn = (n * (n + 1)) / 2;
  // S2-S2n = X^2-Y^2:-
  long long S2n = (n * (n + 1) * ((2 * n) + 1)) / 6;
  long long s = 0, s2 = 0;

  // Calculate S and S2:-
  for (int i = 0; i < n; i++)
  {
    s += (long long)a1[i];
    s2 += (long long)a1[i] * (long long)a1[i];
  }
  // S-Sn = X-Y:
  long long val1 = s - Sn; // X-Y

  // S2-S2n = X^2-Y^2:
  long long val2 = s2 - S2n;

  // Find X+Y = (X^2-Y^2)/(X-Y):
  val2 = val2 / val1; // X+Y

  // Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
  //  Here, X-Y = val1 and X+Y = val2:
  long long x = (val1 + val2) / 2;
  long long y = x - val1;
  return {(int)x, (int)y};
}
int main(){
  int n1;
  cout<<"Enter the size of the array: "<<endl;
  cin>>n1;
  int a1[n1];
  cout<<"Enter the value of the array: "<<endl;
  for (int i = 0; i < n1; i++) cin>>a1[i];  
  
  pair<int,int> ans = missing_and_repeating_OP(a1,n1);
  cout<<ans.first<<","<<ans.second;

  return 0;
}
