#include <bits/stdc++.h>
using namespace std;
string sort_char_by_freq_BR(string s){
  vector<int> freq(128,0);
  for(char ch:s) freq[ch]++;
  // Lambda function for custom comparator
  auto cmp = [&](char a,char b){
  if(freq[a] == freq[b]) return a<b;
  return freq[a]>freq[b]; //If the frequencies are not equal, the character with the higher frequency should come first.
  }; 
  // sorting begin to en using cmp function...
  sort(s.begin(),s.end(),cmp); // cmp: This is the name of the comparator function.
  return s;
}
int main(){
  cout<<sort_char_by_freq_BR("anagram");
  return 0;                                                                                          
}
