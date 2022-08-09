#include <bits/stdc++.h>

using namespace std;

int f(int i, int buy, int k, vector<int> &p, vector<vector<vector<int>>> &dp)
{
    if (k == 0)
        return 0;
    if (i >= p.size())
        return 0;
    if (dp[i][buy][k] != -1)
        return dp[i][buy][k];
    if (buy)
        return dp[i][buy][k] = max(-p[i] + f(i + 1, 0, k, p, dp), f(i + 1, 1, k, p, dp));
    else
        return dp[i][buy][k] = max(p[i] + f(i + 1, 1, k - 1, p, dp), f(i + 1, 0, k, p, dp));
}
int maxProfit(int k, vector<int> &p)
{
    int n = p.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return f(0, 1, k, p, dp);
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int k = 2, n = prices.size();
    cout << "The maximum profit that can be generated is " << maxProfit(k, prices);
}