#include <bits/stdc++.h>
using namespace std;
void swapIfGreater(int a1[], int a2[], int idx1, int idx2)
{
  if (a1[idx1] > a2[idx2])
  {
    swap(a1[idx1], a2[idx2]);
  }
}
void mrg_sortd_arr_OP2(int a1[], int n, int a2[], int m){
  // len of the imaginary single array:--
  int len = n + m;
  // Initial gap:
  int gap = (len / 2) + (len % 2);
  while (gap > 0)
  {
    // Place 2 pointers:
    int left = 0, right = left + gap;
    while (right < len)
    {
      // case 1: left in a1[]
      // and right in a2[]:
      if (left < n && right >= n)
      {
        swapIfGreater(a1, a2, left, right - n);
      }
      // case 2: both pointers in a2[]:
      else if (left >= n)
      {
        swapIfGreater(a2, a2, left - n, right - n);
      }
      // case 3: both pointers in a1[]:
      else
      {
        swapIfGreater(a1, a1, left, right);
      }
      left++, right++;
    }
    // break if iteration gap=1 is completed:
    if (gap == 1) break;
    // Otherwise, calculate new gap:
    gap = (gap / 2) + (gap % 2);
  }

  // for printing.......
  cout << "the first array is : " << endl;
  for (int i = 0; i < n; i++)
    cout << a1[i] << " ";
  cout << endl;
  cout << "the second array is : " << endl;
  for (int i = 0; i < m; i++)
    cout << a2[i] << " ";
}
int main(){
  int n1;
  cout<<"Enter the size of the array: "<<endl;
  cin>>n1;

  int a1[n1];
  cout<<"Enter the value of the array: "<<endl;
  for (int i = 0; i < n1; i++) cin>>a1[i];  

  int n2;
  cout<<"Enter the size of the 2nd array: "<<endl;
  cin>>n2;

  int a2[n2];
  cout<<"Enter the value of the array: "<<endl;
  for (int i = 0; i < n2; i++) cin>>a2[i];

  mrg_sortd_arr_OP2(a1,n1,a2,n2);
  return 0;
}
