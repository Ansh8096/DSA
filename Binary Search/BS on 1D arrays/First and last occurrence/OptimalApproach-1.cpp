#include <bits/stdc++.h>
using namespace std;
int lowerBound_BS(vector<int> &a,int n,int x){
  int low=0,high=n-1,ans=n;
  while (low<=high)
  {
    int mid = (low+high)/2;
    if(a[mid]>=x) {  // CASE_1: may be an answer....
        ans = mid;
        // look for small index on left ...
        high = mid-1;
    }
    // look for right...
    else low = mid+1; // CASE_2: can't be an answer....
  }
  return ans;   
}
int upperBound_BS(vector<int> &a,int n,int x){
  int low=0,high=n-1,ans=n;
  while (low<=high)
  {
    int mid = (low+high)/2;
    if(a[mid]>x) {  // CASE_1: may be an answer....
      ans = mid;
      // look for small index on left ...
      high = mid-1;
    }
    // look for right...
    else low = mid+1; // CASE_2: can't be an answer....
  }
  return ans;   
}
int floor_1(vector<int> &a,int n,int x){
  int low=0,high=n-1,ans=-1;
  while (low<=high){
    int mid = (low+high)/2;
    if(a[mid] <= x){
        ans=a[mid];
        low=mid+1;
    }
    else high=mid-1;
  }
  return ans;
}
int ceil_1(vector<int> &a,int n,int x){
  int low=0,high=n-1,ans=-1;
  while (low<=high)
  {
    int mid = (low+high)/2;
    if(a[mid]>=x) {  // CASE_1: may be an answer....
        ans = a[mid];
        // look for small index on left ...
        high = mid-1;
    }
    // look for right...
    else low = mid+1; // CASE_2: can't be an answer....
  }
  return ans;   
}
void floor_and_ceil_BS(vector<int> &a,int n,int x){
  cout<<"floor is : "<<floor_1(a,n,x)<<endl;
  cout<<"ceil is : "<<ceil_1(a,n,x);   
}
pair<int,int> first_last_occurence_OP(vector<int> &a,int n,int x){
  int lb = lowerBound_BS(a,n,x);
  if(lb == n || a[lb] != x) return {-1,-1};
  return {lb,upperBound_BS(a,n,x)-1};
}
int main(){
  int n1;
  cout<<"Enter the size of the array: "<<endl;
  cin>>n1;
  
  vector<int>a(n1);
  cout<<"Enter the value of the array: "<<endl;
  for (int i = 0; i < n1; i++) cin>>a[i]; 
  
  int x;
  cout<<"Enter the value of x: "<<endl;
  cin>>x;
  
  pair<int,int> ans = first_last_occurence_OP(a,n1,x);
  cout<< ans.first << ","<<ans.second<<endl;
  return 0;
}
