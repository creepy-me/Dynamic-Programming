#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int p = 0, mini = prices[0];
    int n = prices.size();
    for (int i = 1; i < n; i++)
    {
        p = max(p, prices[i] - mini);
        mini = min(mini, prices[i]);
    }
    return p;
}

int main() {

  vector<int> Arr  ={7,1,5,3,6,4};

  cout<<"The maximum profit by selling the stock is "<<maxProfit(Arr);
}