#include<bits/stdc++.h>
using namespace std;
int candy_OP(vector<int>& ratings) {
    int sum = 1, i = 1, n = ratings.size();
    while (i < n)
    {
        if (ratings[i - 1] == ratings[i])
        {
            sum++;
            i++;
            continue;
        }

        int peak = 1;
        while (i < n && ratings[i] > ratings[i - 1])
        {
            peak++;
            sum += peak;
            i++;
        }

        int down = 1;
        while (i < n && ratings[i - 1] > ratings[i])
        {
            sum += down;
            down++;
            i++;
        }

        // No (down+1), because down will get incremented
        // By at last in its while loop
        if (down > peak)
        {
            sum += (down)-peak;
        }
    }
    return sum;
}
int main(){

    vector<int> a = {1,0,2};
    cout<<candy_OP(a);
    
    return 0;
}
