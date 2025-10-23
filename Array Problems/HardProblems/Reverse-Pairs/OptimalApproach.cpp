#include <bits/stdc++.h>
using namespace std;
void merge2(int arr[], int low, int mid, int high)
{
  int left = low, right = mid + 1;
  vector<int> temp;
  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
    {
      temp.push_back(arr[left]);
      left++;
    }
    // if(arr[right] > arr[left])
    else
    {
      temp.push_back(arr[right]);
      right++;
    }
  }
  while (left <= mid)
  {
    temp.push_back(arr[left]);
    left++;
  }

  while (right <= high)
  {
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
}
int count_pairs(int a[], int low, int mid, int high)
{
  int cnt = 0, right = mid + 1;
  for (int i = low; i <= mid; i++)
  {
    while (right <= high && a[i] > 2 * a[right]) right++;
    cnt += right - (mid + 1);
  }
  return cnt;
}
int mergesort2(int a1[], int low, int high)
{
  int cnt = 0;
  if (low >= high) return 0;
  int mid = (low + high) / 2;
  cnt += mergesort2(a1, low, mid);        // left half
  cnt += mergesort2(a1, mid + 1, high);   // right half
  cnt += count_pairs(a1, low, mid, high); // Modification
  merge2(a1, low, mid, high);             // merging sorted halves
  return cnt;
}
int reverse_pairs_OP(int a[], int n)
{
  return mergesort2(a, 0, n - 1);
}
int main(){
  int n1;
  cout<<"Enter the size of the array: "<<endl;
  cin>>n1;
  int a1[n1];
  cout<<"Enter the value of the array: "<<endl;
  for (int i = 0; i < n1; i++) cin>>a1[i];  
  
  cout<<reverse_pairs_OP(a1,n1);

  return 0;
}
