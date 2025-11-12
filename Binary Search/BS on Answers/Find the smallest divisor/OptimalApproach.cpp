#include <bits/stdc++.h>
using namespace std;
int max_el_for_koko(vector<int> &a, int n){
  int maxii = INT_MIN;
  // find the maximum:
  for (int i = 0; i < n; i++){
    maxii = max(maxii, a[i]);
  }
  return maxii;
}
bool poss_sum(vector<int> &a, int n, int d, int thres)
{
  int sum = 0;
  for (int i = 0; i < n; i++){
    sum += ceil((double)a[i] / (double)d);
  }
  if (sum <= thres) return true;
  else return false;
}
int smallest_div_withGiven_thres_OP(vector<int> &a,int n,int thres){
  int low = 1;
  int high = max_el_for_koko(a, n);
  if (n > thres) return -1; // edge case:-
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (poss_sum(a, n, mid, thres) == 1){
      high = mid - 1;
    }
    else low = mid + 1;
  }
  return low;
}
int main(){

  int n;
  cout<<"Enter the value n: "<<endl;
  cin>>n;

  vector<int> a(n);
  cout<<"Enter the values of the array:"<<endl;
  for(int i=0;i<n;i++) cin>>a[i];

  int thres;
  cout << "Enter the threshold value : " << endl;
  cin >> thres;

  cout << smallest_div_withGiven_thres_OP(a, n, thres);

  return 0;
}
