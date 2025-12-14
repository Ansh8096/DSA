#include <bits/stdc++.h>
using namespace std;
int Roman_to_integer_OP(string s){
  // mapping the exact values given in question....
  unordered_map<char,int> mpp;
  mpp['I'] = 1;
  mpp['V'] = 5;
  mpp['X'] = 10;
  mpp['L'] = 50;
  mpp['C'] = 100;
  mpp['D'] = 500;
  mpp['M'] = 1000;
  
  int ans = 0;
  // traversing  from 0 -> n-2 (becauz of i++)...
  for(int i = 0;i<s.length()-1;i++)
  {
    if(mpp[s[i]] >= mpp[s[i+1]]){
      ans += mpp[s[i]];
    }
    if(mpp[s[i]] < mpp[s[i+1]]){
      ans -= mpp[s[i]];
    }  
  }
  // adding the last element char value beacuzse it will always be added ...
  ans += mpp[s[s.length()-1]];
  return ans;
}
int main(){
  cout<<Roman_to_integer_OP("XLII");
  return 0;                                                                                          
}
