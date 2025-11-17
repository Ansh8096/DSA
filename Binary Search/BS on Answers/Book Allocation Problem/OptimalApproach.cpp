#include <bits/stdc++.h>
using namespace std;
int max_el_for_koko(vector<int> &a, int n){
  int maxii = INT_MIN;

  // find the maximum:
  for (int i = 0; i < n; i++)
  {
    maxii = max(maxii, a[i]);
  }
  return maxii;
}
long long sum_of_arr(vector<int> &a, int n){
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += a[i];
  }
  return sum;
}
int allocation(vector<int> &a, int n, int pages)
{
  int students = 1, std_page = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] + std_page <= pages)
    {
      std_page += a[i];
    }
    else
    {
      students++;
      std_page = a[i];
    }
  }
  return students;
}
int book_allocate_OP(vector<int> &a, int n, int students)
{
  if (students > n) return -1;
  int low = max_el_for_koko(a, n);
  int high = sum_of_arr(a, n);
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (allocation(a, n, mid) <= students)
    {
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

  int std;
  cout<<"Enter the students: "<<endl;
  cin>>std;

  cout<<book_allocate_OP(a,n,std);
  return 0;
}
