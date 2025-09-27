#include <bits/stdc++.h>
using namespace std;
int stock_buy_AND_sell(int arr[], int n){
  int mini = arr[0];
  int profit = 0;
  for(int i = 1; i < n; i++){ // start iteration from 2nd element....
    int cost = arr[i] - mini;   // it is the currebt profit.....
    profit = max(profit, cost); // it maximizes the profit
    mini = min(mini, arr[i]);   // it makes sure it get minimum.....
  }
  return profit;
}
int main(){
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;

  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin>>arr[i];

  cout<<stock_buy_AND_sell(arr,n);
}
