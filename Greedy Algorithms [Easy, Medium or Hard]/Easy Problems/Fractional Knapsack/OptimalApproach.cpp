#include<bits/stdc++.h>
using namespace std;
class Item{
    public:
    int value;
    int weight;
};
// Comparator function to sort items by value/weight ratio...
bool static comp(Item a,Item b){
    double r1 = (double)a.value/(double)a.weight;
    double r2 = (double)b.value/(double)b.weight;
    return r1 >= r2; // Return true if the ratio of item a is greater than item b...
}
double fractionalKnapsack(Item a[],int n,int w){
    sort(a+0,a+n,comp); // Sort items based on the value/weight ratio...

    int currWeight = 0;
    double finalWeight = 0.0;
    
    for (int i = 0; i < n; i++){
        if(currWeight + a[i].weight <= w){
            currWeight += a[i].weight;
            finalWeight += (double)a[i].value;
        }
        else{
            int leftWeight = w - currWeight;
            double valuePerWeight = (double)a[i].value/a[i].weight;
            finalWeight += valuePerWeight*(double)leftWeight; 
            break;
        }
    }
    return finalWeight;
} 
int main(){

    int n = 4, weight = 90;  // Number of items and capacity of knapsack
    // Item values and weights
    Item arr[n] = { {100,20},{60,10},{100,50},{200,50}};
    cout<<fractionalKnapsack(arr,n,weight);

    return 0;
}
