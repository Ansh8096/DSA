#include <bits/stdc++.h>
using namespace std;
string sort_char_by_freq_BT(string s){
  unordered_map<char,int> mpp;
  // map every char into map...
  for(char el:s) mpp[el]++;   
  
  vector<pair<char,int>> freqArr;
  // then put mapped chars into vector for sorting...
  // for(auto [ch,fr]: mpp) {freqArr.push_back({ch,fr});}
  for(auto ch_fr: mpp) {freqArr.push_back({ch_fr.first,ch_fr.second});}
  
  // Lambda function for custom comparator
  auto cmp = [&](pair<char,int> a , pair<char,int> b){
      return a.second>b.second;
  };
  // sorting begin to end the freqArr using cmp function...
  sort(freqArr.begin(),freqArr.end(),cmp);
  // create the ans string...
  string ans = "";

  // for(auto [ch,fr] :freqArr) ans.append(fr,ch); // it will add the char to ans (freq times)
  for(auto ch_fr :freqArr) ans.append(ch_fr.second,ch_fr.first); // it will add the char to ans (freq times)
  return ans; 
}
int main(){
  cout<<sort_char_by_freq_BT("anagram");
  return 0;                                                                                          
}
