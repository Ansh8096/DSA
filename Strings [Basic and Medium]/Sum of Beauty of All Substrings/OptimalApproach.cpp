#include <bits/stdc++.h>
using namespace std;
int get_max(vector<int> &a)
{
  // to get max. occurence element ...
  int maxii = INT_MIN;
  for (int i = 0; i < 26; i++)
  {
    if (a[i] > maxii)
    {
      maxii = a[i];
    }
  }
  return maxii;
}
int get_min(vector<int> &a)
{
  // to get min. occurence element ...
  int minn = INT_MAX;
  for (int i = 0; i < 26; i++)
  {
    if (a[i] > 0)
    { // we did this to avoid least occurence = 0....
      minn = min(minn, a[i]);
    }
  }
  return minn;
}
int beauty_Sum(string s)
{
  int total = 0;
  // two for loop's for generating every substring ....
  for (int i = 0; i < s.length(); i++)
  {
    vector<int> freq_ARR(26, 0); // to store the frequency of every char in string....
    for (int j = i; j < s.length(); j++)
    {
      freq_ARR[(s[j] - 'a')]++;                         // (s[i] - 'a)--> will give us the int value of char..
      int diff = get_max(freq_ARR) - get_min(freq_ARR); // for finding the difference...
      total += diff;                                    // adding the total difference...
    }
  }
  return total;
}
int main(){
  cout<<beauty_Sum("aabcbaa");
  return 0;                                                                                          
}
